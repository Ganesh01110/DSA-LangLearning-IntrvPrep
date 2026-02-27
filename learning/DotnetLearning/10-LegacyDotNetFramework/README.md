# Lesson 10: Legacy .NET Framework Patterns

## 🎯 Learning Objectives

- Understand .NET Framework project structure
- Navigate web.config and Global.asax
- Work with ASP.NET MVC (not Core)
- Understand WCF services basics
- Know migration strategies

## 📚 Key Differences

### Project Structure

**Legacy .NET Framework:**
```
MyWebApp/
├── Global.asax              ← Application startup
├── Web.config               ← Configuration (XML)
├── packages.config          ← NuGet packages
├── Controllers/
├── Views/
├── Models/
└── App_Start/
    └── RouteConfig.cs       ← Routing configuration
```

**Modern .NET Core:**
```
MyWebApp/
├── Program.cs               ← Application startup
├── appsettings.json         ← Configuration (JSON)
├── MyWebApp.csproj          ← Project + packages
├── Controllers/
├── Views/
└── Models/
```

## 🔑 Legacy Patterns

### 1. Global.asax (Application Events)

```csharp
public class MvcApplication : System.Web.HttpApplication
{
    protected void Application_Start()
    {
        AreaRegistration.RegisterAllAreas();
        RouteConfig.RegisterRoutes(RouteTable.Routes);
        BundleConfig.RegisterBundles(BundleTable.Bundles);
    }

    protected void Application_Error()
    {
        var exception = Server.GetLastError();
        // Log error
    }

    protected void Session_Start()
    {
        // Initialize session
    }
}
```

**Modern equivalent:** Program.cs with middleware

### 2. Web.config

```xml
<?xml version="1.0"?>
<configuration>
  <connectionStrings>
    <add name="DefaultConnection" 
         connectionString="Server=localhost;Database=mydb;User Id=sa;Password=pass;" 
         providerName="System.Data.SqlClient" />
  </connectionStrings>
  
  <appSettings>
    <add key="ApiKey" value="my-api-key" />
    <add key="EnableFeature" value="true" />
  </appSettings>
  
  <system.web>
    <compilation debug="true" targetFramework="4.8" />
    <authentication mode="Forms">
      <forms loginUrl="~/Account/Login" timeout="2880" />
    </authentication>
  </system.web>
  
  <system.webServer>
    <modules>
      <remove name="FormsAuthentication" />
    </modules>
  </system.webServer>
</configuration>
```

**Modern equivalent:** appsettings.json

### 3. ASP.NET MVC 5 Controller

```csharp
using System.Web.Mvc; // Not Microsoft.AspNetCore.Mvc!

public class HomeController : Controller
{
    // GET: /Home/Index
    public ActionResult Index()
    {
        return View();
    }

    // POST: /Home/Create
    [HttpPost]
    [ValidateAntiForgeryToken]
    public ActionResult Create(Product product)
    {
        if (ModelState.IsValid)
        {
            db.Products.Add(product);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        return View(product);
    }
}
```

### 4. ADO.NET (Pre-EF)

```csharp
using System.Data.SqlClient;

public List<Product> GetProducts()
{
    var products = new List<Product>();
    
    using (var connection = new SqlConnection(connectionString))
    {
        connection.Open();
        
        using (var command = new SqlCommand("SELECT * FROM Products", connection))
        using (var reader = command.ExecuteReader())
        {
            while (reader.Read())
            {
                products.Add(new Product
                {
                    Id = (int)reader["Id"],
                    Name = (string)reader["Name"],
                    Price = (decimal)reader["Price"]
                });
            }
        }
    }
    
    return products;
}
```

**Modern equivalent:** Entity Framework Core

### 5. WCF Services (Windows Communication Foundation)

```csharp
[ServiceContract]
public interface IProductService
{
    [OperationContract]
    List<Product> GetProducts();
    
    [OperationContract]
    void AddProduct(Product product);
}

public class ProductService : IProductService
{
    public List<Product> GetProducts()
    {
        // Implementation
    }
    
    public void AddProduct(Product product)
    {
        // Implementation
    }
}
```

**Modern equivalent:** gRPC or REST API

## 🔄 Migration Strategies

### 1. Identify Dependencies
```bash
# Check if packages support .NET Core
# Visit nuget.org and check compatibility
```

### 2. Common Migration Issues

| Legacy | Modern Alternative |
|--------|-------------------|
| System.Web | Microsoft.AspNetCore |
| Web.config | appsettings.json |
| Global.asax | Program.cs middleware |
| packages.config | PackageReference |
| WCF | gRPC or REST API |
| WebForms | Blazor or Razor Pages |

### 3. Incremental Migration

1. **Create new .NET Core project**
2. **Copy business logic** (usually works with minimal changes)
3. **Rewrite infrastructure** (web, data access)
4. **Update dependencies**
5. **Test thoroughly**

## 📖 Legacy Code Indicators

When you see these, you're in .NET Framework:

```csharp
using System.Web;                    // Framework
using System.Web.Mvc;                // MVC 5 (not Core)
using System.Configuration;          // Old config system
using System.Data.SqlClient;         // Old ADO.NET (still works but prefer EF)

// Global.asax.cs
public class MvcApplication : System.Web.HttpApplication

// Web.config
<?xml version="1.0"?>
<configuration>
```

## 💡 Working with Legacy Systems

### Do's
✅ Understand the existing architecture before changing
✅ Add new features in a modern way when possible
✅ Document legacy patterns for team knowledge
✅ Propose gradual modernization
✅ Use .NET Standard libraries for shared code

### Don'ts
❌ Don't rewrite everything at once
❌ Don't mix Framework and Core patterns
❌ Don't ignore existing tests
❌ Don't assume Framework is "bad" - it works for many systems

## 🔗 Resources

- [.NET Framework to .NET Core Migration](https://docs.microsoft.com/dotnet/core/porting/)
- [ASP.NET to ASP.NET Core Migration](https://docs.microsoft.com/aspnet/core/migration/proper-to-2x/)
- [WCF to gRPC Migration](https://docs.microsoft.com/dotnet/architecture/grpc-for-wcf-developers/)

## 🎓 Congratulations!

You've completed all 10 lessons! You now have:
- ✅ C# fundamentals and LINQ
- ✅ Understanding of .NET ecosystem
- ✅ Dependency injection skills
- ✅ Web API development knowledge
- ✅ Entity Framework Core with MariaDB
- ✅ Middleware and configuration
- ✅ Authentication patterns
- ✅ Design pattern implementations
- ✅ Legacy .NET Framework understanding

**Next Steps:**
1. Build a complete CRUD API project
2. Contribute to a real .NET codebase
3. Explore advanced topics (SignalR, Blazor, microservices)
4. Keep the documentation for reference!
