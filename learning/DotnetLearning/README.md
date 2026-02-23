# .NET Learning Path for Java/Spring Boot Developers

Welcome to your focused .NET learning journey! This curriculum is designed specifically for developers with Java/Spring Boot experience who want to understand and work with .NET legacy systems.

## 🎯 Learning Objectives

By completing this course, you will:
- Understand C# syntax and how it compares to Java
- Build REST APIs with ASP.NET Core
- Work with Entity Framework Core (ORM)
- Navigate and contribute to legacy .NET Framework codebases
- Apply design patterns in the .NET ecosystem
- Be ready to work as a mid-level .NET backend engineer

## 📋 Prerequisites

### Required Software

1. **.NET SDK 8.0** (LTS)
   - Download: https://dotnet.microsoft.com/download
   - Verify: `dotnet --version`

2. **IDE** (Choose one):
   - **Visual Studio 2022 Community** (Recommended for Windows)
   - **Visual Studio Code** + C# Dev Kit extension
   - **JetBrains Rider**

3. **MariaDB** (via XAMPP)
   - Ensure MariaDB is running on port 3306
   - Default credentials: root / (no password)

### Verification

```bash
# Check .NET installation
dotnet --version

# List available project templates
dotnet new list

# Check MariaDB connection (from XAMPP)
# Open phpMyAdmin at http://localhost/phpmyadmin
```

## 📚 Learning Path

This course follows the **80/20 principle** - covering the 20% of .NET that you'll use 80% of the time.

### Lesson Sequence

| Lesson | Topic | Duration | Key Concepts |
|--------|-------|----------|--------------|
| 01 | C# Fundamentals | 3-4 hours | Syntax, LINQ, async/await |
| 02 | .NET Ecosystem | 2-3 hours | Framework vs Core, project structure |
| 03 | Dependency Injection | 2-3 hours | DI container, service lifetimes |
| 04 | Web API Basics | 4-5 hours | Controllers, routing, validation |
| 05 | Entity Framework Core | 4-5 hours | DbContext, migrations, queries |
| 06 | Middleware & Pipeline | 3-4 hours | Request processing, custom middleware |
| 07 | Configuration | 2-3 hours | appsettings.json, environment configs |
| 08 | Auth & Security | 4-5 hours | JWT, Identity, authorization |
| 09 | Design Patterns | 3-4 hours | Repository, UoW, CQRS |
| 10 | Legacy .NET Framework | 3-4 hours | Understanding older codebases |

**Total Estimated Time**: 30-40 hours (2-3 weeks at 2-3 hours/day)

## 🗂️ Folder Structure

```
DotnetLearning/
├── README.md                          ← You are here
├── implementation_plan.md             ← Detailed lesson plans
├── task.md                            ← Progress tracking
├── .gitignore                         ← .NET gitignore
│
├── 01-CSharpFundamentals/            ← Start here!
│   ├── README.md
│   ├── Program.cs
│   ├── TypesComparison.cs
│   ├── LinqExamples.cs
│   └── AsyncExamples.cs
│
├── 02-DotNetEcosystem/
│   ├── README.md
│   └── FrameworkVsCore.md
│
├── 03-DependencyInjection/
│   ├── README.md
│   ├── Program.cs
│   └── Services/
│
├── 04-WebApiBasics/
│   ├── README.md
│   ├── Program.cs
│   ├── Controllers/
│   └── Models/
│
├── 05-EntityFrameworkCore/
│   ├── README.md
│   ├── Program.cs
│   ├── Data/
│   ├── Models/
│   └── Repositories/
│
├── 06-MiddlewareAndPipeline/
│   ├── README.md
│   ├── Program.cs
│   └── Middleware/
│
├── 07-ConfigurationManagement/
│   ├── README.md
│   ├── Program.cs
│   └── appsettings.json
│
├── 08-AuthenticationAuthorization/
│   ├── README.md
│   ├── Program.cs
│   ├── Services/
│   └── Controllers/
│
├── 09-DesignPatterns/
│   ├── README.md
│   └── Patterns/
│
└── 10-LegacyDotNetFramework/
    ├── README.md
    ├── LegacyPatterns.md
    └── MigrationGuide.md
```

