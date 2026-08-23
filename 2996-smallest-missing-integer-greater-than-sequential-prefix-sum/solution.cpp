class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // 1. Calculate the sum of the longest sequential prefix

        
        int prefixSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];