<h2><a href="https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true">2D Array - DS</a></h2><h3>Medium</h3><hr>
<div>
<p>Given a  2D array, , an hourglass is a subset of values with indices falling in the following pattern:</p>
<p>a b c  <br>  d  <br>e f g</p>
<p>There are  hourglasses in a  array. The  is the sum of the values in an hourglass. Calculate the hourglass sum for every hourglass in , then print the  hourglass sum.</p>
<p>Example</p>
<p>-9 -9 -9  1 1 1 <br> 0 -9  0  4 3 2<br>-9 -9 -9  1 2 3<br> 0  0  8  6 6 0<br> 0  0  0 -2 0 0<br> 0  0  1  2 4 0</p>
<p>The  hourglass sums are:</p>
<p>-63, -34, -9, 12, <br>-10,   0, 28, 23, <br>-27, -11, -2, 10, <br>  9,  17, 25, 18</p>
<p>The highest hourglass sum is  from the hourglass beginning at row , column :</p>
<p>0 4 3<br>  1<br>8 6 6</p>
<p>Note: If you have already solved the Java domain's Java 2D Array challenge, you may wish to skip this challenge.</p>
<p>Function Description</p>
<p>Complete the function  with the following parameter(s):</p>
<p>: a 2-D array of integers</p>
<p>Returns</p>
<p>: the maximum hourglass sum</p>
<p>Input Format</p>
<p>Each of the  lines of inputs  contains  space-separated integers .</p>
<p>Constraints</p>
<p>Sample Input</p>
<p>1 1 1 0 0 0<br>0 1 0 0 0 0<br>1 1 1 0 0 0<br>0 0 2 4 4 0<br>0 0 0 2 0 0<br>0 0 1 2 4 0</p>
<p>Sample Output</p>
<p>19</p>
<p>Explanation</p>
<p>contains the following hourglasses:</p>
<p>The hourglass with the maximum sum () is:</p>
<p>2 4 4<br>  2<br>1 2 4</p>
</div>

<hr>

### 📊 Submission Statistics
- **Language:** `cpp`
- **Runtime:** `N/A`
- **Memory:** `N/A`
- **Submission Date:** Tue, 25 Aug 2026 17:45:14 GMT

---

### 💡 Approach & Complexity Analysis
#### 🧠 Intuition & Algorithmic Strategy
- **Approach:** Utilizes frequency counting or presence tracking via hash mapping for O(1) membership queries.
- **Flow:**
  1. Initialize state variables and inspect base constraints.
  2. Iterate through input elements, maintaining current progress and boundaries.
  3. Return the calculated result satisfying problem criteria.

#### ⏱️ Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N^2) \text{ or } \mathcal{O}(N \times M)$ — *Nested iteration processing combinations or grid cells.*
- **Space Complexity:** $\mathcal{O}(N)$ — *Auxiliary hash-based lookup structure storing up to N elements.*

#### 📈 Time Complexity Graph (Operations vs Input Size $N$)
```mermaid
xychart-beta
    title "Time Complexity: O(N²) — Quadratic Operations"
    x-axis "Input Size (N)" [10, 100, 300, 600, 1000]
    y-axis "Operations (Steps)" 0 --> 1000000
    bar [100, 10000, 90000, 360000, 1000000]
    line [100, 10000, 90000, 360000, 1000000]
```

#### 📦 Space Complexity Graph (Memory Footprint vs Input Size $N$)
```mermaid
xychart-beta
    title "Space Complexity: O(N) — Linear Memory Allocation"
    x-axis "Input Size (N)" [10, 100, 300, 600, 1000]
    y-axis "Memory Footprint (Units)" 0 --> 1000
    bar [10, 100, 300, 600, 1000]
    line [10, 100, 300, 600, 1000]
```

---
*Auto-synced with [LeetGitSyncPro](https://synccode-pro.pages.dev) & [DSATracker](https://dsatracker.in)*
