# Lesson 08: Authentication & Authorization

## 🎯 Learning Objectives

- Implement JWT authentication
- Understand authentication vs authorization
- Use `[Authorize]` and `[AllowAnonymous]` attributes
- Create role-based and policy-based authorization
- Compare with Spring Security
- Secure API endpoints

## 📚 Authentication vs Authorization

| Concept | Description | Spring Equivalent |
|---------|-------------|-------------------|
| **Authentication** | Who are you? | `@EnableWebSecurity` |
| **Authorization** | What can you do? | `@PreAuthorize`, `@Secured` |
| **JWT** | Stateless token | Same (JWT) |
| **Claims** | User properties | `GrantedAuthority` |
| **Roles** | User groups | `ROLE_*` |

## 🔑 JWT (JSON Web Token)

JWT is a compact, self-contained way to securely transmit information between parties.

### Structure
```
Header.Payload.Signature
```

### Example Token
```
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.
eyJzdWIiOiJqb2huQGV4YW1wbGUuY29tIiwicm9sZSI6IkFkbWluIn0.
SflKxwRJSMeKKF2QT4fwpMeJf36POkO6yJV_adQssw5c
```

### Decoded Payload
```json
{
  "sub": "john@example.com",
  "role": "Admin",
  "exp": 1735689600
}
```

## 💻 Implementation

### 1. Configure JWT Authentication

```csharp
builder.Services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options =>
    {
        options.TokenValidationParameters = new TokenValidationParameters
        {
            ValidateIssuer = true,
            ValidateAudience = true,
            ValidateLifetime = true,
            ValidateIssuerSigningKey = true,
            ValidIssuer = "your-app",
            ValidAudience = "your-app",
            IssuerSigningKey = new SymmetricSecurityKey(
                Encoding.UTF8.GetBytes("your-secret-key"))
        };
    });
```

### 2. Generate JWT Token

```csharp
var claims = new[]
{
    new Claim(ClaimTypes.Name, user.Email),
    new Claim(ClaimTypes.Role, user.Role)
};

var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(secretKey));
var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

var token = new JwtSecurityToken(
    issuer: "your-app",
    audience: "your-app",
    claims: claims,
    expires: DateTime.Now.AddHours(1),
    signingCredentials: creds
);

return new JwtSecurityTokenHandler().WriteToken(token);
```

### 3. Protect Endpoints

```csharp
[Authorize] // Requires authentication
public class SecureController : ControllerBase
{
    [Authorize(Roles = "Admin")] // Requires Admin role
    [HttpGet("admin")]
    public IActionResult AdminOnly()
    {
        return Ok("Admin access");
    }

    [AllowAnonymous] // Override [Authorize]
    [HttpGet("public")]
    public IActionResult Public()
    {
        return Ok("Public access");
    }
}
```

## 🔒 Policy-Based Authorization

```csharp
builder.Services.AddAuthorization(options =>
{
    options.AddPolicy("RequireAdmin", policy =>
        policy.RequireRole("Admin"));
    
    options.AddPolicy("MinimumAge", policy =>
        policy.RequireClaim("Age", "18", "19", "20")); // etc.
});

[Authorize(Policy = "RequireAdmin")]
public IActionResult AdminAction() { }
```

## ⏭️ Next Lesson

Move to **Lesson 09: Design Patterns**.
