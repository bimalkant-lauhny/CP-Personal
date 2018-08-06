class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: nothing
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size(), s = -1;
        for (int i=n-2; i>=0; --i) {
            if (nums[i] < nums[i+1]) {
                s = i;
                break;
            }
        }
        
        sort(nums.begin()+s+1, nums.end());
        
        if (s != -1) {
            for (int i = s+1; i<n; ++i) {
                if (nums[i] > nums[s]) {
                    swap(nums[i], nums[s]);
                    break;
                }
            } 
        }
    }
};
