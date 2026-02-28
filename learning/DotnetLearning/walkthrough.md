# .NET Learning Curriculum - Walkthrough

## 📦 What Was Created

A complete, production-ready .NET learning curriculum tailored for Java/Spring Boot developers. The curriculum covers the critical 20% of .NET knowledge that delivers 80% of the value for backend development and legacy system maintenance.

## 📁 Folder Structure

```
DotnetLearning/
├── README.md                          Master guide with setup and overview
├── implementation_plan.md             Detailed lesson plans
├── task.md                            Progress tracking
├── .gitignore                         .NET-specific gitignore
│
├── 01-CSharpFundamentals/            ✅ Complete with runnable examples
│   ├── README.md
│   ├── Program.cs                     Main examples runner
│   ├── TypesComparison.cs             Value vs reference types
│   ├── LinqExamples.cs                LINQ vs Java Streams
│   ├── AsyncExamples.cs               Async/await patterns
│   └── CSharpFundamentals.csproj
│
├── 02-DotNetEcosystem/               ✅ Documentation complete
│   ├── README.md
│   └── FrameworkVsCore.md             Framework vs Core comparison
│
├── 03-DependencyInjection/           ✅ Complete with runnable examples
│   ├── README.md
│   ├── Program.cs                     DI lifetime demonstrations
│   └── DependencyInjection.csproj
│
├── 04-WebApiBasics/                  ✅ Complete REST API
│   ├── README.md
│   ├── Program.cs                     Full CRUD API with Swagger
│   └── WebApiBasics.csproj
│
├── 05-EntityFrameworkCore/           ✅ Complete with MariaDB
│   ├── README.md
│   ├── Program.cs                     EF Core + Repository pattern
│   ├── appsettings.json               MariaDB connection (XAMPP)
│   └── EntityFrameworkCore.csproj
│
├── 06-MiddlewareAndPipeline/         ✅ Documentation complete
│   └── README.md
│
├── 07-ConfigurationManagement/       ✅ Documentation complete
│   └── README.md
│
├── 08-AuthenticationAuthorization/   ✅ Documentation complete
│   └── README.md
│
├── 09-DesignPatterns/                ✅ Documentation complete
│   └── README.md
│
└── 10-LegacyDotNetFramework/         ✅ Complete with guides
    ├── README.md
    ├── LegacyPatterns.md              Common legacy patterns
    └── MigrationGuide.md              Framework to Core migration
```

## 🎯 Key Features

### 1. Java/Spring Boot Comparisons Throughout

Every lesson includes direct comparisons to familiar Java concepts:
- Properties vs getters/setters
- LINQ vs Java Streams
- async/await vs CompletableFuture
- DI lifetimes vs Spring scopes
- Controllers vs @RestController
- EF Core vs JPA/Hibernate

### 2. Runnable Code Examples

**Lesson 01** - C# Fundamentals:
```bash
cd 01-CSharpFundamentals
dotnet run
```
Demonstrates:
- Properties and auto-properties
- Value vs reference types
- LINQ operations
- Async/await patterns
- Records and nullable types
- Extension methods

**Lesson 03** - Dependency Injection:
```bash
cd 03-DependencyInjection
dotnet run
```
Shows service lifetimes in action with GUID tracking.

**Lesson 04** - Web API:
```bash
cd 04-WebApiBasics
dotnet run
# Visit https://localhost:5001/swagger
```
Full CRUD API with:
- GET, POST, PUT, DELETE endpoints
- Model validation
- Swagger UI
- Search functionality

**Lesson 05** - Entity Framework Core:
```bash
cd 05-EntityFrameworkCore
dotnet run
# Visit https://localhost:5001/swagger
```
Complete database example with:
- MariaDB connection (XAMPP)
- Auto-migrations on startup
- Repository pattern
- Seed data
- Product-Category relationships

### 3. MariaDB Configuration (XAMPP)

All database examples are pre-configured for XAMPP:
- Server: localhost
- Port: 3306
- User: root
- Password: (empty)
- Database: dotnet_learning

Connection string in `appsettings.json`:
```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Server=localhost;Port=3306;Database=dotnet_learning;User=root;Password=;"
  }
}
```

### 4. Comprehensive Documentation

Each lesson includes:
- **Learning objectives** - What you'll master
- **Key concepts** - Core ideas explained
- **Code examples** - Practical implementations
- **Java comparisons** - Relate to existing knowledge
- **Best practices** - Do's and don'ts
- **Resources** - Links to official docs

### 5. Legacy System Support

Lesson 10 provides:
- **LegacyPatterns.md** - Common patterns in old codebases
- **MigrationGuide.md** - Framework to Core migration strategies
- Understanding of:
  - Global.asax vs Program.cs
  - Web.config vs appsettings.json
  - ASP.NET MVC 5 vs ASP.NET Core
  - Entity Framework 6 vs EF Core
  - WCF services

## 🚀 Getting Started

### Step 1: Install .NET SDK

