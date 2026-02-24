using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using System;
using System.Threading.Tasks;

namespace DependencyInjectionDemo
{
    class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("=== Dependency Injection in .NET ===\n");

            // Create a host with DI container (similar to Spring ApplicationContext)
            var host = Host.CreateDefaultBuilder(args)
                .ConfigureServices((context, services) =>
                {
                    // Register services with different lifetimes
                    ConfigureServices(services);
                })
                .Build();

            // Demonstrate service lifetimes
            await DemonstrateServiceLifetimes(host.Services);

            // Demonstrate scoped services
            DemonstrateScopedServices(host.Services);

            Console.WriteLine("\n✅ All DI examples completed!");
        }

        static void ConfigureServices(IServiceCollection services)
        {
            Console.WriteLine("Registering services...\n");

            // Transient: New instance every time
            services.AddTransient<ITransientService, TransientService>();
            services.AddTransient<IOperationService, OperationService>();

            // Scoped: One instance per scope (like per HTTP request)
            services.AddScoped<IScopedService, ScopedService>();

            // Singleton: One instance for application lifetime
            services.AddSingleton<ISingletonService, SingletonService>();

            // Register with implementation factory
            services.AddSingleton<IConfigService>(provider =>
                new ConfigService("Production"));

            // Register multiple implementations
            services.AddTransient<INotificationService, EmailNotificationService>();
            services.AddTransient<INotificationService, SmsNotificationService>();
        }

        static async Task DemonstrateServiceLifetimes(IServiceProvider services)
        {
            Console.WriteLine("1. SERVICE LIFETIMES");
            Console.WriteLine("────────────────────");

            // Resolve services multiple times
            var transient1 = services.GetRequiredService<ITransientService>();
            var transient2 = services.GetRequiredService<ITransientService>();

            var singleton1 = services.GetRequiredService<ISingletonService>();
            var singleton2 = services.GetRequiredService<ISingletonService>();

            Console.WriteLine($"Transient 1 ID: {transient1.InstanceId}");
            Console.WriteLine($"Transient 2 ID: {transient2.InstanceId}");
            Console.WriteLine($"Same instance? {transient1.InstanceId == transient2.InstanceId}\n");

            Console.WriteLine($"Singleton 1 ID: {singleton1.InstanceId}");
            Console.WriteLine($"Singleton 2 ID: {singleton2.InstanceId}");
            Console.WriteLine($"Same instance? {singleton1.InstanceId == singleton2.InstanceId}\n");

            await Task.CompletedTask;
        }

        static void DemonstrateScopedServices(IServiceProvider services)
        {
            Console.WriteLine("2. SCOPED SERVICES");
            Console.WriteLine("──────────────────");

            // Create first scope (like an HTTP request)
            using (var scope1 = services.CreateScope())
            {
                var scoped1a = scope1.ServiceProvider.GetRequiredService<IScopedService>();
                var scoped1b = scope1.ServiceProvider.GetRequiredService<IScopedService>();

                Console.WriteLine($"Scope 1 - First resolve:  {scoped1a.InstanceId}");
                Console.WriteLine($"Scope 1 - Second resolve: {scoped1b.InstanceId}");
                Console.WriteLine($"Same within scope? {scoped1a.InstanceId == scoped1b.InstanceId}");
            }

            // Create second scope (like another HTTP request)
            using (var scope2 = services.CreateScope())
            {
                var scoped2 = scope2.ServiceProvider.GetRequiredService<IScopedService>();
                Console.WriteLine($"\nScope 2 - First resolve:  {scoped2.InstanceId}");
                Console.WriteLine("Different scope = different instance\n");
            }
        }
    }

    // ===== SERVICE INTERFACES =====

    public interface ITransientService
    {
        Guid InstanceId { get; }
    }

    public interface IScopedService
    {
        Guid InstanceId { get; }
    }

    public interface ISingletonService
    {
        Guid InstanceId { get; }
    }

    public interface IConfigService
    {
        string Environment { get; }
    }

    public interface IOperationService
    {
        void Execute();
    }

    public interface INotificationService
    {
        void Send(string message);
    }

    // ===== SERVICE IMPLEMENTATIONS =====

    public class TransientService : ITransientService
    {
        public Guid InstanceId { get; } = Guid.NewGuid();

        public TransientService()
        {
            Console.WriteLine($"  [Transient] Created instance: {InstanceId}");
        }
    }

    public class ScopedService : IScopedService
    {
        public Guid InstanceId { get; } = Guid.NewGuid();

        public ScopedService()
        {
            Console.WriteLine($"  [Scoped] Created instance: {InstanceId}");
        }
    }

    public class SingletonService : ISingletonService
    {
        public Guid InstanceId { get; } = Guid.NewGuid();

        public SingletonService()
        {
            Console.WriteLine($"  [Singleton] Created instance: {InstanceId}");
        }
    }

    public class ConfigService : IConfigService
    {
        public string Environment { get; }

        public ConfigService(string environment)
        {
            Environment = environment;
            Console.WriteLine($"  [Config] Environment: {environment}");
        }
    }

    // ===== SERVICE WITH DEPENDENCIES =====

    public class OperationService : IOperationService
    {
        private readonly ITransientService _transient;
        private readonly ISingletonService _singleton;

        // Constructor injection - dependencies provided by DI container
        public OperationService(
            ITransientService transient,
            ISingletonService singleton)
        {
            _transient = transient;
            _singleton = singleton;
            Console.WriteLine($"  [Operation] Injected Transient: {_transient.InstanceId}");
            Console.WriteLine($"  [Operation] Injected Singleton: {_singleton.InstanceId}");
        }

        public void Execute()
        {
            Console.WriteLine("Executing operation...");
        }
    }

    // ===== MULTIPLE IMPLEMENTATIONS =====

    public class EmailNotificationService : INotificationService
    {
        public void Send(string message)
        {
            Console.WriteLine($"📧 Email: {message}");
        }
    }

    public class SmsNotificationService : INotificationService
    {
        public void Send(string message)
        {
            Console.WriteLine($"📱 SMS: {message}");
        }
    }
}
