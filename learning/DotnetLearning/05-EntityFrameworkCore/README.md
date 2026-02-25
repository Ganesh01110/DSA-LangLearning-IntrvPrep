# Lesson 05: Entity Framework Core with MariaDB

## 🎯 Learning Objectives

- Understand EF Core as an ORM (vs JPA/Hibernate)
- Configure MariaDB connection from XAMPP
- Create entities and DbContext
- Use migrations for schema management
- Perform CRUD operations with LINQ
- Implement Repository pattern

## 📚 Key Concepts

### EF Core vs JPA/Hibernate

| JPA/Hibernate | EF Core |
|---------------|---------|
| EntityManager | DbContext |
| @Entity | DbSet<T> property |
| @Id | [Key] attribute |
| @Column | [Column] attribute |
| JPQL | LINQ |
| Flyway/Liquibase | EF Migrations |
| persistence.xml | DbContextOptions |

## 🔧 MariaDB Setup (XAMPP)

### 1. Start MariaDB in XAMPP
- Open XAMPP Control Panel
- Start "MySQL" (MariaDB) service
- Default port: 3306
- Default user: root
- Default password: (empty)

### 2. Create Database
```sql
CREATE DATABASE dotnet_learning CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
```

### 3. Connection String

```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Server=localhost;Port=3306;Database=dotnet_learning;User=root;Password=;"
  }
}
```

## 💻 DbContext Setup

```csharp
public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options)
        : base(options)
    {
    }

    public DbSet<Product> Products { get; set; }
    public DbSet<Category> Categories { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        // Configure relationships, constraints, etc.
        modelBuilder.Entity<Product>()
            .HasOne(p => p.Category)
            .WithMany(c => c.Products)
            .HasForeignKey(p => p.CategoryId);
    }
}
```

## 🏃 Running the Example

### Install EF Core Tools
```bash
dotnet tool install --global dotnet-ef
```

### Create and Apply Migration
```bash
cd 05-EntityFrameworkCore

# Create migration
dotnet ef migrations add InitialCreate

# Apply to database
dotnet ef database update

# Run the application
dotnet run
```

## 📝 CRUD Operations

```csharp
// Create
var product = new Product { Name = "Laptop", Price = 999.99m };
context.Products.Add(product);
await context.SaveChangesAsync();

// Read
var products = await context.Products
    .Where(p => p.Price > 100)
    .Include(p => p.Category)
    .ToListAsync();

// Update
var product = await context.Products.FindAsync(id);
product.Price = 899.99m;
await context.SaveChangesAsync();

// Delete
context.Products.Remove(product);
await context.SaveChangesAsync();
```

## 🔗 Repository Pattern

```csharp
public interface IRepository<T> where T : class
{
    Task<T?> GetByIdAsync(int id);
    Task<IEnumerable<T>> GetAllAsync();
    Task AddAsync(T entity);
    Task UpdateAsync(T entity);
    Task DeleteAsync(int id);
}
```

## ⚠️ Important Notes

- **Always use async methods** for database operations
- **Use Include()** for eager loading (like JOIN FETCH)
- **Dispose DbContext** properly (handled by DI)
- **Use migrations** for schema changes
- **Connection pooling** is automatic

## 📖 Additional Resources

- [EF Core Documentation](https://docs.microsoft.com/ef/core/)
- [EF Core vs EF6](https://docs.microsoft.com/ef/efcore-and-ef6/)

## ⏭️ Next Lesson

Move to **Lesson 06: Middleware & Pipeline** to understand request processing.
