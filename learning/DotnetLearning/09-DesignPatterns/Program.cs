using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

// Add services
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

// ===== IN-MEMORY DATABASE =====
builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseInMemoryDatabase("DesignPatternsDemo"));

// ===== REPOSITORY PATTERN =====
builder.Services.AddScoped(typeof(IRepository<>), typeof(Repository<>));

// ===== UNIT OF WORK PATTERN =====
builder.Services.AddScoped<IUnitOfWork, UnitOfWork>();

// ===== FACTORY PATTERN =====
builder.Services.AddSingleton<INotificationFactory, NotificationFactory>();
builder.Services.AddTransient<EmailService>();
builder.Services.AddTransient<SmsService>();

// ===== STRATEGY PATTERN =====
// Register all payment strategies
builder.Services.AddTransient<CreditCardPayment>();
builder.Services.AddTransient<PayPalPayment>();
builder.Services.AddTransient<BankTransferPayment>();

var app = builder.Build();

// Seed database
using (var scope = app.Services.CreateScope())
{
    var context = scope.ServiceProvider.GetRequiredService<AppDbContext>();
    SeedData(context);
}

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();
app.UseAuthorization();
app.MapControllers();

Console.WriteLine("🎨 Design Patterns Demo");
Console.WriteLine("Visit: https://localhost:5001/swagger");
Console.WriteLine("\n📚 Patterns Demonstrated:");
Console.WriteLine("  - Repository Pattern (GET/POST /api/products)");
Console.WriteLine("  - Unit of Work Pattern (POST /api/products)");
Console.WriteLine("  - Factory Pattern (GET /api/notifications/{type})");
Console.WriteLine("  - Strategy Pattern (POST /api/payments)");

app.Run();

// Seed sample data
static void SeedData(AppDbContext context)
{
    if (!context.Products.Any())
    {
        context.Products.AddRange(
            new Product { Name = "Laptop", Price = 999.99m, Category = "Electronics" },
            new Product { Name = "Mouse", Price = 29.99m, Category = "Electronics" },
            new Product { Name = "Desk", Price = 299.99m, Category = "Furniture" }
        );
        context.SaveChanges();
    }
}

// ===== MODELS =====

/// <summary>
/// Product entity
/// </summary>
public class Product
{
    public int Id { get; set; }
    public string Name { get; set; } = string.Empty;
    public decimal Price { get; set; }
    public string Category { get; set; } = string.Empty;
}

// ===== DATABASE CONTEXT =====

/// <summary>
/// Entity Framework DbContext
/// </summary>
public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

    public DbSet<Product> Products { get; set; }
}

// ===== REPOSITORY PATTERN =====

/// <summary>
/// Generic repository interface
/// Abstracts data access logic
/// Similar to Spring's JpaRepository
/// </summary>
public interface IRepository<T> where T : class
{
    Task<T?> GetByIdAsync(int id);
    Task<IEnumerable<T>> GetAllAsync();
    Task AddAsync(T entity);
    Task UpdateAsync(T entity);
    Task DeleteAsync(int id);
}

/// <summary>
/// Generic repository implementation
/// </summary>
public class Repository<T> : IRepository<T> where T : class
{
    protected readonly AppDbContext _context;
    protected readonly DbSet<T> _dbSet;

    public Repository(AppDbContext context)
    {
        _context = context;
        _dbSet = context.Set<T>();
    }

    public async Task<T?> GetByIdAsync(int id)
    {
        return await _dbSet.FindAsync(id);
    }

    public async Task<IEnumerable<T>> GetAllAsync()
    {
        return await _dbSet.ToListAsync();
    }

    public async Task AddAsync(T entity)
    {
        await _dbSet.AddAsync(entity);
        await _context.SaveChangesAsync(); // Note: In real app, use Unit of Work
    }

    public async Task UpdateAsync(T entity)
    {
        _dbSet.Update(entity);
        await _context.SaveChangesAsync();
    }

    public async Task DeleteAsync(int id)
    {
        var entity = await GetByIdAsync(id);
        if (entity != null)
        {
            _dbSet.Remove(entity);
            await _context.SaveChangesAsync();
        }
    }
}

// ===== UNIT OF WORK PATTERN =====

/// <summary>
/// Unit of Work interface
/// Coordinates multiple repositories in a single transaction
/// Similar to Spring's @Transactional
/// </summary>
public interface IUnitOfWork : IDisposable
{
    IRepository<Product> Products { get; }
    Task<int> SaveChangesAsync();
}

