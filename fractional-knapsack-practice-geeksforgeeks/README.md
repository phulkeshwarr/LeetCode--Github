<h2><a href="https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1">Fractional Knapsack | Practice | GeeksforGeeks</a></h2><h3>Medium</h3><hr>
<div>
<p>Given an array of integers <code>nums</code> and an integer <code>target</code>, return indices of the two numbers such that they add up to <code>target</code>.</p>
<p>Refer to the <a href="https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1">LeetCode problem page</a> for full constraints and examples.</p>
</div>

<hr>

### 📊 Submission Statistics
- **Language:** `cpp`
- **Runtime:** `N/A`
- **Memory:** `N/A`
- **Submission Date:** Tue, 25 Aug 2026 17:23:31 GMT

---

### 💡 Approach & Complexity Analysis
#### 🧠 Intuition & Algorithmic Strategy
- **Approach:** Orders the elements to greedily identify optimal candidates or missing targets.
- **Flow:**
  1. Initialize state variables and inspect base constraints.
  2. Iterate through input elements, maintaining current progress and boundaries.
  3. Return the calculated result satisfying problem criteria.

#### ⏱️ Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N \log N)$ — *Sorting the input elements dominates the time complexity.*
- **Space Complexity:** $\mathcal{O}(N)$ — *Auxiliary hash-based lookup structure storing up to N elements.*

#### 📈 Time Complexity Graph (Operations vs Input Size $N$)
```mermaid
xychart-beta
    title "Time Complexity: O(N log N) — Linearithmic Growth"
    x-axis "Input Size (N)" [10, 100, 300, 600, 1000]
    y-axis "Operations (Steps)" 0 --> 10000
    bar [33, 664, 2470, 5537, 9966]
    line [33, 664, 2470, 5537, 9966]
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
