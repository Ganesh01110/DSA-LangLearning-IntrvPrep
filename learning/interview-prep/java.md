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

