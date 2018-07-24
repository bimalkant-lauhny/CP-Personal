class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int median = nums[n/2];
        
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[newIndex(i, n)] < median) {
                swap(nums[newIndex(right,n)], nums[newIndex(i,n)]);
                --right;
            } else if (nums[newIndex(i, n)] > median) {
                swap(nums[newIndex(left,n)], nums[newIndex(i,n)]);
                ++left;
                ++i;
            } else {
                ++i; 
            }
        }
    }
    
    int newIndex(int i, int n) {
        return (1 + 2*i) % (n|1);
    }
};
