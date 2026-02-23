# .NET Framework vs .NET Core/.NET 5+

## Overview

Understanding the difference between .NET Framework and modern .NET is crucial when working with legacy systems.

## .NET Framework (Legacy)

### Characteristics
- **Windows-only**: Cannot run on Linux or macOS
- **System-wide installation**: Shared across all applications
- **Monolithic**: Large, tightly coupled framework
- **Last version**: 4.8 (released 2019, still supported)

### Project Structure
```xml
<!-- Old-style .csproj -->
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <PropertyGroup>
    <TargetFrameworkVersion>v4.8</TargetFrameworkVersion>
  </PropertyGroup>
  <ItemGroup>
    <Reference Include="System" />
    <Reference Include="System.Core" />
    <!-- Must list every file -->
    <Compile Include="Program.cs" />
    <Compile Include="Helper.cs" />
  </ItemGroup>
</Project>
```

### Configuration
- **web.config** for web apps
- **app.config** for console/desktop apps
- XML-based configuration

### Package Management
```xml
<!-- packages.config -->
<?xml version="1.0" encoding="utf-8"?>
<packages>
  <package id="Newtonsoft.Json" version="12.0.3" targetFramework="net48" />
</packages>
```

### Common Namespaces
- `System.Web` - Web applications
- `System.Data.SqlClient` - Database access
- `System.Configuration` - Configuration management

## .NET Core / .NET 5+ (Modern)

### Characteristics
- **Cross-platform**: Windows, Linux, macOS
- **Self-contained deployment**: Can bundle runtime with app
- **Modular**: Only include what you need
- **High performance**: Significantly faster than Framework
- **Open source**: Developed on GitHub

### Project Structure
```xml
<!-- Modern SDK-style .csproj -->
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <Nullable>enable</Nullable>
  </PropertyGroup>
  
  <ItemGroup>
    <PackageReference Include="Newtonsoft.Json" Version="13.0.3" />
  </ItemGroup>
</Project>
```

### Configuration
- **appsettings.json** - JSON-based configuration
- **appsettings.Development.json** - Environment-specific
- **User secrets** - Sensitive data (development)
- **Environment variables** - Production configuration

### Package Management
- Integrated into .csproj via `<PackageReference>`
- No separate packages.config file

### Common Namespaces
- `Microsoft.AspNetCore` - Web applications
- `Microsoft.EntityFrameworkCore` - ORM
- `Microsoft.Extensions.Configuration` - Configuration
- `Microsoft.Extensions.DependencyInjection` - DI container

## Migration Path

### When to Migrate
✅ **Migrate if**:
- Starting new projects
- Need cross-platform support
- Want better performance
- Need modern features (async streams, records, etc.)

❌ **Don't migrate if**:
- Legacy app works fine and won't be maintained
- Uses Windows-specific APIs (WCF, WPF, WinForms)
- Migration cost outweighs benefits

### Migration Strategy
1. **Assess dependencies**: Check if all NuGet packages support .NET Core
2. **Incremental migration**: Move one project at a time
3. **Use .NET Standard**: For shared libraries
4. **Test thoroughly**: Behavior may differ slightly

## Key Differences for Java Developers

| Concept | Java | .NET Framework | .NET Core/.NET 5+ |
|---------|------|----------------|-------------------|
| Build Tool | Maven/Gradle | MSBuild | dotnet CLI |
| Dependency Management | pom.xml | packages.config | PackageReference |
| Configuration | application.properties | web.config | appsettings.json |
| Deployment | JAR/WAR | DLL + Framework | Self-contained or Framework-dependent |
| Cross-platform | Yes | No | Yes |

## Identifying Legacy Code

### .NET Framework Indicators
```csharp
using System.Web;              // ASP.NET (not Core)
using System.Web.Mvc;          // MVC 5 (not Core)
using System.Configuration;    // Old config system

// Global.asax.cs
public class MvcApplication : System.Web.HttpApplication
{
    protected void Application_Start()
    {
        // Framework-style startup
    }
}
```

### .NET Core/.NET 5+ Indicators
```csharp
using Microsoft.AspNetCore;
using Microsoft.Extensions.DependencyInjection;

// Program.cs (modern)
var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();
app.Run();
```

## Version Targeting

### Target Framework Monikers (TFM)
```xml
<TargetFramework>net48</TargetFramework>        <!-- .NET Framework 4.8 -->
<TargetFramework>netcoreapp3.1</TargetFramework> <!-- .NET Core 3.1 -->
<TargetFramework>net6.0</TargetFramework>        <!-- .NET 6 -->
<TargetFramework>net8.0</TargetFramework>        <!-- .NET 8 (current LTS) -->
<TargetFramework>netstandard2.0</TargetFramework> <!-- .NET Standard (libraries) -->
```

### Multi-targeting
```xml
<TargetFrameworks>net48;net8.0</TargetFrameworks>
```

## Practical Advice

### For Legacy System Work
1. **Learn both**: You'll encounter both in the wild
2. **Focus on concepts**: DI, middleware, etc. are similar
3. **Use documentation**: Framework docs are still available
4. **Ask about version**: First question when joining a project

### For New Development
1. **Always use .NET 8** (or latest LTS)
2. **Enable nullable reference types**
3. **Use minimal APIs** for simple services
4. **Follow modern patterns**

## Resources

- [.NET Framework vs .NET Core](https://docs.microsoft.com/dotnet/standard/choosing-core-framework-server)
- [Porting Guide](https://docs.microsoft.com/dotnet/core/porting/)
- [.NET Standard](https://docs.microsoft.com/dotnet/standard/net-standard)
