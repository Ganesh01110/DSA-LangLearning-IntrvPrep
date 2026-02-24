# Lesson 04: ASP.NET Core Web API Basics

## 🎯 Learning Objectives

- Build REST APIs with ASP.NET Core
- Understand controller-based vs minimal APIs
- Implement routing and model binding
- Handle validation and error responses
- Compare with Spring Boot REST

## 📚 Key Concepts

### ASP.NET Core Web API vs Spring Boot

| Spring Boot | ASP.NET Core |
|-------------|--------------|
| @RestController | [ApiController] + ControllerBase |
| @GetMapping | [HttpGet] |
| @PostMapping | [HttpPost] |
| @PathVariable | [FromRoute] |
| @RequestBody | [FromBody] |
| @RequestParam | [FromQuery] |
| ResponseEntity<T> | ActionResult<T> |

## 🔑 Controller Basics

### Simple Controller

```csharp
[ApiController]
[Route("api/[controller]")]
public class ProductsController : ControllerBase
{
    [HttpGet]
    public ActionResult<IEnumerable<Product>> GetAll()
    {
        return Ok(products);
    }

    [HttpGet("{id}")]
    public ActionResult<Product> GetById(int id)
    {
        var product = products.FirstOrDefault(p => p.Id == id);
        if (product == null)
            return NotFound();
        
        return Ok(product);
    }

    [HttpPost]
    public ActionResult<Product> Create([FromBody] Product product)
    {
        products.Add(product);
        return CreatedAtAction(nameof(GetById), new { id = product.Id }, product);
    }

    [HttpPut("{id}")]
    public IActionResult Update(int id, [FromBody] Product product)
    {
        // Update logic
        return NoContent();
    }

    [HttpDelete("{id}")]
    public IActionResult Delete(int id)
    {
        // Delete logic
        return NoContent();
    }
}
```

## 💻 Model Validation

```csharp
using System.ComponentModel.DataAnnotations;

public class Product
{
    public int Id { get; set; }

    [Required]
    [StringLength(100)]
    public string Name { get; set; } = string.Empty;

    [Range(0, 10000)]
    public decimal Price { get; set; }
}
```

## 🏃 Running the Example

```bash
cd 04-WebApiBasics
dotnet run

# API will be available at:
# https://localhost:5001/api/products
# http://localhost:5000/api/products
```

## 📖 Additional Resources

- [ASP.NET Core Web API](https://docs.microsoft.com/aspnet/core/web-api/)
- [Routing](https://docs.microsoft.com/aspnet/core/mvc/controllers/routing)

## ⏭️ Next Lesson

Move to **Lesson 05: Entity Framework Core** to learn database access with MariaDB.
