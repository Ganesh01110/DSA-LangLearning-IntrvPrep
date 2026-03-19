# Ultimate Java Interview Guide (Mid-Level Backend Engineer)
*This guide contains high-yield interview questions focusing on the 80% most important concepts to understand Java heavily used in modern and legacy backend systems.*

## 🔥 PRIORITY 1: Core Fundamentals & OOP

### 🔹 1. Core Java Fundamentals
**Q1. Primitive vs Wrapper Classes**
* **What:** Primitives (`int`, `char`) store raw values. Wrappers (`Integer`, `Character`) are object representations of primitives.
* **How:** `int a = 5; Integer b = Integer.valueOf(5);`
* **When:** Use primitives for performance/math. Use wrappers when working with Collections (e.g., `ArrayList<Integer>`) or preventing NullPointerExceptions (wrappers can be null).
* **Why:** Collections Framework only works with Objects, not primitives.
* **💡 Tip:** Mention "Autoboxing and Unboxing" (automatic conversion between primitive and wrapper).

**Q2. Pass by Value vs Pass by Reference**
* **What:** Java is strictly **Pass by Value**.
* **How:** When passing objects, the *reference* (memory address) is passed by value (a copy of the address is passed).
* **When / Why:** Prevents methods from reassigning original object pointers, but allows modifying the object's internal state.
* **💡 Tip:** If an interviewer asks "Can a method reassign the object?", the answer is "No, it only changes local reference copy."

**Q3. Arrays vs Strings**
* **What:** Arrays are fixed-size sequential collections. Strings are immutable object arrays of characters.
* **How:** `int[] arr = new int[5]; String s = "Hello";`
* **When:** Use arrays for fixed-size fast data access. Use Strings for text manipulation.
* **Why:** Strings are pooled in memory (String Pool) to save space, making them ideal for heavy text reuse.
* **💡 Tip:** Strings are immutable; modifying them creates a new object in the Heap.

**Q4. break vs continue**
* **What/How:** `break` exits the nearest loop entirely. `continue` skips the current iteration and jumps to the next.
* **When/Why:** `break` to short-circuit searching; `continue` to filter out specific loop conditions.

**Q5. Recursion vs Iteration**
* **What/How:** Recursion is a method calling itself. Iteration uses loops.
* **When/Why:** Recursion is great for tree/graph traversal. Iteration is better for memory safety (avoids StackOverflowError).

### 🔹 2. OOP Concepts (Crucial)
**Q6. Class vs Object**
* **What:** Class is a blueprint. Object is an instance of a class.
* **How:** `class Car {}` -> `Car myCar = new Car();`
* **When/Why:** Use classes to encapsulate data and behavior logically.
* **💡 Tip:** Compare it to an architectural blueprint vs the actual house.

**Q7. Encapsulation**
* **What:** Hiding internal state/data and requiring all interactions to be performed through an object's methods.
* **How:** Making fields `private` and providing `public` getters/setters.
* **Why:** Protects data integrity and hides implementation details (Black Boxing).
* **💡 Tip:** Mention that encapsulation helps in achieving loose coupling.

**Q8. Abstraction**
* **What:** Hiding complex implementation details and showing only the essential features of an object.
* **How:** Using `abstract` classes or `interface`.
* **When:** When you want to define "what" something does without worrying about "how" it does it yet.
* **Why:** Reduces code complexity and aids in scaling architectures.
* **💡 Tip:** Interface = 100% abstract (until Java 8 default methods).

**Q9. Inheritance**
* **What:** Mechanism where one class acquires the properties of another.
* **How:** `class Dog extends Animal`
* **When:** To achieve code reusability and establish an IS-A relationship.
* **Why:** To utilize Polymorphism and reduce redundant code.
* **💡 Tip:** Java does not support multiple inheritance with classes (to avoid Diamond Problem), only through interfaces.

**Q10. Polymorphism (Compile-time vs Run-time)**
* **What:** The ability of an object to take many forms.
* **How:** Compile-time (Method Overloading: same name, different params). Run-time (Method Overriding: subclass redefines parent method).
* **When/Why:** Run-time polymorphism allows dynamic method dispatch, crucial for loosely coupled code (e.g., Spring Dependency Injection).
* **💡 Tip:** Mention `@Override` annotation and Dynamic Binding.

