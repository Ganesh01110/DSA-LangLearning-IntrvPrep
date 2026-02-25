using Microsoft.AspNetCore.Mvc;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

// Configure the HTTP request pipeline
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

// ===== MIDDLEWARE PIPELINE =====
// Order is CRITICAL! Each middleware processes the request in order,
// then processes the response in reverse order.

// 1. Exception handling middleware (should be first to catch all errors)
app.UseMiddleware<ExceptionMiddleware>();

// 2. Request timing middleware (measures total request time)
app.UseMiddleware<TimingMiddleware>();

// 3. Logging middleware (logs all requests)
app.UseMiddleware<LoggingMiddleware>();

// 4. Built-in middleware
app.UseHttpsRedirection();  // Redirect HTTP to HTTPS
app.UseRouting();           // Enable routing

// 5. Authentication & Authorization (if needed)
// app.UseAuthentication();
// app.UseAuthorization();

// 6. Map controllers (execute endpoints)
app.MapControllers();

Console.WriteLine("🚀 Middleware Pipeline Demo");
Console.WriteLine("Visit: https://localhost:5001/swagger");
Console.WriteLine("Test endpoints:");
Console.WriteLine("  GET /api/test - Normal request");
Console.WriteLine("  GET /api/test/error - Triggers exception");
Console.WriteLine("  GET /api/test/slow - Slow request (2 seconds)");

app.Run();

// ===== MIDDLEWARE CLASSES =====

/// <summary>
/// Logging Middleware - Logs all incoming requests and outgoing responses
/// Similar to Spring's HandlerInterceptor
/// </summary>
public class LoggingMiddleware
{
    private readonly RequestDelegate _next;
    private readonly ILogger<LoggingMiddleware> _logger;

    public LoggingMiddleware(RequestDelegate next, ILogger<LoggingMiddleware> logger)
    {
        _next = next;
        _logger = logger;
    }

    public async Task InvokeAsync(HttpContext context)
    {
        // BEFORE: Log incoming request
        _logger.LogInformation(
            "📥 Request: {Method} {Path} from {IP}",
            context.Request.Method,
            context.Request.Path,
            context.Connection.RemoteIpAddress
        );

        // Call the next middleware in the pipeline
        await _next(context);

        // AFTER: Log outgoing response
        _logger.LogInformation(
            "📤 Response: {StatusCode} for {Method} {Path}",
            context.Response.StatusCode,
            context.Request.Method,
            context.Request.Path
        );
    }
}

/// <summary>
/// Exception Middleware - Global exception handler
/// Similar to Spring's @ControllerAdvice with @ExceptionHandler
/// </summary>
public class ExceptionMiddleware
{
    private readonly RequestDelegate _next;
    private readonly ILogger<ExceptionMiddleware> _logger;

    public ExceptionMiddleware(RequestDelegate next, ILogger<ExceptionMiddleware> logger)
    {
        _next = next;
        _logger = logger;
    }

    public async Task InvokeAsync(HttpContext context)
    {
        try
        {
            // Try to execute the rest of the pipeline
            await _next(context);
        }
        catch (Exception ex)
        {
            // Catch any unhandled exceptions
            _logger.LogError(ex, "❌ Unhandled exception occurred");

            // Set response
            context.Response.StatusCode = 500;
            context.Response.ContentType = "application/json";

            var errorResponse = new
            {
                error = "Internal Server Error",
                message = ex.Message,
                timestamp = DateTime.UtcNow
            };

            await context.Response.WriteAsJsonAsync(errorResponse);
        }
    }
}

/// <summary>
/// Timing Middleware - Measures request processing time
/// Useful for performance monitoring
/// </summary>
public class TimingMiddleware
{
    private readonly RequestDelegate _next;
    private readonly ILogger<TimingMiddleware> _logger;

    public TimingMiddleware(RequestDelegate next, ILogger<TimingMiddleware> logger)
    {
        _next = next;
        _logger = logger;
    }

    public async Task InvokeAsync(HttpContext context)
    {
        // Start timing
        var stopwatch = System.Diagnostics.Stopwatch.StartNew();

        // Execute the rest of the pipeline
        await _next(context);

        // Stop timing
        stopwatch.Stop();

        // Log the elapsed time
        _logger.LogInformation(
            "⏱️  Request {Method} {Path} took {ElapsedMs}ms",
            context.Request.Method,
            context.Request.Path,
            stopwatch.ElapsedMilliseconds
        );

        // Add timing header to response
        context.Response.Headers["X-Response-Time"] = $"{stopwatch.ElapsedMilliseconds}ms";
    }
}

// ===== TEST CONTROLLER =====

/// <summary>
/// Test controller to demonstrate middleware behavior
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class TestController : ControllerBase
{
    private readonly ILogger<TestController> _logger;

    public TestController(ILogger<TestController> logger)
    {
        _logger = logger;
    }

    /// <summary>
    /// Normal endpoint - returns success
    /// </summary>
    [HttpGet]
    public IActionResult Get()
    {
        _logger.LogInformation("✅ Test endpoint called");
        return Ok(new
        {
            message = "Success! Check the console to see middleware logs.",
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// Error endpoint - throws exception to test exception middleware
    /// </summary>
    [HttpGet("error")]
    public IActionResult GetError()
    {
        _logger.LogWarning("⚠️  About to throw an exception");
        throw new InvalidOperationException("This is a test exception!");
    }

    /// <summary>
    /// Slow endpoint - simulates slow processing to test timing middleware
    /// </summary>
    [HttpGet("slow")]
    public async Task<IActionResult> GetSlow()
    {
        _logger.LogInformation("🐌 Slow endpoint - simulating 2 second delay");
        await Task.Delay(2000); // Simulate slow operation
        return Ok(new
        {
            message = "Slow operation completed. Check X-Response-Time header!",
            timestamp = DateTime.UtcNow
        });
    }

    /// <summary>
    /// Headers endpoint - shows request headers
    /// </summary>
    [HttpGet("headers")]
    public IActionResult GetHeaders()
    {
        var headers = Request.Headers
            .ToDictionary(h => h.Key, h => h.Value.ToString());

        return Ok(new
        {
            message = "Request headers",
            headers = headers
        });
    }
}
