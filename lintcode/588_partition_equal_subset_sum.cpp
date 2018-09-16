class Solution {
public:
    /**
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (auto const &a: nums) {
            sum += a;
        }
        
        if (sum % 2 == 1) {
            // sum is odd, no partition possible!
            return false;
        }
        
        int w = sum/2;
        int n = nums.size();
        
        vector<vector<bool>> ss (n+1, vector<bool>(w+1));
        
        for (int i=0; i<=n; ++i) {
            ss[i][0] = true;
        }
         
        for (int j=1; j<=w; ++j) {
            ss[0][j] = false;
        }
        
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=w; ++j) {
                if (nums[i] > j) {
                    // element has value larger than sum required
                    ss[i][j] = ss[i-1][j];
                } else {
                    ss[i][j] = ss[i-1][j] || ss[i-1][j-nums[i]];
                }
            }
        } 
        
        return ss[n][w];
    }
};