**Q11. Constructor & `this` keyword**
* **What:** Constructor initializes an object. `this` refers to the current invoking object.
* **How:** `public MyClass(int id) { this.id = id; }`
* **When:** Used during object instantiation.
* **Why:** `this` resolves ambiguity between instance variables and parameters.
* **💡 Tip:** Constructors have no return type. If none is defined, Java provides a default no-arg constructor.

**Q12. `super` keyword**
* **What/How:** Used to call parent class constructor, methods, or variables (`super.method()`, `super()`).
* **Why:** To reuse parent logic in an overridden method.

## 🔥 PRIORITY 2: Collections Framework

### 🔹 3. Collections Framework (Highly Important)
**Q13. Iterable & Collection Hierarchy**
* **What:** The root interfaces of the framework. `Iterable` -> `Collection` -> {`List`, `Set`, `Queue`}. `Map` is separate.
* **Why:** Standardizes data structure operations across Java.

**Q14. ArrayList vs LinkedList**
* **What/How:** `ArrayList` uses a dynamic array. `LinkedList` uses a doubly-linked list.
* **When/Why:** 
  * `ArrayList`: O(1) for retrieval. Best for searching and reading.
  * `LinkedList`: O(1) for adding/removing at ends. Best for frequent insertions/deletions.
* **💡 Tip:** ArrayList is essentially default in modern apps due to CPU caching efficiency.

**Q15. Set: HashSet vs TreeSet vs LinkedHashSet**
* **What/How:** 
  * `HashSet`: Uses HashMap internally. O(1) ops. Unordered.
  * `TreeSet`: Uses Red-Black Tree. O(log n). Sorted naturally.
  * `LinkedHashSet`: Maintains insertion order.
* **When:** Use Set to remove duplicates. Use TreeSet when you need them sorted.
* **💡 Tip:** HashSet allows one `null`. TreeSet allows no `nulls` (throws NullPointerException).

**Q16. Map: HashMap vs TreeMap vs ConcurrentHashMap**
* **What/How:** Key-value pairs. 
  * `HashMap`: O(1) lookup. Unordered.
  * `TreeMap`: O(log n). Sorted by keys.
  * `ConcurrentHashMap`: Thread-safe version of HashMap.
* **When:** Connecting IDs to Objects (e.g., `userId` -> `User`).
* **Why:** High-performance data retrieval.
* **💡 Tip:** Explain HashMap internal working (Array of buckets + LinkedList/Red-Black Tree for collisions, Java 8).

**Q17. Iterator vs ListIterator**
* **What:** `Iterator` traverses any collection forward. `ListIterator` traverses lists bidirectionally.
* **Why:** Used to safely remove elements while looping (avoids `ConcurrentModificationException`).

**Q18. Comparable vs Comparator**
* **What:** Interfaces used to sort objects.
* **How:** 
  * `Comparable`: Implemented in the class itself (`compareTo()`). Single sorting logic (e.g., sort users by ID).
  * `Comparator`: External class (`compare()`). Multiple sorting logics (e.g., sort users by age, then by name).
* **When/Why:** Use `Comparator` for custom sorting without modifying the original class.

**Q19. fail-fast vs fail-safe iterators**
* **What:** Fail-fast throws exception if collection is modified while iterating (e.g., `ArrayList`). Fail-safe doesn't throw because it operates on a clone (e.g., `ConcurrentHashMap`).

**Q20. HashMap Internal Working (Guaranteed Interview Question)**
* **What/How:** Hashing principle. Keys generate a `hashCode()` which modulo the array size gives the index. If collision occurs, nodes are linked. Since Java 8, if a bucket gets >8 nodes, list converts to Red-Black Tree (O(n) -> O(log n)).
* **💡 Tip:** Knowing the Treeify threshold (8) proves seniority.

## 🔥 PRIORITY 3: Java 8 Features & Exceptions

### 🔹 4. Java 8+ Features 
**Q21. Lambda Expressions**
* **What:** Anonymous functions that provide concise syntax to implement functional interfaces.
* **How:** `(args) -> { body };`
* **When/Why:** Replaces boilerplate anonymous inner classes. Heavily used in Streams.

