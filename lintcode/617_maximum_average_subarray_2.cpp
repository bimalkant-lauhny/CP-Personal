class Solution {
    public:
        /*
         * @param nums: an array with positive and negative numbers
         * @param k: an integer
         * @return: the maximum average
         */

        double maxAverage(vector<int> &nums, int k) {
            double start = INT_MAX, 
                   end = INT_MIN, 
                   mid;
            for (auto const& i: nums) {
                start = min(start, static_cast<double>(i));
                end = max(end, static_cast<double>(i));
            }

            double precision = 1e-6;
            while ((end - start) > precision) {
                mid = start + (end - start)/2;
                vector <double> prefixSum (nums.size() + 1, 0);
                for (int i=0; i<nums.size(); ++i) {
                    prefixSum[i+1] = prefixSum[i] + (nums[i] - mid);
                }

                double prefixSumMax = INT_MIN, 
                       prefixSumMin = 0;
                for (int i=k; i<prefixSum.size(); ++i) {
                    prefixSumMax = max(prefixSumMax, prefixSum[i] - prefixSumMin);
                    prefixSumMin = min(prefixSumMin, prefixSum[i - k + 1]);
                }

                if(prefixSumMax == 0) {
                    return mid;
                } else if (prefixSumMax < 0) {
                    // means mid is larger than maxAvg
                    end = mid;
                } else {
                    // means mid is smaller that maxAvg
                    start = mid;
                }
            }

            return start;
        }
};
