# Common TCS NQT Coding Questions (with Solutions Strategy)

These are specific "High Probability" questions that have appeared in previous TCS iON exams.

## 1. Finding the Second Largest Element
**Requirement:** Find the second largest element in an array without sorting it (to keep time complexity $O(N)$).
**Strategy:**
*   Keep two variables: `max` and `secondMax`.
*   Iterate once. Update `max` if current is larger. If current is smaller than `max` but larger than `secondMax`, update `secondMax`.

## 2. Array Rotation (Left/Right)
**Requirement:** Rotate an array by $K$ positions.
**Strategy (Optimal):**
1.  Reverse the first part (0 to $K-1$).
2.  Reverse the second part ($K$ to $N-1$).
3.  Reverse the entire array.

## 3. Anagram Check
**Requirement:** Check if two strings are anagrams.
**Strategy (No Sorting):**
*   Create a frequency array of size 256 (for ASCII).
*   Increment for String A, decrement for String B.
*   If all elements are 0, they are anagrams.

## 4. Equilibrium Index
**Requirement:** Find an index such that sum of elements at lower indices is equal to sum of elements at higher indices.
**Strategy:**
*   Calculate total sum.
*   Iterate and keep track of `leftSum`. `rightSum = totalSum - leftSum - currentElement`.

## 5. Most Frequent Character
**Requirement:** Find the character that appears most often.
**Strategy:**
*   Use a Hash Map or Frequency Array.
*   Iterate through string once.

## 6. Matrix Rotation (90 Degrees)
**Requirement:** Rotate a $N \times N$ matrix in-place.
**Strategy:**
1.  Transpose the matrix (swap `matrix[i][j]` with `matrix[j][i]`).
2.  Reverse each row.

## 7. Palindrome Number/String (Manual)
**Requirement:** Do not use `reverse()` or `StringBuilder.reverse()`.
**Strategy:**
*   Use two pointers (Start and End) and compare.

## 8. GCD/LCM (Euclidean Algorithm)
**Requirement:** Find GCD of two numbers.
**Strategy:** 
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

## 9. Removing Duplicates from Sorted Array
**Requirement:** Return the length of the unique array.
**Strategy:** Use the two-pointer approach to shift unique elements to the front.

## 10. Leap Year (No Library)
**Requirement:** Logic for Leap Year.
**Strategy:** `(year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)`.
