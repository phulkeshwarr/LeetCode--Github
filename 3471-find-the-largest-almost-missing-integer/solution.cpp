class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sub_count(51, 0);
        
        // 1. Iterate through every starting index of a subarray of size k
        for (int i = 0; i <= n - k; i++) {
            vector<bool> seen(51, false);
            
            // 2. Mark which elements are present in the current subarray
            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }
            
            // 3. Increment the global subarray count for these elements
            for (int x = 0; x <= 50; x++) {
                if (seen[x]) {
                    sub_count[x]++;
                }
            }
        }
        
        // 4. Find the largest integer that appears in exactly one subarray
        for (int x = 50; x >= 0; x--) {
            if (sub_count[x] == 1) {
                return x;
            }
        }
        
        return -1;
    }
};