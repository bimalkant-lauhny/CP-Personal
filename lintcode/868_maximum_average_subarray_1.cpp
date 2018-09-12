class Solution {
    public:
        /**
         * @param nums: an array
         * @param k: an integer
         * @return: the maximum average value
         */
        double findMaxAverage(vector<int> &nums, int k) {
            int i = 0;
            double subarrSum = 0;
            while (i<k) {
                subarrSum += nums[i];
                ++i;
            }

            double maxSubarrSum = subarrSum;
            while(i<nums.size()) {
                subarrSum -= nums[i-k];
                subarrSum += nums[i];
                maxSubarrSum = max(maxSubarrSum, subarrSum);
                ++i;
            }

            return maxSubarrSum / k;
        }
};
