# Lesson 01: C# Fundamentals & Syntax Comparison

## 🎯 Learning Objectives

By the end of this lesson, you will:
- Understand C# syntax and how it differs from Java
- Master properties vs getters/setters
- Use LINQ effectively (vs Java Streams)
- Work with async/await patterns
- Understand value types vs reference types
- Use modern C# features (records, nullable reference types)

## 📚 Prerequisites

- Java programming experience
- Understanding of OOP concepts
- .NET SDK installed

## 🔑 Key Concepts

### 1. Value Types vs Reference Types

**Java**: Everything except primitives is a reference type
**C#**: Has both `struct` (value type) and `class` (reference type)

```csharp
// Value type (stored on stack)
struct Point {
    public int X { get; set; }
    public int Y { get; set; }
}

// Reference type (stored on heap)
class Person {
    public string Name { get; set; }
    public int Age { get; set; }
}
```

### 2. Properties vs Getters/Setters

**Java**:
```java
private String name;
public String getName() { return name; }
public void setName(String name) { this.name = name; }
```

**C#**:
```csharp
public string Name { get; set; }  // Auto-property

// With backing field
private string _name;
public string Name {
    get => _name;
    set => _name = value?.Trim();
}
```

### 3. LINQ vs Java Streams

**Java**:
```java
List<String> names = people.stream()
    .filter(p -> p.getAge() > 18)
    .map(Person::getName)
    .collect(Collectors.toList());
```

**C#**:
```csharp
var names = people
    .Where(p => p.Age > 18)
    .Select(p => p.Name)
    .ToList();
```

### 4. Async/Await vs CompletableFuture

**Java**:
```java
CompletableFuture<String> future = CompletableFuture
    .supplyAsync(() -> fetchData())
    .thenApply(data -> process(data));
```

**C#**:
```csharp
string result = await FetchDataAsync();
string processed = Process(result);
```

### 5. Nullable Reference Types (C# 8.0+)

```csharp
#nullable enable

string nonNullable = "Hello";      // Cannot be null
string? nullable = null;            // Can be null

// Compiler warns if you don't check
if (nullable != null) {
    Console.WriteLine(nullable.Length);
}
```

### 6. Records (C# 9.0+)

**Java**:
```java
public record Person(String name, int age) {}
```

**C#**:
```csharp
public record Person(string Name, int Age);

// Immutable by default, value equality
var p1 = new Person("John", 30);
var p2 = new Person("John", 30);
Console.WriteLine(p1 == p2);  // True!
```

## 🏃 Running the Examples

```bash
cd 01-CSharpFundamentals
dotnet run
```

## 📝 Code Files

- **Program.cs** - Main entry point with examples
- **TypesComparison.cs** - Value vs reference types
- **LinqExamples.cs** - LINQ operations
- **AsyncExamples.cs** - Async/await patterns

## 💻 Exercises

### Exercise 1: Properties
Create a `BankAccount` class with:
- Auto-property for `AccountNumber`
- Property for `Balance` that prevents negative values
- Read-only property for `AccountType`

### Exercise 2: LINQ
Given a list of products, use LINQ to:
- Filter products with price > $50
- Group by category
- Calculate average price per category

### Exercise 3: Async
Create an async method that:
- Fetches data from multiple sources concurrently
- Waits for all to complete
- Combines the results

## 🔗 Key Differences Summary

| Feature | Java | C# |
|---------|------|-----|
| Properties | Getters/Setters | Auto-properties |
| Streams | Stream API | LINQ |
| Async | CompletableFuture | async/await |
| Null Safety | @Nullable annotations | Nullable reference types |
| Records | record keyword (Java 14+) | record keyword (C# 9+) |
| Extension Methods | No | Yes |
| Delegates | Functional interfaces | Delegates, Func, Action |

## 🎓 Best Practices

1. **Use properties** instead of explicit getters/setters
2. **Prefer LINQ** for collection operations
3. **Use async/await** for I/O operations
4. **Enable nullable reference types** in new projects
5. **Use records** for immutable data transfer objects
6. **Leverage extension methods** for cleaner code

## 📖 Additional Resources

- [C# for Java Developers](https://docs.microsoft.com/dotnet/csharp/programming-guide/concepts/)
- [LINQ Documentation](https://docs.microsoft.com/dotnet/csharp/linq/)
- [Async Programming](https://docs.microsoft.com/dotnet/csharp/async)

## ⏭️ Next Lesson

Once you're comfortable with C# syntax, move to **Lesson 02: .NET Ecosystem** to understand the framework landscape.

---

**Pro Tip**: Don't try to memorize everything! Focus on understanding the concepts and refer back to this documentation as needed.
