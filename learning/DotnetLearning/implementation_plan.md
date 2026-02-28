# .NET Learning Plan for Java/Spring Boot Developers

A focused learning path covering the critical 20% of .NET that delivers 80% of the value for working with legacy systems and contributing as a mid-level backend engineer.

## User Review Required

> [!IMPORTANT]
> **Learning Approach**: This plan focuses on practical, hands-on learning with direct comparisons to Java/Spring Boot concepts you already know. Each lesson includes runnable code examples.

> [!NOTE]
> **Time Commitment**: Estimated 2-3 weeks of focused learning (2-3 hours per day) to complete all lessons and exercises.

---

## Prerequisites & Setup

### Required Software Installation

1. **.NET SDK** (Latest LTS version - .NET 8.0 recommended)
   - Download: https://dotnet.microsoft.com/download
   - Verify installation: `dotnet --version`

2. **IDE Options** (Choose one):
   - **Visual Studio 2022 Community** (Recommended for Windows, full-featured)
   - **Visual Studio Code** + C# Dev Kit extension (Lightweight, cross-platform)
   - **JetBrains Rider** (If you're familiar with IntelliJ)

3. **SQL Server Express** (Optional, for database lessons)
   - Download: https://www.microsoft.com/en-us/sql-server/sql-server-downloads
   - Alternative: Use SQLite for simpler setup

### Verification Commands
```bash
dotnet --version          # Should show 8.0.x or higher
dotnet --list-sdks        # List installed SDKs
dotnet new list           # Show available project templates
```

---

## Proposed Changes

### Folder Structure

```
DotnetLearning/
├── README.md                           # Overview and setup instructions
├── 01-CSharpFundamentals/             # C# syntax, types, LINQ
├── 02-DotNetEcosystem/                # Framework vs Core, runtime concepts
├── 03-DependencyInjection/            # Built-in DI container
├── 04-WebApiBasics/                   # ASP.NET Core Web API
├── 05-EntityFrameworkCore/            # ORM and database access
├── 06-MiddlewareAndPipeline/          # Request processing
├── 07-ConfigurationManagement/        # appsettings.json, environment variables
├── 08-AuthenticationAuthorization/    # JWT, Identity, policies
├── 09-DesignPatterns/                 # Common patterns in .NET
└── 10-LegacyDotNetFramework/          # Understanding older codebases
```

---

### Lesson 1: C# Fundamentals & Syntax Comparison

**Focus**: Core C# syntax with Java comparisons

#### [NEW] [01-CSharpFundamentals](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/01-CSharpFundamentals)

**Topics Covered**:
- Value types vs Reference types (struct vs class)
- Properties and auto-properties (vs Java getters/setters)
- LINQ (vs Java Streams)
- Nullable reference types
- Extension methods
- Async/await (vs CompletableFuture)
- Records (vs Java records)

**Files**:
- `Program.cs` - Main examples
- `TypesComparison.cs` - Type system examples
- `LinqExamples.cs` - LINQ vs Java Streams
- `AsyncExamples.cs` - Async patterns
- `README.md` - Lesson notes and comparisons

---

### Lesson 2: .NET Ecosystem Understanding

**Focus**: Understanding .NET Framework vs .NET Core/.NET 6+

#### [NEW] [02-DotNetEcosystem](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/02-DotNetEcosystem)

**Topics Covered**:
- .NET Framework (legacy, Windows-only)
- .NET Core → .NET 5/6/7/8 (modern, cross-platform)
- Runtime concepts (CLR vs JVM)
- NuGet packages (vs Maven/npm)
- Project file structure (.csproj vs pom.xml)
- Solution files (.sln)

**Files**:
- `FrameworkVsCore.md` - Key differences
- `ProjectStructure/` - Sample project layouts
- `README.md` - Ecosystem overview

---

### Lesson 3: Dependency Injection & IoC Container

**Focus**: Built-in DI container (vs Spring's IoC)

#### [NEW] [03-DependencyInjection](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/03-DependencyInjection)

**Topics Covered**:
- Service lifetimes: Transient, Scoped, Singleton (vs Spring scopes)
- Constructor injection
- Service registration
- IServiceProvider
- Configuration binding

**Files**:
- `Program.cs` - DI setup
- `Services/` - Example services
- `Controllers/` - Consuming services
- `README.md` - DI concepts and Spring comparison

---

### Lesson 4: ASP.NET Core Web API Basics

**Focus**: Building REST APIs (vs Spring Boot REST)

#### [NEW] [04-WebApiBasics](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/04-WebApiBasics)

**Topics Covered**:
- Controller-based APIs (vs @RestController)
- Minimal APIs (new in .NET 6+)
- Routing and attribute routing
- Model binding and validation
- Action results
- Exception handling

**Files**:
- `Controllers/ProductController.cs` - Traditional controller
- `MinimalApiExample.cs` - Minimal API approach
- `Models/` - DTOs and validation
- `Program.cs` - API setup
- `README.md` - API patterns comparison

---

### Lesson 5: Entity Framework Core

**Focus**: ORM for database access (vs JPA/Hibernate)

#### [NEW] [05-EntityFrameworkCore](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/05-EntityFrameworkCore)

**Topics Covered**:
- DbContext (vs EntityManager)
- Code-First approach
- Migrations (vs Flyway/Liquibase)
- LINQ queries (vs JPQL/Criteria API)
- Relationships and navigation properties
- Repository pattern

**Files**:
- `Data/AppDbContext.cs` - DbContext setup
- `Models/` - Entity classes
- `Repositories/` - Repository pattern
- `Migrations/` - Generated migrations
- `Program.cs` - EF Core configuration
- `README.md` - EF Core vs JPA comparison

---

### Lesson 6: Middleware & Request Pipeline

**Focus**: Request processing pipeline (vs Spring filters/interceptors)

#### [NEW] [06-MiddlewareAndPipeline](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/06-MiddlewareAndPipeline)

**Topics Covered**:
- Middleware concept and order
- Built-in middleware (CORS, Auth, Static Files)
- Custom middleware
- Exception handling middleware
- Request/Response manipulation

**Files**:
- `Middleware/LoggingMiddleware.cs` - Custom middleware
- `Middleware/ExceptionMiddleware.cs` - Global exception handling
- `Program.cs` - Pipeline configuration
- `README.md` - Middleware vs Spring filters

---

### Lesson 7: Configuration & Environment Management

**Focus**: Application configuration (vs application.properties/yml)

#### [NEW] [07-ConfigurationManagement](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/07-ConfigurationManagement)

**Topics Covered**:
- appsettings.json structure
- Environment-specific configs
- User secrets (vs Spring Cloud Config)
- Options pattern
- Environment variables
- Configuration binding

**Files**:
- `appsettings.json` - Base configuration
- `appsettings.Development.json` - Dev overrides
- `Models/AppSettings.cs` - Strongly-typed config
- `Program.cs` - Configuration setup
- `README.md` - Configuration patterns

---

### Lesson 8: Authentication & Authorization

**Focus**: Security patterns (vs Spring Security)

#### [NEW] [08-AuthenticationAuthorization](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/08-AuthenticationAuthorization)

**Topics Covered**:
- JWT authentication
- ASP.NET Core Identity
- Authorization policies
- Role-based and claims-based auth
- [Authorize] attribute

**Files**:
- `Services/AuthService.cs` - JWT generation
- `Controllers/AuthController.cs` - Login/register
- `Models/` - User models
- `Program.cs` - Auth configuration
- `README.md` - Security comparison

---

### Lesson 9: Design Patterns in .NET

**Focus**: Common patterns in .NET context

#### [NEW] [09-DesignPatterns](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/09-DesignPatterns)

**Topics Covered**:
- Repository pattern
- Unit of Work
- Factory pattern with DI
- Strategy pattern
- Decorator pattern (middleware)
- CQRS basics
- MediatR library

**Files**:
- `Patterns/Repository/` - Repository implementation
- `Patterns/Factory/` - Factory with DI
- `Patterns/Strategy/` - Strategy examples
- `README.md` - Pattern implementations

---

### Lesson 10: Legacy .NET Framework Patterns

**Focus**: Understanding older codebases

#### [NEW] [10-LegacyDotNetFramework](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/10-LegacyDotNetFramework)

**Topics Covered**:
- ASP.NET MVC (vs ASP.NET Core MVC)
- Web.config (vs appsettings.json)
- Global.asax
- System.Web namespace
- ADO.NET (vs Entity Framework)
- WCF services basics

**Files**:
- `LegacyPatterns.md` - Common legacy patterns
- `MigrationGuide.md` - Framework to Core migration tips
- `Examples/` - Legacy code samples
- `README.md` - Working with legacy systems

---

### Root Level Files

#### [NEW] [README.md](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/README.md)

Master README with:
- Learning path overview
- Setup instructions
- Lesson sequence
- Additional resources
- Common commands cheat sheet

#### [NEW] [.gitignore](file:///c:/Users/sahug/OneDrive/Desktop/ganeshdocs/antigravity/learning/DotnetLearning/.gitignore)

Standard .NET gitignore for bin/, obj/, etc.

---

## Verification Plan

### Automated Tests
- Each lesson will include a runnable console app or Web API project
- Use `dotnet run` to execute examples
- Use `dotnet test` for unit test examples (introduced in later lessons)

### Manual Verification
1. **Setup Verification**: Run `dotnet --version` and create a test project
2. **Lesson Completion**: Each lesson has a "Challenge" section to build something independently
3. **Final Project**: Build a simple CRUD API combining all concepts

### Success Criteria
- All lesson projects compile and run successfully
- User can explain .NET concepts using Java/Spring Boot analogies
- User can navigate and understand a legacy .NET Framework codebase
- User can create a basic ASP.NET Core Web API from scratch
