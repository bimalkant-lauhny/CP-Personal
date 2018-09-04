class Solution {
public:
    /**
     * @param nums: the given array
     * @return:  the number of triplets chosen from the array that can make triangles
     */
    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int validTriangles = 0;
        for (int i=0; i<n-2; ++i) {
            
            if(nums[i] == 0)
                continue;
            
            int k = i+2; 
            for (int j=i+1; j<n-1; ++j) {
                while(k < n && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                validTriangles += (k - j - 1);
            }
        }
        return validTriangles;
    }
};
