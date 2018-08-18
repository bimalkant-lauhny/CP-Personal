class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        for (int i=1; i<nums.size(); i += 2) {
            if (nums[i] < nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
            
            if (i+1 < nums.size() && nums[i] < nums[i+1]) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};
