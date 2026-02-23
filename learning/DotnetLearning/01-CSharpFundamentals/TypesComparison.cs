using System;

namespace CSharpFundamentals
{
    /// <summary>
    /// Deep dive into value types vs reference types
    /// Critical concept that differs significantly from Java
    /// </summary>
    public class TypesComparison
    {
        public static void RunExamples()
        {
            Console.WriteLine("=== Value Types vs Reference Types ===\n");

            StructVsClassDemo();
            BoxingUnboxingDemo();
            NullableValueTypesDemo();
            RecordStructDemo();
        }

        // ===== STRUCT vs CLASS =====
        static void StructVsClassDemo()
        {
            Console.WriteLine("1. STRUCT (Value Type) vs CLASS (Reference Type)");
            Console.WriteLine("─────────────────────────────────────────────────");

            // Struct - copied by value
            Point p1 = new Point(10, 20);
            Point p2 = p1; // Creates a COPY
            p2.X = 100;

            Console.WriteLine($"Struct - p1.X: {p1.X}, p2.X: {p2.X}");
            Console.WriteLine("p1 and p2 are independent copies\n");

            // Class - copied by reference
            Rectangle r1 = new Rectangle(10, 20);
            Rectangle r2 = r1; // Same REFERENCE
            r2.Width = 100;

            Console.WriteLine($"Class - r1.Width: {r1.Width}, r2.Width: {r2.Width}");
            Console.WriteLine("r1 and r2 point to the same object\n");

            // Performance implications
            Console.WriteLine("When to use:");
            Console.WriteLine("  Struct: Small, immutable data (Point, Color, DateTime)");
            Console.WriteLine("  Class: Complex objects, mutable state, inheritance\n");
        }

        // ===== BOXING AND UNBOXING =====
        static void BoxingUnboxingDemo()
        {
            Console.WriteLine("2. BOXING and UNBOXING");
            Console.WriteLine("──────────────────────");

            // Boxing: value type → reference type (object)
            int number = 42;
            object boxed = number; // Boxing (allocates on heap)

            Console.WriteLine($"Boxed value: {boxed}");

            // Unboxing: reference type → value type
            int unboxed = (int)boxed; // Unboxing (must cast)

            Console.WriteLine($"Unboxed value: {unboxed}");

            // Performance note: Boxing/unboxing has overhead
            // Use generics to avoid: List<int> instead of ArrayList
            Console.WriteLine("\n⚠️  Avoid boxing in performance-critical code");
            Console.WriteLine("   Use List<T> instead of ArrayList\n");
        }

        // ===== NULLABLE VALUE TYPES =====
        static void NullableValueTypesDemo()
        {
            Console.WriteLine("3. NULLABLE VALUE TYPES");
            Console.WriteLine("───────────────────────");

            // Value types cannot be null by default
            // int x = null; // Compile error!

            // Nullable value types (int? is shorthand for Nullable<int>)
            int? nullableInt = null;

            Console.WriteLine($"Has value: {nullableInt.HasValue}");
            Console.WriteLine($"Value: {nullableInt.GetValueOrDefault()}");

            nullableInt = 42;
            Console.WriteLine($"Has value: {nullableInt.HasValue}");
            Console.WriteLine($"Value: {nullableInt.Value}");

            // Null-coalescing operator
            int result = nullableInt ?? 0;
            Console.WriteLine($"Using ??: {result}");

            // Practical example: database fields that can be NULL
            DatabaseRecord record = new DatabaseRecord
            {
                Id = 1,
                Name = "John",
                Age = 30,
                LastLogin = null // No login yet
            };

            Console.WriteLine($"\nDatabase record:");
            Console.WriteLine($"  Last login: {record.LastLogin?.ToString() ?? "Never"}");
            Console.WriteLine();
        }

        // ===== RECORD STRUCT (C# 10+) =====
        static void RecordStructDemo()
        {
            Console.WriteLine("4. RECORD STRUCT (Best of both worlds)");
            Console.WriteLine("──────────────────────────────────────");

            // Record struct: value type + value equality + immutability
            var point1 = new PointRecord(10, 20);
            var point2 = new PointRecord(10, 20);
            var point3 = point1; // Copy

            Console.WriteLine($"point1 == point2: {point1 == point2}"); // True (value equality)
            Console.WriteLine($"point1.Equals(point2): {point1.Equals(point2)}"); // True

            // Immutable - use 'with' to create modified copy
            var movedPoint = point1 with { X = 30 };
            Console.WriteLine($"Original: {point1}, Moved: {movedPoint}");

            Console.WriteLine("\n✅ Record structs are great for DTOs and value objects\n");
        }

        // ===== SUPPORTING TYPES =====

        // Struct (Value Type)
        public struct Point
        {
            public int X { get; set; }
            public int Y { get; set; }

            public Point(int x, int y)
            {
                X = x;
                Y = y;
            }

            public override string ToString() => $"({X}, {Y})";
        }

        // Class (Reference Type)
        public class Rectangle
        {
            public int Width { get; set; }
            public int Height { get; set; }

            public Rectangle(int width, int height)
            {
                Width = width;
                Height = height;
            }

            public override string ToString() => $"{Width}x{Height}";
        }

        // Record Struct (Value Type + Value Equality)
        public readonly record struct PointRecord(int X, int Y);

        // Example database record with nullable fields
        public class DatabaseRecord
        {
            public int Id { get; set; }
            public string Name { get; set; } = string.Empty;
            public int? Age { get; set; }           // Nullable int
            public DateTime? LastLogin { get; set; } // Nullable DateTime
        }
    }

    // ===== COMMON VALUE TYPES IN .NET =====
    public class CommonValueTypes
    {
        public static void ShowCommonTypes()
        {
            Console.WriteLine("Common Value Types in .NET:");
            Console.WriteLine("───────────────────────────");
            Console.WriteLine("  Numeric: int, long, float, double, decimal");
            Console.WriteLine("  Boolean: bool");
            Console.WriteLine("  Character: char");
            Console.WriteLine("  Date/Time: DateTime, TimeSpan, DateTimeOffset");
            Console.WriteLine("  Other: Guid, enum types");
            Console.WriteLine("  All structs you define");
            Console.WriteLine("\nCommon Reference Types:");
            Console.WriteLine("──────────────────────");
            Console.WriteLine("  string (special case - immutable reference type)");
            Console.WriteLine("  object");
            Console.WriteLine("  Arrays: int[], string[]");
            Console.WriteLine("  Collections: List<T>, Dictionary<K,V>");
            Console.WriteLine("  All classes you define");
        }
    }
}