**Q22. Functional Interfaces & `@FunctionalInterface`**
* **What:** An interface with exactly ONE abstract method. Can have multiple default/static methods.
* **Examples:** `Runnable`, `Callable`, `Predicate`, `Function`, `Consumer`, `Supplier`.
* **When:** Use as targets for lambda expressions.

**Q23. Streams API (Intermediate vs Terminal Operations)**
* **What:** A sequence of elements supporting sequential and parallel aggregate operations.
* **How:** 
  * Intermediate (Return Stream, lazy): `filter()`, `map()`, `sorted()`.
  * Terminal (Return result, triggers execution): `collect()`, `forEach()`, `reduce()`.
* **When:** Processing large collections of objects natively.
* **Why:** Declarative, clean, easily parallelizable code.
* **💡 Tip:** Streams do not store data, they only process data from a source.

**Q24. Optional Class**
* **What:** A container object which may or may not contain a non-null value.
* **How:** `Optional<String> opt = Optional.ofNullable(val); opt.orElse("default");`
* **When/Why:** To completely eliminate `NullPointerException` and avoid dirty `if(val != null)` checks.
* **💡 Tip:** Never use `Optional` as a parameter or class field, only as a method return type.

**Q25. Method References**
* **What:** Shorthand syntax for a lambda expression that calls one existing method.
* **How:** `ClassName::methodName` instead of `x -> ClassName.methodName(x)`.

**Q26. Default Methods in Interfaces**
* **What:** Methods inside an interface that have a body using `default` keyword.
* **Why:** Allowed Java to add `stream()` to existing Collections interfaces without breaking all legacy code that implemented them.

### 🔹 5. Exception Handling
**Q27. Checked vs Unchecked Exceptions**
* **What:** 
  * Checked (compile-time): Extend `Exception` (e.g., `IOException`). Must be explicitly handled using try-catch or `throws`.
  * Unchecked (run-time): Extend `RuntimeException` (e.g., `NullPointerException`). Don't strictly require handling.
* **When/Why:** Checked forces the caller to recover (expected system failures). Unchecked indicates programming bugs (logic errors).
* **💡 Tip:** Spring `@Transactional` by default only rolls back on Unchecked exceptions!

**Q28. try-catch-finally**
* **What:** Try contains risky code. Catch handles the error. Finally runs regardless of success or failure.
* **Why:** `finally` guarantees resource cleanup (closing DB connections/files).
* **💡 Tip:** Does finally run if try has a `return` statement? Yes!

**Q29. try-with-resources**
* **What:** Introduced in Java 7 to auto-close resources that implement `AutoCloseable`.
* **How:** `try (BufferedReader br = new BufferedReader(...)) { ... }`
* **Why:** Replaces verbose `finally` blocks.

**Q30. throw vs throws**
* **What:** `throw` explicitly throws an exception object. `throws` is used in method signatures to declare what exceptions might be thrown.
* **How:** `throw new RuntimeException();` vs `public void run() throws IOException`.

**Q31. Custom Exceptions**
* **What/How:** Creating a class that `extends RuntimeException`.
* **When:** Business logic errors (e.g., `UserNotFoundException`, `InsufficientFundsException`).
* **Why:** Makes logs and error handling semantic and readable.

## 🔥 PRIORITY 4: Memory Management (JVM) & Multithreading

### 🔹 6. Memory Management & JVM
**Q32. JVM vs JRE vs JDK**
* **What:**
  * JVM: Executes bytecode.
  * JRE: JVM + Core Libraries (Runtime environment).
  * JDK: JRE + Development Tools (javac, debugger).
* **💡 Tip:** Write Once, Run Anywhere is possible because each OS has a specific JVM.

**Q33. Heap vs Stack Memory**
* **What/Why:**
  * **Heap:** Stores Objects and JRE classes. Shared across all threads. Garbage collected.
  * **Stack:** Stores local variables and method calls. Thread-specific. LIFO structure.
* **💡 Tip:** `OutOfMemoryError` = Heap is full. `StackOverflowError` = Stack is full (usually infinite recursion).

