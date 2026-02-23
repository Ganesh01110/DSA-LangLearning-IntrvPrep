using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpFundamentals
{
    /// <summary>
    /// Comprehensive LINQ examples with Java Stream API comparisons
    /// </summary>
    public class LinqExamples
    {
        public static void RunExamples()
        {
            Console.WriteLine("=== LINQ Examples (vs Java Streams) ===\n");

            FilteringExamples();
            MappingExamples();
            AggregationExamples();
            GroupingExamples();
            JoiningExamples();
            QuerySyntaxVsMethodSyntax();
        }

        // ===== FILTERING =====
        static void FilteringExamples()
        {
            Console.WriteLine("1. FILTERING");
            Console.WriteLine("───────────");

            var numbers = Enumerable.Range(1, 20).ToList();

            // Java: numbers.stream().filter(n -> n % 2 == 0).collect(Collectors.toList())
            var evenNumbers = numbers.Where(n => n % 2 == 0).ToList();
            Console.WriteLine($"Even numbers: {string.Join(", ", evenNumbers)}");

            // Multiple conditions
            var filtered = numbers
                .Where(n => n > 5)
                .Where(n => n < 15)
                .ToList();
            Console.WriteLine($"Between 5 and 15: {string.Join(", ", filtered)}");

            // OfType - filter by type
            object[] mixed = { 1, "hello", 2, "world", 3.14, 42 };
            var integers = mixed.OfType<int>().ToList();
            Console.WriteLine($"Only integers: {string.Join(", ", integers)}\n");
        }

        // ===== MAPPING =====
        static void MappingExamples()
        {
            Console.WriteLine("2. MAPPING (Select)");
            Console.WriteLine("───────────────────");

            var people = GetSamplePeople();

            // Java: people.stream().map(Person::getName).collect(Collectors.toList())
            var names = people.Select(p => p.Name).ToList();
            Console.WriteLine($"Names: {string.Join(", ", names)}");

            // Map to anonymous type
            var summary = people.Select(p => new
            {
                p.Name,
                AgeGroup = p.Age < 30 ? "Young" : "Senior"
            }).ToList();

            foreach (var item in summary)
            {
                Console.WriteLine($"{item.Name}: {item.AgeGroup}");
            }

            // SelectMany - flatten nested collections (like flatMap)
            var departments = new[]
            {
                new { Name = "IT", Employees = new[] { "Alice", "Bob" } },
                new { Name = "HR", Employees = new[] { "Charlie", "Diana" } }
            };

            var allEmployees = departments.SelectMany(d => d.Employees).ToList();
            Console.WriteLine($"All employees: {string.Join(", ", allEmployees)}\n");
        }

        // ===== AGGREGATION =====
        static void AggregationExamples()
        {
            Console.WriteLine("3. AGGREGATION");
            Console.WriteLine("──────────────");

            var numbers = new[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            Console.WriteLine($"Sum: {numbers.Sum()}");
            Console.WriteLine($"Average: {numbers.Average():F2}");
            Console.WriteLine($"Min: {numbers.Min()}");
            Console.WriteLine($"Max: {numbers.Max()}");
            Console.WriteLine($"Count: {numbers.Count()}");

            var people = GetSamplePeople();
            Console.WriteLine($"Average age: {people.Average(p => p.Age):F1}");
            Console.WriteLine($"Oldest person: {people.Max(p => p.Age)}");

            // Any, All (like anyMatch, allMatch)
            Console.WriteLine($"Any adults? {people.Any(p => p.Age >= 18)}");
            Console.WriteLine($"All adults? {people.All(p => p.Age >= 18)}");

            // Custom aggregation with Aggregate (like reduce)
            var product = numbers.Aggregate(1, (acc, n) => acc * n);
            Console.WriteLine($"Product of all: {product}\n");
        }

        // ===== GROUPING =====
        static void GroupingExamples()
        {
            Console.WriteLine("4. GROUPING");
            Console.WriteLine("───────────");

            var people = GetSamplePeople();

            // Java: people.stream().collect(Collectors.groupingBy(Person::getDepartment))
            var byDepartment = people.GroupBy(p => p.Department);

            foreach (var group in byDepartment)
            {
                Console.WriteLine($"{group.Key}: {string.Join(", ", group.Select(p => p.Name))}");
            }

            // Group and aggregate
            var avgAgeByDept = people
                .GroupBy(p => p.Department)
                .Select(g => new
                {
                    Department = g.Key,
                    AverageAge = g.Average(p => p.Age),
                    Count = g.Count()
                });

            Console.WriteLine("\nAverage age by department:");
            foreach (var item in avgAgeByDept)
            {
                Console.WriteLine($"{item.Department}: {item.AverageAge:F1} ({item.Count} people)");
            }
            Console.WriteLine();
        }

        // ===== JOINING =====
        static void JoiningExamples()
        {
            Console.WriteLine("5. JOINING");
            Console.WriteLine("──────────");

            var employees = new[]
            {
                new { Id = 1, Name = "Alice", DeptId = 10 },
                new { Id = 2, Name = "Bob", DeptId = 20 },
                new { Id = 3, Name = "Charlie", DeptId = 10 }
            };

            var departments = new[]
            {
                new { Id = 10, Name = "IT" },
                new { Id = 20, Name = "HR" }
            };

            // Inner join
            var joined = employees.Join(
                departments,
                emp => emp.DeptId,
                dept => dept.Id,
                (emp, dept) => new { emp.Name, Department = dept.Name }
            );

            foreach (var item in joined)
            {
                Console.WriteLine($"{item.Name} works in {item.Department}");
            }
            Console.WriteLine();
        }

        // ===== QUERY SYNTAX vs METHOD SYNTAX =====
        static void QuerySyntaxVsMethodSyntax()
        {
            Console.WriteLine("6. QUERY SYNTAX vs METHOD SYNTAX");
            Console.WriteLine("─────────────────────────────────");

            var people = GetSamplePeople();

            // Method syntax (what we've been using)
            var method = people
                .Where(p => p.Age > 25)
                .OrderBy(p => p.Name)
                .Select(p => p.Name)
                .ToList();

            // Query syntax (SQL-like, less common but useful for complex queries)
            var query = (from p in people
                         where p.Age > 25
                         orderby p.Name
                         select p.Name).ToList();

            Console.WriteLine("Method syntax result:");
            Console.WriteLine(string.Join(", ", method));

            Console.WriteLine("\nQuery syntax result:");
            Console.WriteLine(string.Join(", ", query));

            // Complex query with join (query syntax is cleaner here)
            var employees = new[]
            {
                new { Name = "Alice", DeptId = 1 },
                new { Name = "Bob", DeptId = 2 }
            };

            var departments = new[]
            {
                new { Id = 1, Name = "IT" },
                new { Id = 2, Name = "HR" }
            };

            var complexQuery = from emp in employees
                               join dept in departments on emp.DeptId equals dept.Id
                               where dept.Name == "IT"
                               select new { emp.Name, DepartmentName = dept.Name };

            Console.WriteLine("\nComplex query with join:");
            foreach (var item in complexQuery)
            {
                Console.WriteLine($"{item.Name} in {item.DepartmentName}");
            }
        }

        // ===== HELPER METHODS =====
        static List<Person> GetSamplePeople()
        {
            return new List<Person>
            {
                new Person { Name = "Alice", Age = 28, Department = "IT" },
                new Person { Name = "Bob", Age = 35, Department = "HR" },
                new Person { Name = "Charlie", Age = 22, Department = "IT" },
                new Person { Name = "Diana", Age = 31, Department = "Finance" },
                new Person { Name = "Eve", Age = 26, Department = "IT" },
                new Person { Name = "Frank", Age = 40, Department = "HR" }
            };
        }

        class Person
        {
            public string Name { get; set; } = string.Empty;
            public int Age { get; set; }
            public string Department { get; set; } = string.Empty;
        }
    }
}
