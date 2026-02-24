# Lesson 03: Dependency Injection & IoC Container

## 🎯 Learning Objectives

- Understand .NET's built-in DI container
- Master service lifetimes (Transient, Scoped, Singleton)
- Register and resolve dependencies
- Compare with Spring's IoC container
- Use configuration binding with DI

## 📚 Key Concepts

### DI in .NET vs Spring

| Spring | .NET |
|--------|------|
| @Autowired | Constructor injection (preferred) |
| @Component | services.AddTransient<T>() |
| @Service | services.AddScoped<T>() |
| @Singleton | services.AddSingleton<T>() |
| ApplicationContext | IServiceProvider |

## 🔑 Service Lifetimes

### 1. Transient
**New instance every time it's requested**

```csharp
services.AddTransient<IMyService, MyService>();
```

**Spring equivalent**: `@Scope("prototype")`

**Use when**: Lightweight, stateless services

### 2. Scoped
**One instance per request/scope**

```csharp
services.AddScoped<IMyService, MyService>();
```

**Spring equivalent**: `@Scope("request")` (web) or default scope

**Use when**: Per-request services (DbContext, repositories)

### 3. Singleton
**One instance for the application lifetime**

```csharp
services.AddSingleton<IMyService, MyService>();
```

**Spring equivalent**: `@Singleton` or default

**Use when**: Stateless services, caches, configuration

## 💻 Basic Usage

### Registration (Program.cs)

```csharp
var builder = WebApplication.CreateBuilder(args);

// Register services
builder.Services.AddTransient<IEmailService, EmailService>();
builder.Services.AddScoped<IOrderRepository, OrderRepository>();
builder.Services.AddSingleton<ICacheService, CacheService>();

var app = builder.Build();
```

### Consumption (Constructor Injection)

```csharp
public class OrderController : ControllerBase
{
    private readonly IOrderRepository _repository;
    private readonly IEmailService _emailService;

    // Dependencies injected via constructor
    public OrderController(
        IOrderRepository repository,
        IEmailService emailService)
    {
        _repository = repository;
        _emailService = emailService;
    }

    [HttpPost]
    public async Task<IActionResult> CreateOrder(Order order)
    {
        await _repository.AddAsync(order);
        await _emailService.SendConfirmationAsync(order);
        return Ok();
    }
}
```

## 🏃 Running the Example

```bash
cd 03-DependencyInjection
dotnet run
```

## 📝 Code Files

- **Program.cs** - DI configuration and examples
- **Services/** - Service implementations
- **Controllers/** - Consuming services

## 💡 Best Practices

1. **Prefer constructor injection** over property injection
2. **Use interfaces** for abstraction
3. **Choose appropriate lifetime**: Scoped for DbContext, Singleton for caches
4. **Avoid service locator pattern**: Don't inject IServiceProvider
5. **Register in correct order**: Dependencies before dependents

## 🔗 Configuration Binding

Bind configuration to strongly-typed objects:

```csharp
// appsettings.json
{
  "EmailSettings": {
    "SmtpServer": "smtp.example.com",
    "Port": 587
  }
}

// Startup
builder.Services.Configure<EmailSettings>(
    builder.Configuration.GetSection("EmailSettings"));

// Usage
public class EmailService
{
    private readonly EmailSettings _settings;

    public EmailService(IOptions<EmailSettings> options)
    {
        _settings = options.Value;
    }
}
```

## ⏭️ Next Lesson

Move to **Lesson 04: Web API Basics** to build REST APIs with ASP.NET Core.
