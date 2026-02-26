# Lesson 07: Configuration Management

## 🎯 Learning Objectives

- Work with appsettings.json
- Use environment-specific configuration
- Bind configuration to strongly-typed objects
- Use user secrets for sensitive data
- Access configuration via dependency injection
- Compare with Spring's application.properties

## 📚 Configuration Sources

Configuration is loaded from multiple sources in priority order (highest to lowest):

```
1. Command-line arguments          (highest priority)
2. Environment variables
3. User secrets (development only)
4. appsettings.{Environment}.json
5. appsettings.json                (lowest priority)
```

**Spring equivalent**: application.properties + application-{profile}.properties

## 🔑 appsettings.json Structure

```json
{
  "Logging": {
    "LogLevel": {
      "Default": "Information",
      "Microsoft.AspNetCore": "Warning"
    }
  },
  "Database": {
    "ConnectionString": "Server=localhost;Database=mydb",
    "Timeout": 30,
    "MaxRetries": 3
  },
  "Features": {
    "EnableCache": true,
    "CacheExpirationMinutes": 60
  },
  "ApiSettings": {
    "BaseUrl": "https://api.example.com",
    "ApiKey": "will-be-overridden-by-secrets",
    "Timeout": 30
  }
}
```

## 💻 Strongly-Typed Configuration

### Define Configuration Classes

```csharp
public class DatabaseSettings
{
    public string ConnectionString { get; set; } = string.Empty;
    public int Timeout { get; set; }
    public int MaxRetries { get; set; }
}

public class ApiSettings
{
    public string BaseUrl { get; set; } = string.Empty;
    public string ApiKey { get; set; } = string.Empty;
    public int Timeout { get; set; }
}
```

### Register and Use

```csharp
// Register (in Program.cs)
builder.Services.Configure<DatabaseSettings>(
    builder.Configuration.GetSection("Database"));

// Use (via dependency injection)
public class MyService
{
    private readonly DatabaseSettings _settings;

    public MyService(IOptions<DatabaseSettings> options)
    {
        _settings = options.Value;
    }
}
```

## 🔒 User Secrets (Development)

Store sensitive data outside of source control:

```bash
# Initialize user secrets
dotnet user-secrets init

# Set a secret
dotnet user-secrets set "ApiSettings:ApiKey" "my-secret-api-key"

# List secrets
dotnet user-secrets list

# Remove a secret
dotnet user-secrets remove "ApiSettings:ApiKey"
```

**Spring equivalent**: application-local.properties (gitignored)

## 🏃 Running the Example

```bash
cd 07-ConfigurationManagement
dotnet run

# Test endpoints:
# GET /api/config - Shows all configuration
# GET /api/config/database - Shows database settings
# GET /api/config/api - Shows API settings
```

## 📝 Code Files

- **Program.cs** - Configuration setup and DI registration
- **Models/DatabaseSettings.cs** - Database configuration model
- **Models/ApiSettings.cs** - API configuration model
- **Models/FeatureSettings.cs** - Feature flags model
- **Controllers/ConfigController.cs** - Demonstrates configuration access
- **appsettings.json** - Base configuration
- **appsettings.Development.json** - Development overrides

## 💡 Configuration Patterns

### 1. IOptions<T> (Snapshot)
```csharp
public MyService(IOptions<Settings> options)
{
    var settings = options.Value; // Snapshot at registration time
}
```

### 2. IOptionsSnapshot<T> (Per-Request)
```csharp
public MyService(IOptionsSnapshot<Settings> options)
{
    var settings = options.Value; // Reloaded per request
}
```

### 3. IOptionsMonitor<T> (Real-Time)
```csharp
public MyService(IOptionsMonitor<Settings> options)
{
    var settings = options.CurrentValue; // Always current
    options.OnChange(newSettings => { /* React to changes */ });
}
```

## 🎓 Best Practices

1. **Use strongly-typed configuration** instead of magic strings
2. **Never commit secrets** to source control
3. **Use user secrets** for local development
4. **Use environment variables** for production
5. **Validate configuration** at startup
6. **Group related settings** into classes

## 🔗 Environment-Specific Configuration

```json
// appsettings.json (base)
{
  "Database": {
    "ConnectionString": "Server=localhost;Database=dev"
  }
}

// appsettings.Production.json (overrides)
{
  "Database": {
    "ConnectionString": "Server=prod-server;Database=prod"
  }
}
```

Set environment:
```bash
# Windows
$env:ASPNETCORE_ENVIRONMENT="Production"

# Linux/Mac
export ASPNETCORE_ENVIRONMENT=Production
```

## ⏭️ Next Lesson

Move to **Lesson 08: Authentication & Authorization** to learn about JWT and security.
