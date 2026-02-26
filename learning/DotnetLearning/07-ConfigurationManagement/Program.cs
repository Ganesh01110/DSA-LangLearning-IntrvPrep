using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;

var builder = WebApplication.CreateBuilder(args);

// Add services
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

// ===== CONFIGURATION BINDING =====
// Bind configuration sections to strongly-typed classes
// This is similar to Spring's @ConfigurationProperties

builder.Services.Configure<DatabaseSettings>(
    builder.Configuration.GetSection("Database"));

builder.Services.Configure<ApiSettings>(
    builder.Configuration.GetSection("ApiSettings"));

builder.Services.Configure<FeatureSettings>(
    builder.Configuration.GetSection("Features"));

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();
app.UseAuthorization();
app.MapControllers();

Console.WriteLine("🔧 Configuration Management Demo");
Console.WriteLine($"Environment: {app.Environment.EnvironmentName}");
Console.WriteLine("Visit: https://localhost:5001/swagger");
Console.WriteLine("\nTip: Set user secrets with:");
Console.WriteLine("  dotnet user-secrets set \"ApiSettings:ApiKey\" \"your-secret-key\"");

app.Run();

// ===== CONFIGURATION MODELS =====

/// <summary>
/// Database configuration settings
/// Maps to "Database" section in appsettings.json
/// </summary>
public class DatabaseSettings
{
    public string ConnectionString { get; set; } = string.Empty;
    public int Timeout { get; set; }
    public int MaxRetries { get; set; }

    /// <summary>
    /// Validates the configuration
    /// </summary>
    public bool IsValid()
    {
        return !string.IsNullOrEmpty(ConnectionString) && Timeout > 0;
    }
}

/// <summary>
/// API configuration settings
/// Maps to "ApiSettings" section in appsettings.json
/// </summary>
public class ApiSettings
{
    public string BaseUrl { get; set; } = string.Empty;
    public string ApiKey { get; set; } = string.Empty;
    public int Timeout { get; set; }

    /// <summary>
    /// Gets the full API URL with path
    /// </summary>
    public string GetUrl(string path)
    {
        return $"{BaseUrl.TrimEnd('/')}/{path.TrimStart('/')}";
    }
}

/// <summary>
/// Feature flags configuration
/// Maps to "Features" section in appsettings.json
/// </summary>
public class FeatureSettings
{
    public bool EnableCache { get; set; }
    public int CacheExpirationMinutes { get; set; }
    public bool EnableDetailedErrors { get; set; }
}

// ===== CONTROLLER =====

/// <summary>
/// Configuration demonstration controller
/// Shows different ways to access configuration
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class ConfigController : ControllerBase
{
    private readonly IConfiguration _configuration;
    private readonly DatabaseSettings _databaseSettings;
    private readonly ApiSettings _apiSettings;
    private readonly FeatureSettings _featureSettings;
    private readonly ILogger<ConfigController> _logger;

    /// <summary>
    /// Constructor with dependency injection
    /// Demonstrates three ways to access configuration:
    /// 1. IConfiguration (direct access)
    /// 2. IOptions<T> (strongly-typed, snapshot)
    /// 3. IOptionsSnapshot<T> (strongly-typed, per-request)
    /// </summary>
    public ConfigController(
        IConfiguration configuration,
        IOptions<DatabaseSettings> databaseOptions,
        IOptions<ApiSettings> apiOptions,
        IOptions<FeatureSettings> featureOptions,
        ILogger<ConfigController> logger)
    {
        _configuration = configuration;
        _databaseSettings = databaseOptions.Value;
        _apiSettings = apiOptions.Value;
        _featureSettings = featureOptions.Value;
        _logger = logger;
    }

    /// <summary>
    /// GET /api/config
    /// Returns all configuration (be careful in production!)
    /// </summary>
    [HttpGet]
    public IActionResult GetAll()
    {
        _logger.LogInformation("Getting all configuration");

        return Ok(new
        {
            message = "Configuration loaded successfully",
            environment = _configuration["ASPNETCORE_ENVIRONMENT"],
            database = _databaseSettings,
            api = new
            {
                _apiSettings.BaseUrl,
                _apiSettings.Timeout,
                // Don't expose API key!
                apiKeyConfigured = !string.IsNullOrEmpty(_apiSettings.ApiKey)
            },
            features = _featureSettings
        });
    }

    /// <summary>
    /// GET /api/config/database
    /// Returns database configuration
    /// </summary>
    [HttpGet("database")]
    public IActionResult GetDatabaseConfig()
    {
        _logger.LogInformation("Getting database configuration");

        return Ok(new
        {
            settings = _databaseSettings,
            isValid = _databaseSettings.IsValid()
        });
    }

    /// <summary>
    /// GET /api/config/api
    /// Returns API configuration (without sensitive data)
    /// </summary>
    [HttpGet("api")]
    public IActionResult GetApiConfig()
    {
        _logger.LogInformation("Getting API configuration");

        return Ok(new
        {
            baseUrl = _apiSettings.BaseUrl,
            timeout = _apiSettings.Timeout,
            apiKeyConfigured = !string.IsNullOrEmpty(_apiSettings.ApiKey),
            // Example of using helper method
            exampleUrl = _apiSettings.GetUrl("/users")
        });
    }

    /// <summary>
    /// GET /api/config/features
    /// Returns feature flags
    /// </summary>
    [HttpGet("features")]
    public IActionResult GetFeatures()
    {
        _logger.LogInformation("Getting feature flags");

        return Ok(_featureSettings);
    }

    /// <summary>
    /// GET /api/config/direct/{key}
    /// Demonstrates direct configuration access (not recommended)
    /// Example: /api/config/direct/Database:Timeout
    /// </summary>
    [HttpGet("direct/{key}")]
    public IActionResult GetDirect(string key)
    {
        _logger.LogInformation("Getting configuration value for key: {Key}", key);

        // Direct access using IConfiguration (not type-safe)
        var value = _configuration[key];

        if (value == null)
        {
            return NotFound(new { message = $"Configuration key '{key}' not found" });
        }

        return Ok(new
        {
            key = key,
            value = value,
            note = "Direct access is not recommended. Use strongly-typed configuration instead."
        });
    }

    /// <summary>
    /// GET /api/config/validate
    /// Validates all configuration settings
    /// </summary>
    [HttpGet("validate")]
    public IActionResult Validate()
    {
        _logger.LogInformation("Validating configuration");

        var errors = new List<string>();

        // Validate database settings
        if (!_databaseSettings.IsValid())
        {
            errors.Add("Database configuration is invalid");
        }

        // Validate API settings
        if (string.IsNullOrEmpty(_apiSettings.BaseUrl))
        {
            errors.Add("API BaseUrl is not configured");
        }

        if (string.IsNullOrEmpty(_apiSettings.ApiKey))
        {
            errors.Add("API Key is not configured (use user secrets)");
        }

        if (errors.Any())
        {
            return BadRequest(new
            {
                valid = false,
                errors = errors
            });
        }

        return Ok(new
        {
            valid = true,
            message = "All configuration is valid"
        });
    }
}