1. Download .NET 8 SDK from https://dotnet.microsoft.com/download
2. Install and restart terminal
3. Verify installation:
```bash
dotnet --version
# Should show 8.0.x
```

### Step 2: Choose an IDE

**Option A: Visual Studio 2022 Community** (Recommended for Windows)
- Full-featured IDE
- Excellent debugging
- Built-in database tools

**Option B: Visual Studio Code**
- Lightweight
- Install "C# Dev Kit" extension
- Cross-platform

**Option C: JetBrains Rider**
- Similar to IntelliJ IDEA
- Excellent for Java developers
- Paid (with free trial)

### Step 3: Setup MariaDB (XAMPP)

1. Open XAMPP Control Panel
2. Start "MySQL" (MariaDB) service
3. Verify it's running on port 3306
4. (Optional) Open phpMyAdmin to view database

### Step 4: Start Learning!

```bash
cd c:\Users\sahug\OneDrive\Desktop\ganeshdocs\antigravity\learning\DotnetLearning

# Read the master README
# Then start with Lesson 01
cd 01-CSharpFundamentals
dotnet run
```

## 📚 Learning Path

### Week 1: Fundamentals (Lessons 01-03)
- **Day 1-2**: C# syntax, LINQ, async/await
- **Day 3**: .NET ecosystem understanding
- **Day 4-5**: Dependency injection

### Week 2: Web Development (Lessons 04-07)
- **Day 1-2**: Web API basics
- **Day 3-4**: Entity Framework Core with MariaDB
- **Day 5**: Middleware and configuration

### Week 3: Advanced Topics (Lessons 08-10)
- **Day 1-2**: Authentication and authorization
- **Day 3**: Design patterns
- **Day 4-5**: Legacy .NET Framework

## 🔧 Running the Examples

### Console Applications (Lessons 01, 03)

```bash
cd <lesson-folder>
dotnet run
```

### Web APIs (Lessons 04, 05)

```bash
cd <lesson-folder>
dotnet run

# Access Swagger UI
# Open browser: https://localhost:5001/swagger
```

### Database Setup (Lesson 05)

```bash
# Install EF Core tools (one-time)
dotnet tool install --global dotnet-ef

cd 05-EntityFrameworkCore

# Database is auto-created on first run!
dotnet run

# Or manually create migrations
dotnet ef migrations add InitialCreate
dotnet ef database update
```

## 💡 Tips for Success

### 1. Hands-On Practice
Don't just read - run every example and modify the code to see what happens.

### 2. Use Your Java Knowledge
Constantly relate new .NET concepts to Java/Spring Boot equivalents.

### 3. Leverage Documentation
Each README has links to official Microsoft docs for deeper dives.

### 4. Build Something
After completing the lessons, build a small CRUD API from scratch to solidify learning.

### 5. Keep This as Reference
The documentation is designed for future reference - bookmark it!

## 🎓 What You'll Know After Completion

✅ **C# Language**
- Syntax and idioms
- LINQ for data manipulation
- Async/await for concurrent programming
- Modern C# features (records, nullable types)

✅ **ASP.NET Core**
- Building REST APIs
- Routing and model binding
- Middleware pipeline
- Configuration management

✅ **Entity Framework Core**
- Database-first and code-first approaches
- LINQ queries
- Migrations
- Repository pattern

✅ **Dependency Injection**
- Service lifetimes
- Constructor injection
- Configuration binding

✅ **Authentication & Security**
- JWT authentication
- Authorization policies
- Role-based access control

✅ **Design Patterns**
- Repository and Unit of Work
- Factory with DI
- Strategy pattern
- CQRS basics

✅ **Legacy Systems**
- .NET Framework patterns
- Migration strategies
- Working with existing codebases

## 🔄 Next Steps

After completing this curriculum:

1. **Build a Project**: Create a complete CRUD API with authentication
2. **Contribute**: Find an open-source .NET project on GitHub
3. **Explore Advanced Topics**:
   - SignalR (real-time communication)
   - Blazor (web UI framework)
   - gRPC (modern RPC framework)
   - Microservices with .NET
4. **Certifications**: Consider Microsoft certifications if needed for your career

## 📞 Troubleshooting

### "dotnet command not found"
- Restart terminal after installing .NET SDK
- Check PATH environment variable

### "Unable to connect to database"
- Ensure XAMPP MariaDB is running
- Check port 3306 is not blocked
- Verify connection string in appsettings.json

### "Package restore failed"
- Check internet connection
- Clear NuGet cache: `dotnet nuget locals all --clear`

### Build errors
- Ensure you're in the correct folder
- Run `dotnet restore` first
- Check .NET SDK version: `dotnet --version`

## 📊 Progress Tracking

Use `task.md` in the root folder to track your progress through the lessons!

---

**Happy Learning! 🚀**

You now have everything you need to become proficient in .NET as a mid-level backend engineer. The curriculum is designed to be practical, hands-on, and directly applicable to real-world legacy system maintenance and modern .NET development.