/// <summary>
/// Unit of Work implementation
/// </summary>
public class UnitOfWork : IUnitOfWork
{
    private readonly AppDbContext _context;
    private IRepository<Product>? _products;

    public UnitOfWork(AppDbContext context)
    {
        _context = context;
    }

    public IRepository<Product> Products
    {
        get
        {
            _products ??= new Repository<Product>(_context);
            return _products;
        }
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

// ===== FACTORY PATTERN =====

/// <summary>
/// Notification types enum
/// </summary>
public enum NotificationType
{
    Email,
    Sms
}

/// <summary>
/// Notification service interface
/// </summary>
public interface INotificationService
{
    Task SendAsync(string message);
    string GetServiceType();
}

/// <summary>
/// Email notification service
/// </summary>
public class EmailService : INotificationService
{
    public async Task SendAsync(string message)
    {
        await Task.Delay(100); // Simulate sending
        Console.WriteLine($"📧 Email sent: {message}");
    }

    public string GetServiceType() => "Email";
}

/// <summary>
/// SMS notification service
/// </summary>
public class SmsService : INotificationService
{
    public async Task SendAsync(string message)
    {
        await Task.Delay(100); // Simulate sending
        Console.WriteLine($"📱 SMS sent: {message}");
    }

    public string GetServiceType() => "SMS";
}

/// <summary>
/// Notification factory interface
/// Creates notification services based on type
/// Similar to Spring's @Bean factory methods
/// </summary>
public interface INotificationFactory
{
    INotificationService Create(NotificationType type);
}

/// <summary>
/// Notification factory implementation
/// Uses DI container to resolve services
/// </summary>
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
            _ => throw new ArgumentException($"Unknown notification type: {type}")
        };
    }
}

// ===== STRATEGY PATTERN =====

/// <summary>
/// Payment strategy interface
/// Defines algorithm for processing payments
/// Similar to Spring's multiple @Component implementations
/// </summary>
public interface IPaymentStrategy
{
    Task<PaymentResult> ProcessPaymentAsync(decimal amount);
    string GetPaymentMethod();
}

/// <summary>
/// Credit card payment strategy
/// </summary>
public class CreditCardPayment : IPaymentStrategy
{
    public async Task<PaymentResult> ProcessPaymentAsync(decimal amount)
    {
        await Task.Delay(100); // Simulate processing
        return new PaymentResult
        {
            Success = true,
            TransactionId = Guid.NewGuid().ToString(),
            Message = $"Credit card payment of ${amount} processed successfully"
        };
    }

    public string GetPaymentMethod() => "CreditCard";
}

/// <summary>
/// PayPal payment strategy
/// </summary>
public class PayPalPayment : IPaymentStrategy
{
    public async Task<PaymentResult> ProcessPaymentAsync(decimal amount)
    {
        await Task.Delay(100); // Simulate processing
        return new PaymentResult
        {
            Success = true,
            TransactionId = Guid.NewGuid().ToString(),
            Message = $"PayPal payment of ${amount} processed successfully"
        };
    }

    public string GetPaymentMethod() => "PayPal";
}

/// <summary>
/// Bank transfer payment strategy
/// </summary>
public class BankTransferPayment : IPaymentStrategy
{
    public async Task<PaymentResult> ProcessPaymentAsync(decimal amount)
    {
        await Task.Delay(100); // Simulate processing
        return new PaymentResult
        {
            Success = true,
            TransactionId = Guid.NewGuid().ToString(),
            Message = $"Bank transfer of ${amount} processed successfully"
        };
    }

    public string GetPaymentMethod() => "BankTransfer";
}

/// <summary>
/// Payment result model
/// </summary>
public class PaymentResult
{
    public bool Success { get; set; }
    public string TransactionId { get; set; } = string.Empty;
    public string Message { get; set; } = string.Empty;
}

/// <summary>
/// Payment request model
/// </summary>
public class PaymentRequest
{
    public decimal Amount { get; set; }
    public string PaymentMethod { get; set; } = string.Empty; // "CreditCard", "PayPal", "BankTransfer"
}

// ===== CONTROLLERS =====

