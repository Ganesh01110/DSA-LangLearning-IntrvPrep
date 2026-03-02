# Scenario-Based Problem Decoding Guide

In the TCS NQT (especially for **Prime** and **Digital** roles), you won't see a question like "Find the second largest element." Instead, you'll see a story. This guide helps you peel back the "story" to find the underlying DSA pattern.

## The Strategy: "The 3-Step Peel"

1.  **Identify the Input/Output:** What data are they giving? (Values in a line? Time intervals? Encrypted strings?)
2.  **Filter the "Noise":** Ignore names of people, names of factories, or flavor text. Look for the **action**.
3.  **Map to a Pattern:** Does it involve counting? Sorting? Sums of segments?

---

## Common Scenario Mappings

| NQT Scenario Name | Story Logic | Underlying DSA Pattern |
| :--- | :--- | :--- |
| **"The Chocolate Factory"** | Moving empty packets (0s) to the end of a line. | **Move Zeroes to End** (Two Pointers) |
| **"A Party on a Cruise"** | Max guests at a time given entry/exit hours. | **Interval Overlap / Prefix Sum** |
| **"The Supermarket"** | Price is the product of digits of a given N. | **Number Theory / Digit Extraction** |
| **"Oxygen Level Check"** | Average oxygen in 3 rounds for 3 trainees. | **Matrix Traversal / Averaging** |
| **"Washing Machine Load"** | Weight vs Time based on ranges. | **Conditional Logic (If-Else Ranges)** |
| **"Stock Price Span"** | Consecutive days price was less than today. | **Monotonic Stack** (Advanced) |

---

## Example: Decoding the "Cruise Party"

**The Story:** 
> "A party is being held on a cruise. Two arrays are given: `E[]` (Entry hour) and `L[]` (Leaving hour). Find the maximum number of people on the cruise at any point."

**The Decoding:**
*   **Input:** Two arrays representing time intervals.
*   **Action:** Count simultaneous occurrences.
*   **Pattern:** This is **Interval Overlap**. You create a timeline (Prefix Sum) and find the peak.

---

## 🚀 Pro-Tip for Prime Role
For the Prime role, the compiler is very strict on **Time Complexity**. 
*   If $N = 10^5$, you **must** use $O(N)$ or $O(N \log N)$. 
*   Nested loops ($O(N^2)$) will get you **Time Limit Exceeded (TLE)**.
*   Always use `long long` for sums to avoid **Overflow**.
