# Lesson 09: Design Patterns in .NET

## 🎯 Learning Objectives

- Implement Repository pattern
- Use Unit of Work pattern
- Apply Factory pattern with DI
- Understand Strategy pattern
- Learn CQRS basics
- Compare with Java/Spring patterns

## 📚 Common Patterns

### 1. Repository Pattern

Abstracts data access logic. **Spring equivalent**: `@Repository` + JPA Repository

```csharp
public interface IRepository<T> where T : class
{
    Task<T?> GetByIdAsync(int id);
    Task<IEnumerable<T>> GetAllAsync();
    Task AddAsync(T entity);
    Task UpdateAsync(T entity);
    Task DeleteAsync(int id);
}

public class Repository<T> : IRepository<T> where T : class
{
    private readonly DbContext _context;
    private readonly DbSet<T> _dbSet;

    public Repository(DbContext context)
    {
        _context = context;
        _dbSet = context.Set<T>();
    }

    public async Task<T?> GetByIdAsync(int id)
    {
        return await _dbSet.FindAsync(id);
    }

    // ... other methods
}
```

### 2. Unit of Work Pattern

Coordinates multiple repositories in a single transaction.

```csharp
public interface IUnitOfWork : IDisposable
{
    IRepository<Product> Products { get; }
    IRepository<Category> Categories { get; }
    Task<int> SaveChangesAsync();
}

public class UnitOfWork : IUnitOfWork
{
    private readonly AppDbContext _context;

    public IRepository<Product> Products { get; }
    public IRepository<Category> Categories { get; }

    public UnitOfWork(AppDbContext context)
    {
        _context = context;
        Products = new Repository<Product>(context);
        Categories = new Repository<Category>(context);
    }

    public async Task<int> SaveChangesAsync()
    {
        return await _context.SaveChangesAsync();
    }

    public void Dispose()
    {
        _context.Dispose();
    }
}
```

### 3. Factory Pattern with DI

Creates objects with dependencies. **Spring equivalent**: `@Bean` factory methods

```csharp
public interface INotificationFactory
{
    INotificationService Create(NotificationType type);
}

public class NotificationFactory : INotificationFactory
{
    private readonly IServiceProvider _serviceProvider;

    public NotificationFactory(IServiceProvider serviceProvider)
    {
        _serviceProvider = serviceProvider;
    }

    public INotificationService Create(NotificationType type)
    {
        return type switch
        {
            NotificationType.Email => _serviceProvider.GetRequiredService<EmailService>(),
            NotificationType.Sms => _serviceProvider.GetRequiredService<SmsService>(),
            _ => throw new ArgumentException("Invalid type")
        };
    }
}
```

### 4. Strategy Pattern

Swaps algorithms at runtime. **Spring equivalent**: Multiple `@Component` implementations

```csharp
public interface IPaymentStrategy
{
    Task ProcessPaymentAsync(decimal amount);
}

public class CreditCardPayment : IPaymentStrategy
{
    public async Task ProcessPaymentAsync(decimal amount)
    {
        // Process credit card payment
        await Task.CompletedTask;
    }
}

public class PayPalPayment : IPaymentStrategy
{
    public async Task ProcessPaymentAsync(decimal amount)
    {
        // Process PayPal payment
        await Task.CompletedTask;
    }
}

public class PaymentService
{
    private readonly IPaymentStrategy _strategy;

    public PaymentService(IPaymentStrategy strategy)
    {
        _strategy = strategy;
    }

    public async Task ProcessAsync(decimal amount)
    {
        await _strategy.ProcessPaymentAsync(amount);
    }
}
```

### 5. CQRS (Command Query Responsibility Segregation)

Separates read and write operations. **Spring equivalent**: Separate service methods

```csharp
// Command (write operation)
public class CreateProductCommand
{
    public string Name { get; set; } = string.Empty;
    public decimal Price { get; set; }
}

public interface ICommandHandler<TCommand>
{
    Task HandleAsync(TCommand command);
}

public class CreateProductCommandHandler : ICommandHandler<CreateProductCommand>
{
    private readonly AppDbContext _context;

    public CreateProductCommandHandler(AppDbContext context)
    {
        _context = context;
    }

    public async Task HandleAsync(CreateProductCommand command)
    {
        var product = new Product
        {
            Name = command.Name,
            Price = command.Price
        };

        _context.Products.Add(product);
        await _context.SaveChangesAsync();
    }
}

// Query (read operation)
public class GetProductsQuery
{
    public string? Category { get; set; }
}

public interface IQueryHandler<TQuery, TResult>
{
    Task<TResult> HandleAsync(TQuery query);
}

public class GetProductsQueryHandler : IQueryHandler<GetProductsQuery, List<Product>>
{
    private readonly AppDbContext _context;

    public GetProductsQueryHandler(AppDbContext context)
    {
        _context = context;
    }

    public async Task<List<Product>> HandleAsync(GetProductsQuery query)
    {
        var products = _context.Products.AsQueryable();

        if (!string.IsNullOrEmpty(query.Category))
        {
            products = products.Where(p => p.Category.Name == query.Category);
        }

        return await products.ToListAsync();
    }
}
```

## 🏃 Running the Example

```bash
cd 09-DesignPatterns
dotnet run

# Visit: https://localhost:5001/swagger

# Test endpoints:
# GET /api/products - Uses Repository pattern
# POST /api/products - Uses Repository + Unit of Work
# GET /api/notifications/{type} - Uses Factory pattern
# POST /api/payments - Uses Strategy pattern
```

## 📝 Code Files

- **Program.cs** - DI setup and pattern registration
- **Patterns/Repository.cs** - Generic repository implementation
- **Patterns/UnitOfWork.cs** - Unit of Work pattern
- **Patterns/NotificationFactory.cs** - Factory pattern
- **Patterns/PaymentStrategy.cs** - Strategy pattern implementations
- **Controllers/ProductsController.cs** - Repository pattern demo
- **Controllers/NotificationsController.cs** - Factory pattern demo
- **Controllers/PaymentsController.cs** - Strategy pattern demo
- **Models/Product.cs** - Domain models
- **Data/AppDbContext.cs** - EF Core context

## 💡 Best Practices

1. **Repository**: Use for data access abstraction
2. **Unit of Work**: Coordinate multiple repositories
3. **Factory**: Create objects with dependencies
4. **Strategy**: Swap algorithms at runtime
5. **CQRS**: Separate read and write operations for complex domains

## 🎓 Pattern Comparison

| Pattern | Purpose | Spring Equivalent |
|---------|---------|-------------------|
| Repository | Data access abstraction | `@Repository` + JPA |
| Unit of Work | Transaction management | `@Transactional` |
| Factory | Object creation | `@Bean` factory methods |
| Strategy | Algorithm selection | Multiple `@Component` |
| CQRS | Separate reads/writes | Service layer separation |

## ⏭️ Next Lesson

Move to **Lesson 10: Legacy .NET Framework** to understand older codebases.
