class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int s = -1, n = nums.size();
        for (int i=n-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                s = i; break;
            }
        }
        
        if (s == -1) {
            sort(nums.begin(), nums.end());
            return nums;
        }
        
        sort(nums.begin()+s+1, nums.end());
        for (int i=s+1; i<n; ++i) {
            if (nums[i] > nums[s]) {
                swap(nums[i], nums[s]);
                break;
            }
        }
        return nums;
    }
};
