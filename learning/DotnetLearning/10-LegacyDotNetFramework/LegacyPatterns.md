# Legacy .NET Framework Patterns

## Common Patterns You'll Encounter

### 1. Dependency Injection (Pre-Core)

Before .NET Core's built-in DI, developers used third-party containers:

```csharp
// Using Autofac (popular DI container)
var builder = new ContainerBuilder();
builder.RegisterType<ProductService>().As<IProductService>();
builder.RegisterType<ProductRepository>().As<IProductRepository>();
var container = builder.Build();

// Using Ninject
var kernel = new StandardKernel();
kernel.Bind<IProductService>().To<ProductService>();
kernel.Bind<IProductRepository>().To<ProductRepository>();
```

### 2. Configuration Access

```csharp
using System.Configuration;

// Reading from Web.config or App.config
string connectionString = ConfigurationManager.ConnectionStrings["DefaultConnection"].ConnectionString;
string apiKey = ConfigurationManager.AppSettings["ApiKey"];
```

### 3. Entity Framework 6 (Not Core)

```csharp
public class AppDbContext : DbContext
{
    public AppDbContext() : base("name=DefaultConnection")
    {
    }

    public DbSet<Product> Products { get; set; }

    protected override void OnModelCreating(DbModelBuilder modelBuilder)
    {
        // Fluent API configuration
        modelBuilder.Entity<Product>()
            .HasKey(p => p.Id);
    }
}

// Usage
using (var context = new AppDbContext())
{
    var products = context.Products.Where(p => p.Price > 100).ToList();
}
```

### 4. ASP.NET MVC Filters

```csharp
// Action filter (like middleware)
public class LogActionFilter : ActionFilterAttribute
{
    public override void OnActionExecuting(ActionExecutingContext filterContext)
    {
        // Before action executes
        var controller = filterContext.Controller;
        var action = filterContext.ActionDescriptor.ActionName;
        
        base.OnActionExecuting(filterContext);
    }

    public override void OnActionExecuted(ActionExecutedContext filterContext)
    {
        // After action executes
        base.OnActionExecuted(filterContext);
    }
}

// Usage
[LogActionFilter]
public class HomeController : Controller
{
    public ActionResult Index()
    {
        return View();
    }
}
```

### 5. Bundling and Minification

```csharp
// App_Start/BundleConfig.cs
public class BundleConfig
{
    public static void RegisterBundles(BundleCollection bundles)
    {
        bundles.Add(new ScriptBundle("~/bundles/jquery").Include(
            "~/Scripts/jquery-{version}.js"));

        bundles.Add(new StyleBundle("~/Content/css").Include(
            "~/Content/bootstrap.css",
            "~/Content/site.css"));
    }
}

// In View
@Scripts.Render("~/bundles/jquery")
@Styles.Render("~/Content/css")
```

## Migration Checklist

When migrating from .NET Framework to .NET Core:

- [ ] Check all NuGet packages for .NET Core compatibility
- [ ] Replace System.Web references
- [ ] Convert Web.config to appsettings.json
- [ ] Update project file to SDK-style
- [ ] Replace Global.asax with Program.cs
- [ ] Update Entity Framework 6 to EF Core
- [ ] Replace custom DI container with built-in DI
- [ ] Update authentication/authorization
- [ ] Test thoroughly!

## Common Namespaces

### Framework-Only
- `System.Web` - Web functionality
- `System.Web.Mvc` - MVC 5
- `System.Web.Http` - Web API 2
- `System.Configuration` - Configuration
- `System.Data.Entity` - Entity Framework 6

### Cross-Platform (work in both)
- `System.Linq`
- `System.Collections.Generic`
- `System.Threading.Tasks`
- `System.Text`
