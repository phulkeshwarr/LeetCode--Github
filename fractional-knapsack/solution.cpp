class Solution {
public:
    // Custom comparator to sort based on the value-to-weight ratio in descending order
    static bool cmp(pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<pair<double, int>> ratio(n);
        for (int i = 0; i < n; i++) {
            ratio[i] = {(double)val[i] / wt[i], i};
        }

        sort(ratio.begin(), ratio.end(), cmp);

        double totalValue = 0.0;

        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;

            if (capacity >= wt[idx]) {
                totalValue += val[idx];
                capacity -= wt[idx];
            } else {
                totalValue += ratio[i].first * capacity;
                break; // The knapsack is now full
            }
        }

        return totalValue;
    }
};