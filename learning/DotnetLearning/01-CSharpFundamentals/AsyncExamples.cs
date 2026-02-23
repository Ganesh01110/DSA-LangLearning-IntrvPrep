using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;

namespace CSharpFundamentals
{
    /// <summary>
    /// Async/Await examples with CompletableFuture comparisons
    /// </summary>
    public class AsyncExamples
    {
        public static async Task RunExamples()
        {
            Console.WriteLine("=== Async/Await Examples (vs CompletableFuture) ===\n");

            await BasicAsyncExample();
            await ParallelExecutionExample();
            await ErrorHandlingExample();
            await CancellationExample();
        }

        // ===== BASIC ASYNC/AWAIT =====
        static async Task BasicAsyncExample()
        {
            Console.WriteLine("1. BASIC ASYNC/AWAIT");
            Console.WriteLine("────────────────────");

            /*
             * Java equivalent:
             * CompletableFuture<String> future = CompletableFuture
             *     .supplyAsync(() -> fetchData())
             *     .thenApply(data -> process(data));
             * String result = future.get();
             */

            // C# version - much cleaner!
            string data = await FetchDataAsync("https://api.example.com/data");
            string processed = ProcessData(data);

            Console.WriteLine($"Processed: {processed}");
            Console.WriteLine();
        }

        // ===== PARALLEL EXECUTION =====
        static async Task ParallelExecutionExample()
        {
            Console.WriteLine("2. PARALLEL EXECUTION");
            Console.WriteLine("─────────────────────");

            /*
             * Java equivalent:
             * CompletableFuture<String> f1 = CompletableFuture.supplyAsync(() -> fetch1());
             * CompletableFuture<String> f2 = CompletableFuture.supplyAsync(() -> fetch2());
             * CompletableFuture<String> f3 = CompletableFuture.supplyAsync(() -> fetch3());
             * CompletableFuture.allOf(f1, f2, f3).join();
             */

            Console.WriteLine("Starting 3 parallel operations...");
            var startTime = DateTime.Now;

            // Start all tasks concurrently
            Task<string> task1 = FetchDataAsync("API-1", delayMs: 1000);
            Task<string> task2 = FetchDataAsync("API-2", delayMs: 1500);
            Task<string> task3 = FetchDataAsync("API-3", delayMs: 800);

            // Wait for all to complete
            string[] results = await Task.WhenAll(task1, task2, task3);

            var elapsed = (DateTime.Now - startTime).TotalMilliseconds;

            Console.WriteLine($"Results: {string.Join(", ", results)}");
            Console.WriteLine($"Total time: {elapsed:F0}ms (should be ~1500ms, not 3300ms)\n");
        }

        // ===== ERROR HANDLING =====
        static async Task ErrorHandlingExample()
        {
            Console.WriteLine("3. ERROR HANDLING");
            Console.WriteLine("─────────────────");

            try
            {
                // This will throw an exception
                await FetchDataWithErrorAsync();
            }
            catch (HttpRequestException ex)
            {
                Console.WriteLine($"Caught exception: {ex.Message}");
            }

            // Handle multiple tasks with errors
            var tasks = new[]
            {
                SafeFetchAsync("API-1", shouldFail: false),
                SafeFetchAsync("API-2", shouldFail: true),
                SafeFetchAsync("API-3", shouldFail: false)
            };

            var results = await Task.WhenAll(tasks);

            Console.WriteLine("Results from multiple tasks:");
            foreach (var result in results)
            {
                Console.WriteLine($"  {result}");
            }
            Console.WriteLine();
        }

        // ===== CANCELLATION =====
        static async Task CancellationExample()
        {
            Console.WriteLine("4. CANCELLATION");
            Console.WriteLine("───────────────");

            var cts = new System.Threading.CancellationTokenSource();

            // Cancel after 500ms
            cts.CancelAfter(500);

            try
            {
                // This operation takes 2 seconds, but will be cancelled
                await LongRunningOperationAsync(cts.Token);
                Console.WriteLine("Operation completed");
            }
            catch (OperationCanceledException)
            {
                Console.WriteLine("Operation was cancelled");
            }
            Console.WriteLine();
        }

        // ===== HELPER METHODS =====

        static async Task<string> FetchDataAsync(string url, int delayMs = 100)
        {
            // Simulate network delay
            await Task.Delay(delayMs);
            return $"Data from {url}";
        }

        static string ProcessData(string data)
        {
            return data.ToUpper();
        }

        static async Task<string> FetchDataWithErrorAsync()
        {
            await Task.Delay(100);
            throw new HttpRequestException("Network error occurred");
        }

        static async Task<string> SafeFetchAsync(string source, bool shouldFail)
        {
            try
            {
                await Task.Delay(100);

                if (shouldFail)
                {
                    throw new Exception($"{source} failed");
                }

                return $"{source}: Success";
            }
            catch (Exception ex)
            {
                return $"{source}: Error - {ex.Message}";
            }
        }

        static async Task LongRunningOperationAsync(System.Threading.CancellationToken cancellationToken)
        {
            for (int i = 0; i < 20; i++)
            {
                // Check if cancellation was requested
                cancellationToken.ThrowIfCancellationRequested();

                await Task.Delay(100, cancellationToken);
                Console.WriteLine($"  Progress: {(i + 1) * 5}%");
            }
        }
    }

    // ===== ADVANCED PATTERNS =====
    public class AdvancedAsyncPatterns
    {
        // Pattern 1: Async lazy initialization
        private readonly Lazy<Task<string>> _lazyData = new Lazy<Task<string>>(
            () => ExpensiveOperationAsync()
        );

        public Task<string> GetDataAsync() => _lazyData.Value;

        static async Task<string> ExpensiveOperationAsync()
        {
            await Task.Delay(1000);
            return "Expensive data";
        }

        // Pattern 2: Async retry logic
        public static async Task<T> RetryAsync<T>(
            Func<Task<T>> operation,
            int maxRetries = 3,
            int delayMs = 1000)
        {
            for (int i = 0; i < maxRetries; i++)
            {
                try
                {
                    return await operation();
                }
                catch (Exception) when (i < maxRetries - 1)
                {
                    await Task.Delay(delayMs);
                }
            }

            return await operation(); // Last attempt without catching
        }

        // Pattern 3: Timeout
        public static async Task<T> WithTimeoutAsync<T>(
            Task<T> task,
            TimeSpan timeout)
        {
            var timeoutTask = Task.Delay(timeout);
            var completedTask = await Task.WhenAny(task, timeoutTask);

            if (completedTask == timeoutTask)
            {
                throw new TimeoutException("Operation timed out");
            }

            return await task;
        }

        // Pattern 4: Progress reporting
        public static async Task ProcessWithProgressAsync(
            IProgress<int> progress)
        {
            for (int i = 0; i <= 100; i += 10)
            {
                await Task.Delay(100);
                progress.Report(i);
            }
        }
    }
}
