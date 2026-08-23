class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // 1. Calculate the sum of the longest sequential prefix
        int prefixSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break; // Stop at the first non-sequential element
            }
        }
        
        // 2. Store all array elements in a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer greater than or equal to 
        prefixSum
        while (numSet.count(prefixSum)) {
            prefixSum++;
        }
        
        return prefixSum;
    }
};