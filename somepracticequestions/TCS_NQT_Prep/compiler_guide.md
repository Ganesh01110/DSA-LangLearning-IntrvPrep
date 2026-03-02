# TCS NQT Compiler & Language Guide

To excel in the TCS NQT coding section, choosing the right language and understanding the compiler's quirks is crucial.

## Which Language Should You Choose?

> [!IMPORTANT]
> **Recommended: C++ (with `bits/stdc++.h`) or Java.**
> If you are very comfortable with Python, use it, but be careful with nested loops (time limits) and specific input formatting.

| Language | Pros | Cons |
| :--- | :--- | :--- |
| **C++** | Fastest execution, `bits/stdc++.h` supports most STL. | Manual memory management (rarely needed for NQT). |
| **Java** | Strong standard library, robust error messages. | Verbose Boilerplate (Scanner class can be slow). |
| **Python** | Fast to write, built-in large number support. | Can hit Time Limit Exceeded (TLE) on large inputs. |

## Compiler Pitfalls & Problems

TCS iON uses a strict, sometimes outdated compiler environment. Here is what to expect:

### 1. The "No Packages" Rule
*   **Java:** Do NOT use external libraries. Stick to `java.util.*` and `java.lang.*`.
*   **Python:** No `numpy`, `pandas`, or `scipy`. Only standard libraries like `math`, `collections`, `itertools`.
*   **C++:** Standard STL is allowed.

### 2. Input/Output (I/O) Speed
*   The compiler can be slow. If you use Java, prefer `StringTokenizer` or `BufferedReader` over `Scanner` for large inputs.
*   In C++, use `ios_base::sync_with_stdio(false); cin.tie(NULL);`.

### 3. Missing Method Errors
*   Some versions of Java in TCS NQT do not support modern helper methods like `String.join()` or certain Stream API features. **Always have a manual loop fallback.**

### 4. Extra Space/Newline Issues
*   The evaluation engine is sensitive. Ensure your output exactly matches the format. Avoid extra spaces at the end of lines or extra `\n` unless required.

### 5. Array vs. Length Bug
*   **Pitfall:** Sometimes the test case gives $N$ (size) and then $N$ elements. If you use `Scanner.nextInt()` in a loop, it might fail if there's a trailing newline.
*   **Fix:** Read the entire line and split it manually if `nextInt()` misbehaves.

## The Strategy
1.  **Read the whole input first** if possible.
2.  **Avoid complex recursion** if the depth is unknown (Stack Overflow).
3.  **Test for Edge Cases:** $N=0, N=1$, negative numbers, and very large numbers (use `long` in Java/C++).
