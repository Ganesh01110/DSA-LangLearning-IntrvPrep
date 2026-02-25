using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

var builder = WebApplication.CreateBuilder(args);

// Configure MariaDB connection (from XAMPP)
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection")
    ?? "Server=localhost;Port=3306;Database=dotnet_learning;User=root;Password=;";

builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseMySql(connectionString, ServerVersion.AutoDetect(connectionString)));

builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

// Register repositories
builder.Services.AddScoped<IProductRepository, ProductRepository>();

var app = builder.Build();

// Auto-migrate database on startup (development only!)
using (var scope = app.Services.CreateScope())
{
    var db = scope.ServiceProvider.GetRequiredService<AppDbContext>();
    await db.Database.MigrateAsync();
    
    // Seed data if empty
    if (!await db.Products.AnyAsync())
    {
        await SeedDataAsync(db);
    }
}

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();
app.UseAuthorization();
app.MapControllers();

app.Run();

static async Task SeedDataAsync(AppDbContext db)
{
    var categories = new[]
    {
        new Category { Name = "Electronics", Description = "Electronic devices" },
        new Category { Name = "Books", Description = "Books and publications" },
        new Category { Name = "Clothing", Description = "Apparel and accessories" }
    };

    db.Categories.AddRange(categories);
    await db.SaveChangesAsync();

    var products = new[]
    {
        new Product { Name = "Laptop", Price = 999.99m, CategoryId = categories[0].Id },
        new Product { Name = "Mouse", Price = 29.99m, CategoryId = categories[0].Id },
        new Product { Name = "C# Book", Price = 49.99m, CategoryId = categories[1].Id }
    };

    db.Products.AddRange(products);
    await db.SaveChangesAsync();

    Console.WriteLine("✅ Database seeded successfully!");
}

// ===== ENTITIES =====

public class Product
{
    [Key]
    public int Id { get; set; }

    [Required]
    [StringLength(100)]
    public string Name { get; set; } = string.Empty;

    [Column(TypeName = "decimal(18,2)")]
    public decimal Price { get; set; }

    public string? Description { get; set; }

    [Required]
    public int CategoryId { get; set; }

    // Navigation property
    public Category Category { get; set; } = null!;

    public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
}

public class Category
{
    [Key]
    public int Id { get; set; }

    [Required]
    [StringLength(50)]
    public string Name { get; set; } = string.Empty;

    public string? Description { get; set; }

    // Navigation property
    public ICollection<Product> Products { get; set; } = new List<Product>();
}

// ===== DBCONTEXT =====

public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
    {
    }

    public DbSet<Product> Products { get; set; }
    public DbSet<Category> Categories { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        // Configure Product-Category relationship
        modelBuilder.Entity<Product>()
            .HasOne(p => p.Category)
            .WithMany(c => c.Products)
            .HasForeignKey(p => p.CategoryId)
            .OnDelete(DeleteBehavior.Restrict);

        // Configure indexes
        modelBuilder.Entity<Product>()
            .HasIndex(p => p.Name);

        modelBuilder.Entity<Category>()
            .HasIndex(c => c.Name)
            .IsUnique();
    }
}

// ===== REPOSITORY PATTERN =====

public interface IProductRepository
{
    Task<IEnumerable<Product>> GetAllAsync();
    Task<Product?> GetByIdAsync(int id);
    Task<Product> CreateAsync(Product product);
    Task UpdateAsync(Product product);
    Task DeleteAsync(int id);
}

public class ProductRepository : IProductRepository
{
    private readonly AppDbContext _context;

    public ProductRepository(AppDbContext context)
    {
        _context = context;
    }

    public async Task<IEnumerable<Product>> GetAllAsync()
    {
        return await _context.Products
            .Include(p => p.Category)  // Eager loading (like JOIN FETCH)
            .ToListAsync();
    }

    public async Task<Product?> GetByIdAsync(int id)
    {
        return await _context.Products
            .Include(p => p.Category)
            .FirstOrDefaultAsync(p => p.Id == id);
    }

    public async Task<Product> CreateAsync(Product product)
    {
        _context.Products.Add(product);
        await _context.SaveChangesAsync();
        return product;
    }

    public async Task UpdateAsync(Product product)
    {
        _context.Products.Update(product);
        await _context.SaveChangesAsync();
    }

    public async Task DeleteAsync(int id)
    {
        var product = await _context.Products.FindAsync(id);
        if (product != null)
        {
            _context.Products.Remove(product);
            await _context.SaveChangesAsync();
        }
    }
}

// ===== CONTROLLER =====

[Microsoft.AspNetCore.Mvc.ApiController]
[Microsoft.AspNetCore.Mvc.Route("api/[controller]")]
public class ProductsController : Microsoft.AspNetCore.Mvc.ControllerBase
{
    private readonly IProductRepository _repository;

    public ProductsController(IProductRepository repository)
    {
        _repository = repository;
    }

    [Microsoft.AspNetCore.Mvc.HttpGet]
    public async Task<Microsoft.AspNetCore.Mvc.ActionResult<IEnumerable<Product>>> GetAll()
    {
        var products = await _repository.GetAllAsync();
        return Ok(products);
    }

    [Microsoft.AspNetCore.Mvc.HttpGet("{id}")]
    public async Task<Microsoft.AspNetCore.Mvc.ActionResult<Product>> GetById(int id)
    {
        var product = await _repository.GetByIdAsync(id);
        if (product == null)
            return NotFound();

        return Ok(product);
    }

    [Microsoft.AspNetCore.Mvc.HttpPost]
    public async Task<Microsoft.AspNetCore.Mvc.ActionResult<Product>> Create(Product product)
    {
        var created = await _repository.CreateAsync(product);
        return CreatedAtAction(nameof(GetById), new { id = created.Id }, created);
    }

    [Microsoft.AspNetCore.Mvc.HttpPut("{id}")]
    public async Task<Microsoft.AspNetCore.Mvc.IActionResult> Update(int id, Product product)
    {
        if (id != product.Id)
            return BadRequest();

        await _repository.UpdateAsync(product);
        return NoContent();
    }

    [Microsoft.AspNetCore.Mvc.HttpDelete("{id}")]
    public async Task<Microsoft.AspNetCore.Mvc.IActionResult> Delete(int id)
    {
        await _repository.DeleteAsync(id);
        return NoContent();
    }
}
