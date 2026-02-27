# Migration Guide: .NET Framework to .NET Core/.NET 5+

## Why Migrate?

### Benefits
- ✅ **Cross-platform**: Run on Linux, macOS, Windows
- ✅ **Performance**: 2-3x faster in many scenarios
- ✅ **Modern features**: Latest C# features, better async support
- ✅ **Active development**: Framework is in maintenance mode only
- ✅ **Cloud-ready**: Better containerization, microservices support
- ✅ **Open source**: Community contributions, transparency

### Costs
- ⚠️ **Development time**: Rewriting infrastructure code
- ⚠️ **Testing**: Thorough testing required
- ⚠️ **Learning curve**: New patterns and APIs
- ⚠️ **Third-party dependencies**: May not all be compatible

## Assessment Phase

### 1. Analyze Dependencies

```bash
# Use .NET Portability Analyzer
# Download from: https://github.com/microsoft/dotnet-apiport
```

Check each NuGet package:
- Visit nuget.org
- Look for .NET Standard 2.0+ or .NET Core support
- Find alternatives for incompatible packages

### 2. Identify Blockers

**Hard to migrate:**
- WCF services (consider gRPC or REST)
- WebForms (consider Blazor or Razor Pages)
- Windows-specific APIs
- COM interop
- AppDomains

**Easy to migrate:**
- Business logic
- Data models
- LINQ queries
- Most NuGet packages

## Migration Strategies

### Strategy 1: Big Bang (Small Projects)

Migrate everything at once.

**Best for:**
- Small applications
- Simple dependencies
- Dedicated migration time

**Steps:**
1. Create new .NET Core project
2. Copy code
3. Fix compilation errors
4. Test
5. Deploy

### Strategy 2: Incremental (Large Projects)

Migrate piece by piece.

**Best for:**
- Large applications
- Complex dependencies
- Ongoing development

**Steps:**
1. Extract business logic to .NET Standard libraries
2. Create new .NET Core web layer
3. Gradually migrate features
4. Run both versions in parallel
5. Sunset old version

### Strategy 3: Strangler Fig

Build new features in .NET Core, gradually replace old.

**Best for:**
- Very large applications
- Can't afford downtime
- Long-term migration

## Step-by-Step Migration

### 1. Create New Project

```bash
# Create new .NET 8 Web API
dotnet new webapi -n MyApp.Core

# Or MVC
dotnet new mvc -n MyApp.Core
```

### 2. Update Project File

**Old (.NET Framework):**
```xml
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="15.0" ...>
  <PropertyGroup>
    <TargetFrameworkVersion>v4.8</TargetFrameworkVersion>
  </PropertyGroup>
  <ItemGroup>
    <Reference Include="System" />
    <Reference Include="System.Web" />
  </ItemGroup>
  <ItemGroup>
    <Compile Include="Program.cs" />
  </ItemGroup>
</Project>
```

**New (.NET Core):**
```xml
<Project Sdk="Microsoft.NET.Sdk.Web">
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <Nullable>enable</Nullable>
  </PropertyGroup>
</Project>
```

### 3. Migrate Configuration

**Web.config → appsettings.json**

```xml
<!-- Web.config -->
<connectionStrings>
  <add name="DefaultConnection" connectionString="..." />
</connectionStrings>
<appSettings>
  <add key="ApiKey" value="secret" />
</appSettings>
```

```json
// appsettings.json
{
  "ConnectionStrings": {
    "DefaultConnection": "..."
  },
  "ApiKey": "secret"
}
```

### 4. Migrate Startup

**Global.asax.cs → Program.cs**

```csharp
// Global.asax.cs (Framework)
public class MvcApplication : HttpApplication
{
    protected void Application_Start()
    {
        RouteConfig.RegisterRoutes(RouteTable.Routes);
        BundleConfig.RegisterBundles(BundleTable.Bundles);
    }
}
```

```csharp
// Program.cs (Core)
var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllers();

var app = builder.Build();

app.UseHttpsRedirection();
app.UseAuthorization();
app.MapControllers();

app.Run();
```

### 5. Migrate Controllers

**Minimal changes needed:**

```csharp
// Framework
using System.Web.Mvc;

public class HomeController : Controller
{
    public ActionResult Index()
    {
        return View();
    }
}
```

```csharp
// Core
using Microsoft.AspNetCore.Mvc;

public class HomeController : Controller
{
    public IActionResult Index()
    {
        return View();
    }
}
```

### 6. Migrate Data Access

**Entity Framework 6 → EF Core**

```csharp
// EF6
public class AppDbContext : DbContext
{
    public AppDbContext() : base("name=DefaultConnection") { }
    
    public DbSet<Product> Products { get; set; }
}
```

```csharp
// EF Core
public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options)
        : base(options) { }
    
    public DbSet<Product> Products { get; set; }
}

// Startup
builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseSqlServer(connectionString));
```

## Common Issues and Solutions

### Issue: System.Web not available

**Solution:** Use ASP.NET Core equivalents

```csharp
// Framework
HttpContext.Current.Request.UserHostAddress

// Core
httpContext.Connection.RemoteIpAddress
```

### Issue: ConfigurationManager not available

**Solution:** Use IConfiguration

```csharp
// Framework
ConfigurationManager.AppSettings["Key"]

// Core (inject IConfiguration)
_configuration["Key"]
```

### Issue: Session state

**Solution:** Add session middleware

```csharp
builder.Services.AddSession();
app.UseSession();

// Usage
HttpContext.Session.SetString("key", "value");
var value = HttpContext.Session.GetString("key");
```

## Testing Strategy

1. **Unit tests**: Should mostly work unchanged
2. **Integration tests**: Rewrite using WebApplicationFactory
3. **Manual testing**: Test all features thoroughly
4. **Performance testing**: Verify improvements
5. **Security testing**: Ensure auth/authz works

## Deployment

### Framework
- IIS on Windows Server
- Requires .NET Framework installed

### Core
- IIS, Nginx, Apache
- Self-contained or framework-dependent
- Docker containers
- Linux, Windows, macOS

## Resources

- [Official Migration Guide](https://docs.microsoft.com/aspnet/core/migration/)
- [API Portability Analyzer](https://github.com/microsoft/dotnet-apiport)
- [.NET Upgrade Assistant](https://dotnet.microsoft.com/platform/upgrade-assistant)

## Timeline Estimation

| Project Size | Estimated Time |
|--------------|----------------|
| Small (< 10K LOC) | 1-2 weeks |
| Medium (10-50K LOC) | 1-3 months |
| Large (50-200K LOC) | 3-6 months |
| Enterprise (> 200K LOC) | 6-12+ months |

*These are rough estimates. Actual time depends on complexity, dependencies, and team size.*