/// <summary>
/// Products controller - demonstrates Repository and Unit of Work patterns
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class ProductsController : ControllerBase
{
    private readonly IRepository<Product> _repository;
    private readonly IUnitOfWork _unitOfWork;
    private readonly ILogger<ProductsController> _logger;

    public ProductsController(
        IRepository<Product> repository,
        IUnitOfWork unitOfWork,
        ILogger<ProductsController> logger)
    {
        _repository = repository;
        _unitOfWork = unitOfWork;
        _logger = logger;
    }

    /// <summary>
    /// GET /api/products
    /// Uses Repository pattern
    /// </summary>
    [HttpGet]
    public async Task<IActionResult> GetAll()
    {
        _logger.LogInformation("Getting all products using Repository pattern");
        var products = await _repository.GetAllAsync();
        return Ok(products);
    }

    /// <summary>
    /// GET /api/products/{id}
    /// Uses Repository pattern
    /// </summary>
    [HttpGet("{id}")]
    public async Task<IActionResult> GetById(int id)
    {
        _logger.LogInformation("Getting product {Id} using Repository pattern", id);
        var product = await _repository.GetByIdAsync(id);
        
        if (product == null)
            return NotFound();
        
        return Ok(product);
    }

    /// <summary>
    /// POST /api/products
    /// Uses Unit of Work pattern to coordinate repository operations
    /// </summary>
    [HttpPost]
    public async Task<IActionResult> Create([FromBody] Product product)
    {
        _logger.LogInformation("Creating product using Unit of Work pattern");
        
        // Use Unit of Work to coordinate multiple operations
        await _unitOfWork.Products.AddAsync(product);
        await _unitOfWork.SaveChangesAsync();
        
        return CreatedAtAction(nameof(GetById), new { id = product.Id }, product);
    }
}

/// <summary>
/// Notifications controller - demonstrates Factory pattern
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class NotificationsController : ControllerBase
{
    private readonly INotificationFactory _factory;
    private readonly ILogger<NotificationsController> _logger;

    public NotificationsController(
        INotificationFactory factory,
        ILogger<NotificationsController> logger)
    {
        _factory = factory;
        _logger = logger;
    }

    /// <summary>
    /// GET /api/notifications/{type}
    /// Uses Factory pattern to create notification service
    /// type: "email" or "sms"
    /// </summary>
    [HttpGet("{type}")]
    public async Task<IActionResult> Send(string type, [FromQuery] string message = "Test notification")
    {
        _logger.LogInformation("Sending {Type} notification using Factory pattern", type);

        // Parse notification type
        if (!Enum.TryParse<NotificationType>(type, true, out var notificationType))
        {
            return BadRequest(new { error = "Invalid notification type. Use 'email' or 'sms'" });
        }

        // Use factory to create appropriate service
        var service = _factory.Create(notificationType);
        await service.SendAsync(message);

        return Ok(new
        {
            serviceType = service.GetServiceType(),
            message = $"{service.GetServiceType()} notification sent successfully"
        });
    }
}

/// <summary>
/// Payments controller - demonstrates Strategy pattern
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class PaymentsController : ControllerBase
{
    private readonly IServiceProvider _serviceProvider;
    private readonly ILogger<PaymentsController> _logger;

    public PaymentsController(
        IServiceProvider serviceProvider,
        ILogger<PaymentsController> logger)
    {
        _serviceProvider = serviceProvider;
        _logger = logger;
    }

    /// <summary>
    /// POST /api/payments
    /// Uses Strategy pattern to select payment method
    /// Body: { "amount": 100.00, "paymentMethod": "CreditCard" }
    /// </summary>
    [HttpPost]
    public async Task<IActionResult> ProcessPayment([FromBody] PaymentRequest request)
    {
        _logger.LogInformation("Processing payment using Strategy pattern: {Method}", request.PaymentMethod);

        // Select strategy based on payment method
        IPaymentStrategy strategy = request.PaymentMethod switch
        {
            "CreditCard" => _serviceProvider.GetRequiredService<CreditCardPayment>(),
            "PayPal" => _serviceProvider.GetRequiredService<PayPalPayment>(),
            "BankTransfer" => _serviceProvider.GetRequiredService<BankTransferPayment>(),
            _ => throw new ArgumentException($"Unknown payment method: {request.PaymentMethod}")
        };

        // Execute strategy
        var result = await strategy.ProcessPaymentAsync(request.Amount);

        return Ok(new
        {
            paymentMethod = strategy.GetPaymentMethod(),
            result = result
        });
    }

    /// <summary>
    /// GET /api/payments/methods
    /// Lists available payment methods
    /// </summary>
    [HttpGet("methods")]
    public IActionResult GetPaymentMethods()
    {
        return Ok(new[]
        {
            "CreditCard",
            "PayPal",
            "BankTransfer"
        });
    }
}
