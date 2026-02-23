using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CSharpFundamentals
{
    class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("=== C# Fundamentals for Java Developers ===\n");

            // 1. Properties Demo
            Console.WriteLine("1. PROPERTIES vs GETTERS/SETTERS");
            Console.WriteLine("─────────────────────────────────────");
            PropertiesDemo();

            // 2. Value vs Reference Types
            Console.WriteLine("\n2. VALUE TYPES vs REFERENCE TYPES");
            Console.WriteLine("─────────────────────────────────────");
            ValueVsReferenceDemo();

            // 3. LINQ Demo
            Console.WriteLine("\n3. LINQ vs JAVA STREAMS");
            Console.WriteLine("─────────────────────────────────────");
            LinqDemo();

            // 4. Async/Await Demo
            Console.WriteLine("\n4. ASYNC/AWAIT vs COMPLETABLE FUTURE");
            Console.WriteLine("─────────────────────────────────────");
            await AsyncDemo();

            // 5. Nullable Reference Types
            Console.WriteLine("\n5. NULLABLE REFERENCE TYPES");
            Console.WriteLine("─────────────────────────────────────");
            NullableDemo();

            // 6. Records
            Console.WriteLine("\n6. RECORDS (Immutable Data)");
            Console.WriteLine("─────────────────────────────────────");
            RecordsDemo();

            // 7. Extension Methods
            Console.WriteLine("\n7. EXTENSION METHODS");
            Console.WriteLine("─────────────────────────────────────");
            ExtensionMethodsDemo();

            Console.WriteLine("\n✅ All examples completed!");
            Console.WriteLine("\nNext: Explore TypesComparison.cs, LinqExamples.cs, and AsyncExamples.cs");
        }

        // ===== 1. PROPERTIES DEMO =====
        static void PropertiesDemo()
        {
            var person = new Person
            {
                Name = "John Doe",
                Age = 30,
                Email = "john@example.com"
            };

            Console.WriteLine($"Person: {person.Name}, Age: {person.Age}");
            Console.WriteLine($"Email: {person.Email}");
            Console.WriteLine($"Is Adult: {person.IsAdult}"); // Computed property

            // Try to set negative age (validation in setter)
            person.Age = -5; // Will be set to 0
            Console.WriteLine($"After setting negative age: {person.Age}");
        }

        // ===== 2. VALUE VS REFERENCE TYPES =====
        static void ValueVsReferenceDemo()
        {
            // Value type (struct) - copied by value
            Point p1 = new Point { X = 10, Y = 20 };
            Point p2 = p1; // Creates a copy
            p2.X = 100;

            Console.WriteLine($"p1.X = {p1.X}, p2.X = {p2.X}"); // p1.X is still 10

            // Reference type (class) - copied by reference
            Person person1 = new Person { Name = "Alice" };
            Person person2 = person1; // Same reference
            person2.Name = "Bob";

            Console.WriteLine($"person1.Name = {person1.Name}"); // Also "Bob"
        }

        // ===== 3. LINQ DEMO =====
        static void LinqDemo()
        {
            var numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            // Filter and transform (like Java Streams)
            var evenSquares = numbers
                .Where(n => n % 2 == 0)      // filter
                .Select(n => n * n)           // map
                .ToList();

            Console.WriteLine($"Even squares: {string.Join(", ", evenSquares)}");

            // More complex example with objects
            var people = new List<Person>
            {
                new Person { Name = "Alice", Age = 25 },
                new Person { Name = "Bob", Age = 30 },
                new Person { Name = "Charlie", Age = 17 },
                new Person { Name = "Diana", Age = 35 }
            };

            var adultNames = people
                .Where(p => p.Age >= 18)
                .OrderBy(p => p.Name)
                .Select(p => p.Name)
                .ToList();

            Console.WriteLine($"Adults: {string.Join(", ", adultNames)}");

            // Aggregation
            var averageAge = people.Average(p => p.Age);
            Console.WriteLine($"Average age: {averageAge:F1}");
        }

        // ===== 4. ASYNC/AWAIT DEMO =====
        static async Task AsyncDemo()
        {
            Console.WriteLine("Starting async operations...");

            // Sequential async calls
            var data1 = await FetchDataAsync("API 1", 1000);
            Console.WriteLine($"Received: {data1}");

            // Parallel async calls (like CompletableFuture.allOf)
            var task1 = FetchDataAsync("API 2", 500);
            var task2 = FetchDataAsync("API 3", 800);
            var task3 = FetchDataAsync("API 4", 300);

            var results = await Task.WhenAll(task1, task2, task3);
            Console.WriteLine($"All results: {string.Join(", ", results)}");
        }

        static async Task<string> FetchDataAsync(string source, int delayMs)
        {
            await Task.Delay(delayMs); // Simulate network call
            return $"Data from {source}";
        }

        // ===== 5. NULLABLE REFERENCE TYPES =====
        static void NullableDemo()
        {
            // Non-nullable (compiler warns if you try to assign null)
            string nonNullable = "Hello";
            Console.WriteLine($"Non-nullable value: {nonNullable}");

            // Nullable (explicitly allows null)
            string? nullable = null;

            // Safe navigation
            Console.WriteLine($"Length: {nullable?.Length ?? 0}");

            // Null-forgiving operator (use with caution!)
            // string value = nullable!; // Tells compiler "I know it's not null"

            // Better: null check
            if (nullable != null)
            {
                Console.WriteLine($"Not null: {nullable.Length}");
            }
            else
            {
                Console.WriteLine("Value is null");
            }
        }

        // ===== 6. RECORDS DEMO =====
        static void RecordsDemo()
        {
            // Records provide value equality by default
            var product1 = new Product("Laptop", 999.99m);
            var product2 = new Product("Laptop", 999.99m);
            var product3 = new Product("Mouse", 29.99m);

            Console.WriteLine($"product1 == product2: {product1 == product2}"); // True!
            Console.WriteLine($"product1 == product3: {product1 == product3}"); // False

            // Records are immutable by default - use 'with' to create modified copy
            var discountedProduct = product1 with { Price = 899.99m };
            Console.WriteLine($"Original: {product1.Price}, Discounted: {discountedProduct.Price}");
        }

        // ===== 7. EXTENSION METHODS =====
        static void ExtensionMethodsDemo()
        {
            string text = "hello world";

            // Using extension method (defined in StringExtensions class below)
            string capitalized = text.Capitalize();
            Console.WriteLine($"Capitalized: {capitalized}");

            // Chain extension methods
            var result = "  hello  ".Capitalize().Trim();
            Console.WriteLine($"Chained: '{result}'");
        }
    }

    // ===== SUPPORTING CLASSES =====

    // Class (Reference Type)
    class Person
    {
        // Auto-properties (like Java with Lombok)
        public string Name { get; set; } = string.Empty;

        // Property with validation
        private int _age;
        public int Age
        {
            get => _age;
            set => _age = value < 0 ? 0 : value; // Prevent negative age
        }

        public string Email { get; set; } = string.Empty;

        // Computed property (read-only)
        public bool IsAdult => Age >= 18;

        // Expression-bodied property
        public string DisplayName => $"{Name} ({Age})";
    }

    // Struct (Value Type)
    struct Point
    {
        public int X { get; set; }
        public int Y { get; set; }

        // Structs can have methods too
        public double DistanceFromOrigin()
        {
            return Math.Sqrt(X * X + Y * Y);
        }
    }

    // Record (Immutable by default, value equality)
    record Product(string Name, decimal Price);

    // Extension Methods (add methods to existing types)
    static class StringExtensions
    {
        // This method can be called on any string
        public static string Capitalize(this string input)
        {
            if (string.IsNullOrEmpty(input))
                return input;

            return char.ToUpper(input[0]) + input.Substring(1);
        }

        public static bool IsValidEmail(this string email)
        {
            return email.Contains("@") && email.Contains(".");
        }
    }
}