**Q34. Garbage Collection (GC)**
* **What:** Background daemon thread the JVM runs to reclaim memory of unreachable objects.
* **How:** "Mark and Sweep" algorithm. Objects are marked if reachable, swept if unreachable.
* **Why:** Prevents manual memory management (like C++ `delete`), avoiding memory leaks.
* **💡 Tip:** You cannot force GC using `System.gc()`, it's just a suggestion to JVM.

**Q35. ClassLoader**
* **What:** Part of JRE that dynamically loads Java classes into JVM memory.
* **Types:** Bootstrap (Core runtime classes), Extension, Application (our codebase).
* **Why:** Essential to load classes only when required (lazy loading).

### 🔹 7. Multithreading & Concurrency
**Q36. Process vs Thread**
* **What:** Process is an executing program (heavy). Thread is a sub-unit of a process sharing the same memory (light).
* **Why:** Multithreading allows simultaneous execution, maximizing CPU usage.

**Q37. Runnable vs Thread class**
* **What/How:** Two ways to create a thread: `implement Runnable` or `extend Thread`.
* **When/Why:** Always use `Runnable`! Java doesn't support multiple class inheritance, so extending `Thread` wastes your inheritance opportunity.

**Q38. Thread Lifecycle States**
* **What:** New -> Runnable -> Running -> Blocked/Waiting -> Terminated (Dead).

**Q39. Synchronization**
* **What:** Restricting access to a shared resource to only ONE thread at a time using monitors/locks.
* **How:** `synchronized` keyword on methods or code blocks.
* **Why:** Prevents "Race Conditions" where multiple threads corrupt shared data.

**Q40. Deadlock**
* **What:** When Thread A holds Lock 1 waiting for Lock 2, and Thread B holds Lock 2 waiting for Lock 1. Both wait forever.
* **How to prevent:** Always acquire locks in a consistent global order.

**Q41. Volatile Keyword**
* **What:** Ensures that changes to a variable are strictly written to main memory and not cached by individual threads.
* **Why:** Resolves visibility problems across threads.

**Q42. ExecutorService & Thread Pools**
* **What:** A framework to manage and reuse threads instead of manually doing `new Thread()`.
* **How:** `ExecutorService tp = Executors.newFixedThreadPool(10);`
* **Why:** Creating raw threads is extremely expensive for the CPU. Thread pools reuse a fixed number of threads to process tasks (crucial in web servers like Tomcat).

**Q43. Callable vs Runnable**
* **What:** Both serve thread logic. But `Runnable` returns `void` and cannot throw checked exceptions. `Callable` returns a `Future<T>` and can throw exceptions.

**Q44. Concurrent Collections**
* **What:** Thread-safe implementations using fine-grained locking or lock-stripping.
* **Examples:** `ConcurrentHashMap`, `CopyOnWriteArrayList`, `BlockingQueue`.
* **Why:** Standard `Collections.synchronizedList()` locks the entire object, destroying performance. `ConcurrentHashMap` only locks a specific bucket segment.

## 🚀 ADVANCED: JDBC, Design Patterns, & Core Quirks

### 🔹 8. File Handling & Serialization
**Q45. File I/O (File, BufferedReader)**
* **What:** Used to read/write external resources. `BufferedReader` reads text from a character-input stream, buffering characters for efficiency.
* **Why:** Direct byte reading is slow. Buffering minimizes actual physical disk reads.

**Q46. Serialization & transient keyword**
* **What:** Serialization converts an Object's state to a Byte Stream (to save to file/network). Deserialization is the reverse. Requires implementing `Serializable` marker interface.
* **When/How:** Mark fields as `transient` if you DO NOT want them serialized (like passwords).

### 🔹 9. JDBC (Backend Fundamentals)
**Q47. JDBC Flow**
* **What/How:** Register Driver -> Open `Connection` -> Create `Statement` -> Execute Query -> Return `ResultSet` -> Close Connection.
* **Why:** The legacy, core API for Java database interaction. Underlying layer of Hibernate/JPA.

**Q48. Statement vs PreparedStatement**
* **What/How:** `Statement` compiles query every time. `PreparedStatement` pre-compiles and parameterizes query (`SELECT * FROM X WHERE id = ?`).
* **Why:** `PreparedStatement` prevents **SQL Injection** and runs faster on caching. Always use it!

