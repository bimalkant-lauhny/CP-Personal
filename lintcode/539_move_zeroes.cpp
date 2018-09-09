class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        int slow = 0;
        for (int fast=0; fast<nums.size(); ++fast) {
            if (nums[fast] != 0) {
                if (nums[slow] == 0) {
                    nums[slow] = nums[fast];
                    nums[fast] = 0;
                }
                ++slow;
            }
        }
    }
};
