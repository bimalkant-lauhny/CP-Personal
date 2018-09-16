class NumArray {
    vector<int> rangesums;
public:
    NumArray(vector<int> nums) {
        rangesums.push_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) {
            rangesums.push_back(rangesums[i-1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return rangesums[j];
        } else {
            return rangesums[j] - rangesums[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
