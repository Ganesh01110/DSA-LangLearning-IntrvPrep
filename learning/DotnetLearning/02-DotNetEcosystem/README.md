# Lesson 02: .NET Ecosystem Understanding

## 🎯 Learning Objectives

- Understand .NET Framework vs .NET Core vs .NET 5+
- Navigate project structure (.csproj, .sln)
- Work with NuGet packages
- Understand the CLR and runtime concepts
- Know when you're dealing with legacy vs modern .NET

## 📚 Key Concepts

### .NET Evolution Timeline

```
.NET Framework (2002-2022)
├─ Windows-only
├─ Monolithic
├─ Legacy codebases
└─ Last version: 4.8

.NET Core (2016-2020)
├─ Cross-platform
├─ Modular
├─ Open source
└─ Versions: 1.0, 2.0, 3.0, 3.1

.NET 5+ (2020-present)
├─ Unified platform
├─ Annual releases
├─ Modern development
└─ Versions: 5, 6 (LTS), 7, 8 (LTS)
```

## 🔍 Framework vs Core Comparison

| Feature | .NET Framework | .NET Core/.NET 5+ |
|---------|----------------|-------------------|
| Platform | Windows only | Cross-platform |
| Open Source | No | Yes |
| Performance | Good | Excellent |
| Deployment | System-wide | Self-contained |
| Config | web.config/app.config | appsettings.json |
| Project File | Verbose XML | Minimal SDK-style |
| Package Manager | NuGet (packages.config) | NuGet (PackageReference) |

## 📁 Project Structure

### .csproj File (SDK-Style)

```xml
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

**vs Java's pom.xml**:
- Much more concise
- Auto-includes all .cs files
- SDK handles most defaults

### Solution File (.sln)

Groups multiple projects together (like a multi-module Maven project)

```
MySolution.sln
├── MyWebApi/
│   └── MyWebApi.csproj
├── MyLibrary/
│   └── MyLibrary.csproj
└── MyTests/
    └── MyTests.csproj
```

## 📦 NuGet vs Maven

| Maven | NuGet |
|-------|-------|
| pom.xml | .csproj |
| mvn install | dotnet restore |
| mvn clean package | dotnet build |
| mvn exec:java | dotnet run |
| Maven Central | nuget.org |

## 🏃 Common Commands

```bash
# Create new project
dotnet new console -n MyApp
dotnet new webapi -n MyApi

# Restore packages
dotnet restore

# Build
dotnet build

# Run
dotnet run

# Add package
dotnet add package EntityFrameworkCore

# Create solution
dotnet new sln -n MySolution
dotnet sln add MyProject/MyProject.csproj
```

## 🔧 Runtime Concepts

### CLR vs JVM

| CLR (.NET) | JVM (Java) |
|------------|------------|
| Common Language Runtime | Java Virtual Machine |
| Runs IL (Intermediate Language) | Runs bytecode |
| JIT compilation | JIT compilation |
| Garbage collection | Garbage collection |
| Multiple languages (C#, F#, VB) | Primarily Java (+ Kotlin, Scala) |

## 📖 Additional Resources

- [.NET Platform Overview](https://docs.microsoft.com/dotnet/core/introduction)
- [Migrate from .NET Framework to .NET](https://docs.microsoft.com/dotnet/core/porting/)

## ⏭️ Next Lesson

Move to **Lesson 03: Dependency Injection** to learn about .NET's built-in DI container.
