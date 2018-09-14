class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int left = 0, right = 0, zeroCount = !nums[right], maxWindow = 0;
        while(right < nums.size()) {
            if (zeroCount <=1 ) {
                ++right;
                maxWindow = max(maxWindow, right - left);
                if (right == nums.size())
                    break;
                if (nums[right] == 0)
                    ++zeroCount;
            } else {
                if (nums[left] == 0) 
                    --zeroCount;
                ++left;
            }
        }
        
        return maxWindow;
    }
};
