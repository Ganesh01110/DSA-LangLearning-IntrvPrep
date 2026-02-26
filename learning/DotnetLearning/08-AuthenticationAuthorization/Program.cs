using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;

var builder = WebApplication.CreateBuilder(args);

// Add services
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();

// ===== JWT CONFIGURATION =====
var jwtSettings = builder.Configuration.GetSection("JwtSettings");
var secretKey = jwtSettings["SecretKey"] ?? throw new InvalidOperationException("JWT SecretKey not configured");

builder.Services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options =>
    {
        options.TokenValidationParameters = new TokenValidationParameters
        {
            ValidateIssuer = true,
            ValidateAudience = true,
            ValidateLifetime = true,
            ValidateIssuerSigningKey = true,
            ValidIssuer = jwtSettings["Issuer"],
            ValidAudience = jwtSettings["Audience"],
            IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(secretKey)),
            ClockSkew = TimeSpan.Zero // Remove default 5 minute tolerance
        };
    });

// ===== AUTHORIZATION POLICIES =====
builder.Services.AddAuthorization(options =>
{
    // Policy-based authorization
    options.AddPolicy("RequireAdminRole", policy => policy.RequireRole("Admin"));
    options.AddPolicy("RequireUserRole", policy => policy.RequireRole("User"));
    options.AddPolicy("RequireAnyRole", policy => policy.RequireRole("Admin", "User"));
});

// ===== SWAGGER WITH JWT SUPPORT =====
builder.Services.AddSwaggerGen(c =>
{
    c.SwaggerDoc("v1", new OpenApiInfo { Title = "JWT Auth Demo", Version = "v1" });

    // Add JWT authentication to Swagger
    c.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
    {
        Description = "JWT Authorization header using the Bearer scheme. Enter 'Bearer' [space] and then your token",
        Name = "Authorization",
        In = ParameterLocation.Header,
        Type = SecuritySchemeType.ApiKey,
        Scheme = "Bearer"
    });

    c.AddSecurityRequirement(new OpenApiSecurityRequirement
    {
        {
            new OpenApiSecurityScheme
            {
                Reference = new OpenApiReference
                {
                    Type = ReferenceType.SecurityScheme,
                    Id = "Bearer"
                }
            },
            Array.Empty<string>()
        }
    });
});

// Register services
builder.Services.AddSingleton<TokenService>();

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

// IMPORTANT: Order matters!
app.UseAuthentication(); // Must come before UseAuthorization
app.UseAuthorization();

app.MapControllers();

Console.WriteLine("🔐 JWT Authentication Demo");
Console.WriteLine("Visit: https://localhost:5001/swagger");
Console.WriteLine("\n📝 Test Users:");
Console.WriteLine("  Admin: admin@example.com / admin123");
Console.WriteLine("  User:  user@example.com / user123");
Console.WriteLine("\n🔑 Steps:");
Console.WriteLine("  1. POST /api/auth/login to get token");
Console.WriteLine("  2. Click 'Authorize' in Swagger");
Console.WriteLine("  3. Enter: Bearer <your-token>");
Console.WriteLine("  4. Try protected endpoints");

app.Run();

// ===== TOKEN SERVICE =====

/// <summary>
/// Service for generating and validating JWT tokens
/// </summary>
public class TokenService
{
    private readonly IConfiguration _configuration;

    public TokenService(IConfiguration configuration)
    {
        _configuration = configuration;
    }

    /// <summary>
    /// Generates a JWT token for the given user
    /// </summary>
    public string GenerateToken(User user)
    {
        var jwtSettings = _configuration.GetSection("JwtSettings");
        var secretKey = jwtSettings["SecretKey"] ?? throw new InvalidOperationException("JWT SecretKey not configured");

        // Create claims (user information stored in token)
        var claims = new[]
        {
            new Claim(ClaimTypes.NameIdentifier, user.Id.ToString()),
            new Claim(ClaimTypes.Name, user.Email),
            new Claim(ClaimTypes.Email, user.Email),
            new Claim(ClaimTypes.Role, user.Role),
            new Claim("FullName", user.FullName),
            new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString()) // Unique token ID
        };

        // Create signing credentials
        var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(secretKey));
        var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

        // Create token
        var token = new JwtSecurityToken(
            issuer: jwtSettings["Issuer"],
            audience: jwtSettings["Audience"],
            claims: claims,
            expires: DateTime.UtcNow.AddHours(1), // Token expires in 1 hour
            signingCredentials: creds
        );

        // Return serialized token
        return new JwtSecurityTokenHandler().WriteToken(token);
    }
}

// ===== MODELS =====

public class User
{
    public int Id { get; set; }
    public string Email { get; set; } = string.Empty;
    public string Password { get; set; } = string.Empty; // In real app, hash this!
    public string FullName { get; set; } = string.Empty;
    public string Role { get; set; } = string.Empty; // "Admin" or "User"
}

public class LoginRequest
{
    public string Email { get; set; } = string.Empty;
    public string Password { get; set; } = string.Empty;
}

public class LoginResponse
{
    public string Token { get; set; } = string.Empty;
    public string Email { get; set; } = string.Empty;
    public string Role { get; set; } = string.Empty;
    public DateTime ExpiresAt { get; set; }
}

