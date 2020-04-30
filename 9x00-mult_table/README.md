#Kth smallest number in multiplication table

Given the height `m` and the length `n` of an `m * n` Multiplication Table, and a positive integer `k`, find and return the k-th smallest number in this table.

**What you don’t tell the candidate, but answer her/him when she/he asks for clarification:**

*   `m` and `n` will be in the range `[1, 30000]`
*   `k` will be in the range `[1, m * n]`

**Example 1:**

Input: `m = 3, n = 3, k = 5` Output: `3`

Explanation: The Multiplication Table:

|       |       |       |
| :---: | :---: | :---: |
| 1     | 2     | 3     |
| 2     | 4     | 6     |
| 3     | 6     | 9     |


The 5-th smallest number is `3` (sorted list of values: `1, 2, 2, 3, 3`).

**Example 2:**

Input: `m = 2, n = 3, k = 6` Output: `6`

Explanation: The Multiplication Table:

|       |       |       |
| :---: | :---: | :---: |
| 1     | 2     | 3     |
| 2     | 4     | 6     |


The 6-th smallest number is `6` (sorted list of values: `1, 2, 2, 3, 4, 6`).



Brute force
-----------

Create the multiplication table and sort it, then take the k-th element

**Code implementation in Python:**
```
    def findKthNumber(m, n, k):
        table = [i*j for i in range(1, m+1) for j in range(1, n+1)]
        table.sort()
        return table[k-1]
```    

**Follow-up questions:**

*   What is the time complexity of this algorithm? `O(m*n)`to create the table, and `O(m∗nlog(m∗n))` to sort it
*   What is the space complexity of this algorithm? `O(m*n)` to store the table
*   Can you find a faster solution?

**Score:** If this is the best solution the candidate can find: max 40%

Priority Queue (Heap)
---------------------

Maintain a heap of the smallest unused element of each row. Then, finding the next element is a pop operation on the heap

**Code implementation in Python:**
```
    import heapq
    def findKthNumber(m, n, k):
        heap = [(i, i) for i in range(1, m+1)]
        heapq.heapify(heap)    # create a heap from the list of smallest unused values in each row
    
        for _ in range(k):
            val, root = heapq.heappop(heap)    # pop off the smallest value
            next = val + root    # calculate the next smallest value in that row
            if next <= root * n:
                heapq.heappush(heap, (next, root))    # push the next value onto the heap
        return val
 ```   

**Follow-up questions:**

*   What is the time complexity of this algorithm? `O(k∗mlogm)=O(m^2nlogm)`. Our initial heapify operation is `O(m)`. Afterwards, each pop and push is `O(mlogm)`, and our outer loop is `O(k)=O(m∗n)`
*   What is the space complexity of this algorithm? `O(m)`. Our heap is implemented as an array with `m` elements.
*   Can you find a faster solution?

**Score:** If this is the best solution the candidate can find: max 60%

Binary Search
-------------

Say `enough(x, m, n, k)` is true if and only if there are `k` or more values in the multiplication table that are less than or equal to `x`. Colloquially, enough describes whether `x` is large enough to be the k-th value in the multiplication table.

Let's define 3 variables `lo` the lowest value of the multiplication table (always equals to 1), `hi` the highest value of the multiplication table (always equals to `n * m`) and `mid` the middle value between `lo` and `hi` (equals to `(lo + hi) / 2`). Send the value of `mi` to the `enough` function (as the `x` value) and based on the result, move `lo` or `hi` before re-iterating by starting to re-calculate `mi`, and that, until `lo` >= `hi`.

**Code implementation in Python:**
```
    def enough(x, m, n, k):
        count = 0
        for i in range(1, m+1):
            count += min(x // i, n)
        return count >= k
    
    def findKthNumber(m, n, k):
        lo, hi = 1, m * n
        while lo < hi:
            mi = (lo + hi) / 2
            if not enough(mi, m, n, k):
                lo = mi + 1
            else:
                hi = mi
        return lo
```    

**Execution flow:**

*   `n` = 3
*   `m` = 3
*   `k` = 5

Step #1:

*   `lo` = 1
*   `hi` = 9
*   `mi` = 5

|       |       |       |
| :---: | :---: | :---: |
| **1**     | **2**     | **3**     |
| **2**     | **4**     | 6     |
| **3**     | 6     | 9     |

\=> `enough(5, 3, 3, 5)` => `count` = 6 -> `True`

Step #2:

*   `lo` = 1
*   `hi` = 5
*   `mi` = 3

|       |       |       |
| :---: | :---: | :---: |
| **1**     | **2**     | **3**     |
| **2**     | 4     | 6     |
| **3**     | 6     | 9     |

\=> `enough(3, 3, 3, 5)` => `count` = 5 -> `True`

Step #3:

*   `lo` = 1
*   `hi` = 3
*   `mi` = 2

|       |       |       |
| :---: | :---: | :---: |
| **1**     | **2**     | 3     |
| **2**     | 4     | 6     |
| 3     | 6     | 9     |

\=> `enough(2, 3, 3, 5)` => `count` = 3 -> `False`

Step #4:

*   `lo` = 3
*   `hi` = 3

\=> return `lo` = `3`

**Follow-up questions:**

*   What is the time complexity of this algorithm? `O(m∗log(m∗n))`
*   What is the space complexity of this algorithm? `O(1)`

**Score:** If this is the best solution the candidate can find: max 100%

* * *
