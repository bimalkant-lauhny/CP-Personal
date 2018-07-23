class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given number
     * @return:  whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k
     */
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        if (nums.size() < 2 || k == 0) {
            return false;
        }
        
        map <int, int> getIndex;
        bool res = false;
        
        for (int i=0; i<nums.size(); ++i) {
            if (getIndex.find(nums[i]) == getIndex.end()) {
                getIndex[nums[i]] = i;
            } else {
                int j = getIndex[nums[i]];
                if (i - j <= k) {
                    res = true;
                    break;
                }
                getIndex[nums[i]] = i;
            }
        }
        return res;
    }
};