// ===== CONTROLLERS =====

/// <summary>
/// Authentication controller - handles login and token generation
/// Similar to Spring's @RestController with @PostMapping("/login")
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class AuthController : ControllerBase
{
    private readonly TokenService _tokenService;
    private readonly ILogger<AuthController> _logger;

    // Mock user database (in real app, use database!)
    private static readonly List<User> Users = new()
    {
        new User { Id = 1, Email = "admin@example.com", Password = "admin123", FullName = "Admin User", Role = "Admin" },
        new User { Id = 2, Email = "user@example.com", Password = "user123", FullName = "Regular User", Role = "User" }
    };

    public AuthController(TokenService tokenService, ILogger<AuthController> logger)
    {
        _tokenService = tokenService;
        _logger = logger;
    }

    /// <summary>
    /// POST /api/auth/login
    /// Authenticates user and returns JWT token
    /// </summary>
    [HttpPost("login")]
    [AllowAnonymous] // This endpoint doesn't require authentication
    public IActionResult Login([FromBody] LoginRequest request)
    {
        _logger.LogInformation("Login attempt for: {Email}", request.Email);

        // Find user (in real app, query database)
        var user = Users.FirstOrDefault(u =>
            u.Email == request.Email && u.Password == request.Password);

        if (user == null)
        {
            _logger.LogWarning("Login failed for: {Email}", request.Email);
            return Unauthorized(new { message = "Invalid email or password" });
        }

        // Generate JWT token
        var token = _tokenService.GenerateToken(user);

        _logger.LogInformation("Login successful for: {Email} (Role: {Role})", user.Email, user.Role);

        return Ok(new LoginResponse
        {
            Token = token,
            Email = user.Email,
            Role = user.Role,
            ExpiresAt = DateTime.UtcNow.AddHours(1)
        });
    }

    /// <summary>
    /// GET /api/auth/me
    /// Returns current authenticated user's information
    /// Requires authentication
    /// </summary>
    [HttpGet("me")]
    [Authorize] // Requires valid JWT token
    public IActionResult GetCurrentUser()
    {
        // Extract claims from JWT token
        var email = User.FindFirst(ClaimTypes.Email)?.Value;
        var role = User.FindFirst(ClaimTypes.Role)?.Value;
        var fullName = User.FindFirst("FullName")?.Value;

        return Ok(new
        {
            email = email,
            role = role,
            fullName = fullName,
            claims = User.Claims.Select(c => new { c.Type, c.Value })
        });
    }
}

/// <summary>
/// Secure controller - demonstrates different authorization levels
/// Similar to Spring's @PreAuthorize and @Secured
/// </summary>
[ApiController]
[Route("api/[controller]")]
[Authorize] // All endpoints require authentication by default
public class SecureController : ControllerBase
{
    private readonly ILogger<SecureController> _logger;

    public SecureController(ILogger<SecureController> logger)
    {
        _logger = logger;
    }

    /// <summary>
    /// GET /api/secure
    /// Requires authentication (any role)
    /// </summary>
    [HttpGet]
    public IActionResult Get()
    {
        var email = User.FindFirst(ClaimTypes.Email)?.Value;
        _logger.LogInformation("Authenticated user {Email} accessed secure endpoint", email);

        return Ok(new
        {
            message = "You are authenticated!",
            user = email,
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// GET /api/secure/admin
    /// Requires Admin role
    /// Similar to Spring's @PreAuthorize("hasRole('ADMIN')")
    /// </summary>
    [HttpGet("admin")]
    [Authorize(Roles = "Admin")]
    public IActionResult AdminOnly()
    {
        _logger.LogInformation("Admin accessed admin-only endpoint");

        return Ok(new
        {
            message = "Welcome, Admin!",
            secretData = "Only admins can see this",
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// GET /api/secure/user
    /// Requires User role
    /// </summary>
    [HttpGet("user")]
    [Authorize(Roles = "User")]
    public IActionResult UserOnly()
    {
        _logger.LogInformation("User accessed user-only endpoint");

        return Ok(new
        {
            message = "Welcome, User!",
            userData = "Only users can see this",
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// GET /api/secure/any
    /// Requires Admin OR User role
    /// </summary>
    [HttpGet("any")]
    [Authorize(Roles = "Admin,User")]
    public IActionResult AnyRole()
    {
        var role = User.FindFirst(ClaimTypes.Role)?.Value;
        _logger.LogInformation("User with role {Role} accessed any-role endpoint", role);

        return Ok(new
        {
            message = "You have a valid role!",
            yourRole = role,
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// GET /api/secure/public
    /// Public endpoint (overrides class-level [Authorize])
    /// </summary>
    [HttpGet("public")]
    [AllowAnonymous]
    public IActionResult Public()
    {
        _logger.LogInformation("Public endpoint accessed");

        return Ok(new
        {
            message = "This is public, no authentication required!",
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// GET /api/secure/policy
    /// Uses policy-based authorization
    /// </summary>
    [HttpGet("policy")]
    [Authorize(Policy = "RequireAdminRole")]
    public IActionResult PolicyBased()
    {
        return Ok(new
        {
            message = "You passed the policy check!",
            policy = "RequireAdminRole"
        });
    }
}