## 🚀 Getting Started

### Step 1: Verify Setup

```bash
# Navigate to the learning directory
cd c:\Users\sahug\OneDrive\Desktop\ganeshdocs\antigravity\learning\DotnetLearning

# Verify .NET is installed
dotnet --version
```

### Step 2: Start with Lesson 01

```bash
cd 01-CSharpFundamentals
dotnet run
```

### Step 3: Follow the README in Each Lesson

Each lesson folder contains:
- **README.md** - Lesson objectives, concepts, and Java comparisons
- **Code files** - Runnable examples
- **Exercises** - Hands-on challenges

## 💡 Learning Tips

### For Java Developers

- **Think in terms of Spring Boot**: Each lesson draws parallels to Spring concepts
- **LINQ is your friend**: Similar to Java Streams but more powerful
- **Embrace properties**: They're cleaner than getters/setters
- **async/await > CompletableFuture**: Much simpler async programming

### Best Practices

1. **Run every code example** - Don't just read, execute!
2. **Complete the exercises** - Hands-on practice is crucial
3. **Compare with Java** - Use your existing knowledge as a foundation
4. **Ask "why?"** - Understand the .NET way of doing things
5. **Build something** - Apply concepts to a small project

## 📖 Common Commands Cheat Sheet

```bash
# Create new console app
dotnet new console -n MyApp

# Create new Web API
dotnet new webapi -n MyApi

# Restore dependencies
dotnet restore

# Build project
dotnet build

# Run project
dotnet run

# Run with hot reload
dotnet watch run

# Add NuGet package
dotnet add package PackageName

# Entity Framework migrations
dotnet ef migrations add InitialCreate
dotnet ef database update

# Run tests
dotnet test
```

## 🔗 Additional Resources

### Official Documentation
- [Microsoft .NET Documentation](https://docs.microsoft.com/dotnet/)
- [C# Programming Guide](https://docs.microsoft.com/dotnet/csharp/)
- [ASP.NET Core Documentation](https://docs.microsoft.com/aspnet/core/)
- [Entity Framework Core](https://docs.microsoft.com/ef/core/)

### For Java Developers
- [C# for Java Developers](https://docs.microsoft.com/dotnet/csharp/programming-guide/concepts/)
- [ASP.NET Core vs Spring Boot](https://stackify.com/asp-net-core-vs-spring-boot/)

### Community
- [Stack Overflow - .NET Tag](https://stackoverflow.com/questions/tagged/.net)
- [r/dotnet](https://reddit.com/r/dotnet)
- [.NET Discord](https://aka.ms/dotnet-discord)

## 📊 Progress Tracking

Use `task.md` to track your progress through the lessons. Mark items as complete as you go!

## 🎓 Final Project

After completing all lessons, you'll build a complete CRUD API that demonstrates:
- RESTful endpoints
- Entity Framework Core with MariaDB
- JWT authentication
- Repository pattern
- Proper configuration management
- Exception handling middleware

## 🆘 Troubleshooting

### Common Issues

**"dotnet command not found"**
- Restart your terminal after installing .NET SDK
- Verify PATH environment variable includes .NET

**"Unable to connect to database"**
- Ensure XAMPP MariaDB is running
- Check connection string in appsettings.json
- Verify port 3306 is not blocked

**"Package restore failed"**
- Check internet connection
- Clear NuGet cache: `dotnet nuget locals all --clear`

## 📝 Notes

- All database examples use **MariaDB** (MySQL-compatible)
- Connection strings are configured for XAMPP default setup
- Each lesson is self-contained and runnable
- Code includes extensive comments for future reference

---

**Ready to start?** Head to `01-CSharpFundamentals/` and begin your .NET journey! 🚀
