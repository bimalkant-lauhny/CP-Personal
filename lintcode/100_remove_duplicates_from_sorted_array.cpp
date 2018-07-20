class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        
        int len = 1;
        
        for (int i=1; i<nums.size(); ++i) {
            if (nums[len-1] < nums[i]){
                nums[len] = nums[i];
                ++len;
            }
        }
        
        return len;
    }
};