**Q49. Connection Pooling (e.g., HikariCP)**
* **What:** Keeping a pool of database connections open to reuse them via JDBC.
* **Why:** Opening/closing networking DB connections is incredibly slow and expensive.

### 🔹 10. Design Principles & Patterns
**Q50. SOLID Principles**
* **What / Why (Interview Gold):**
  * **S**ingle Responsibility: Class should have one reason to change.
  * **O**pen/Closed: Open for extension, closed for modification.
  * **L**iskov Substitution: Child classes must seamlessly replace parent classes.
  * **I**nterface Segregation: Many small interfaces are better than one fat interface.
  * **D**ependency Inversion: Depend on abstractions (interfaces), not concretions.

**Q51. Singleton Pattern**
* **What:** Restricts a class from instantiating more than one object.
* **How:** Private constructor, static instance variable, public static `getInstance()` method.
* **When/Why:** Database connection managers, Loggers.
* **💡 Tip:** Is your Singleton thread-safe? Mention double-checked locking using `volatile`.

**Q52. Factory Pattern**
* **What:** Creates object without exposing instantiation logic to the client. Returns interface type.
* **Why:** Loosely couples codebase so adding new subclasses doesn't break client code.

**Q53. Dependency Injection (DI)**
* **What:** (Inversion of Control logic) Instead of creating dependencies using `new Object()`, you pass them in via Constructor. 
* **Why:** Solves tight coupling, making unit testing incredibly easy. Core philosophy of Spring Boot.

### 🔹 11. Important Language Traps
**Q54. final, finally, finalize**
* **What:**
  * `final`: Keyword (Cannot change var, override method, extend class).
  * `finally`: Block in exception handling (always executes).
  * `finalize`: Deprecated method called right before garbage collection.

**Q55. equals() vs ==**
* **What:** `==` compares object memory references (pointers). `.equals()` compares logical object equivalency (content).
* **💡 Tip:** Always override `equals()` if comparing custom objects. 

**Q56. equals() and hashCode() Contract**
* **What:** If two objects are equal according to `equals()`, they MUST return the same `hashCode()`.
* **Why:** Essential for HashMap functionality. If violated, you won't be able to retrieve an object tightly packed in a Hash Bucket.

**Q57. String vs StringBuilder vs StringBuffer**
* **What:**
  * `String`: Immutable. Modifying it creates new objects.
  * `StringBuilder`: Mutable and fast. Not thread-safe.
  * `StringBuffer`: Mutable but thread-safe (synchronized methods).
* **When:** Use `StringBuilder` when concatenating logic inside loops!

**Q58. String Pool & Immutability**
* **What:** Security and Optimization. Strings literal `"Test"` go into String Pool. If another String uses `"Test"`, it points to the same memory.
* **Why Immutable?** Prevents caching errors, makes them thread-safe implicitly, and secures Network/DB passwords from being altered randomly by pointer access.

### 🔹 12. Advanced Topics 
**Q59. Annotations (`@`)**
* **What:** Metadata providing data about a program that is not part of the program itself.
* **Why:** Replaces boilerplate XML configuration (Core of Spring Boot, Hibernate).

**Q60. Reflection API**
* **What:** Allows an executing Java program to examine or introspect upon itself (manipulate internal properties of a class even if `private` at runtime!).
* **Why:** Used extensively by frameworks like Spring (to wire dependencies) and JUnit (to invoke tests). Slow and dangerous for standard apps.

**Q61. Generics (`<T>`)**
* **What:** Allowing classes/methods to operate on objects of various types while providing compile-time type safety.
* **Why:** Fixes the old `ClassCastException` problem where `ArrayList` held raw `Object` types.

---
### 🧠 Final Interview Tips for Backend Roles
1. **Never just define a concept.** Always immediately follow up with a context where you would use it. (e.g., "A HashMap provides O(1) lookup, *which I used recently to cache API credentials instead of querying the DB constantly.*")
2. **Understand "Under the Hood":** Seniority means knowing *how* a HashMap resolves collisions or *how* a Thread Pool queues tasks.
3. **Bring everything to Dependency Injection:** If they ask about Constructors, mention how DI wires things through Constructors to avoid tight coupling.
