class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // using Kadane's Algorithm
        if (nums.size() == 0) {
            return 0;
        }
        
        int maxGlobal, maxCurrent;
        maxGlobal = maxCurrent = nums[0];
        
        for (int i=1; i<nums.size(); ++i) {
            maxCurrent = max(nums[i], maxCurrent + nums[i]);
            maxGlobal = max(maxGlobal, maxCurrent);
        }
        
        return maxGlobal;
    }
};
