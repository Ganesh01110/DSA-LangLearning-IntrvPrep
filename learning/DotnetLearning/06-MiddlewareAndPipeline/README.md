# Lesson 06: Middleware & Request Pipeline

## 🎯 Learning Objectives

- Understand the middleware pipeline concept
- Create custom middleware
- Compare with Spring filters/interceptors
- Handle exceptions globally
- Configure middleware order
- Use built-in middleware components

## 📚 Middleware vs Spring Filters

| Spring | ASP.NET Core |
|--------|--------------|
| Filter | Middleware |
| FilterChain | RequestDelegate |
| @Order | Order in Program.cs |
| @ControllerAdvice | Exception middleware |
| HandlerInterceptor | Middleware |

## 🔑 Middleware Pipeline

The middleware pipeline processes every HTTP request. **Order matters!**

```csharp
var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

// Order is critical!
app.UseHttpsRedirection();     // 1. Redirect HTTP to HTTPS
app.UseStaticFiles();          // 2. Serve static files
app.UseRouting();              // 3. Route matching
app.UseAuthentication();       // 4. Authenticate user
app.UseAuthorization();        // 5. Authorize user
app.MapControllers();          // 6. Execute endpoint

app.Run();
```

## 💻 Custom Middleware

### Method 1: Inline Middleware
```csharp
app.Use(async (context, next) =>
{
    // Before next middleware
    Console.WriteLine($"Request: {context.Request.Path}");
    
    await next(); // Call next middleware
    
    // After next middleware
    Console.WriteLine($"Response: {context.Response.StatusCode}");
});
```

### Method 2: Middleware Class
```csharp
public class LoggingMiddleware
{
    private readonly RequestDelegate _next;

    public LoggingMiddleware(RequestDelegate next)
    {
        _next = next;
    }

    public async Task InvokeAsync(HttpContext context)
    {
        // Before
        await _next(context); // Call next
        // After
    }
}

// Register
app.UseMiddleware<LoggingMiddleware>();
```

## 🏃 Running the Example

```bash
cd 06-MiddlewareAndPipeline
dotnet run

# Test the endpoints:
# https://localhost:5001/api/test
# https://localhost:5001/api/test/error (triggers exception)
```

## 📝 Code Files

- **Program.cs** - Main application with middleware pipeline
- **Middleware/LoggingMiddleware.cs** - Request/response logging
- **Middleware/ExceptionMiddleware.cs** - Global exception handling
- **Middleware/TimingMiddleware.cs** - Request timing
- **Controllers/TestController.cs** - Test endpoints

## 💡 Key Concepts

### 1. Middleware Execution Order
Middleware executes in the order it's registered:
- Request flows **down** the pipeline
- Response flows **back up** the pipeline

### 2. Short-Circuiting
Middleware can stop the pipeline by not calling `next()`:
```csharp
if (!context.Request.Headers.ContainsKey("API-Key"))
{
    context.Response.StatusCode = 401;
    return; // Don't call next()
}
```

### 3. Built-in Middleware
- `UseHttpsRedirection()` - Redirect to HTTPS
- `UseStaticFiles()` - Serve static files
- `UseRouting()` - Enable routing
- `UseAuthentication()` - Enable auth
- `UseAuthorization()` - Enable authz
- `UseCors()` - Enable CORS

## � Best Practices

1. **Order matters** - Authentication before Authorization
2. **Use extension methods** for cleaner registration
3. **Handle exceptions early** in the pipeline
4. **Log requests** for debugging
5. **Don't block** - use async/await

## ⏭️ Next Lesson

Move to **Lesson 07: Configuration Management** to learn about appsettings.json and environment-specific configs.
