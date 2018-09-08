class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> countSmaller(vector<int> &nums) {
        vector <int> smCount (nums.size());
        if (nums.size() == 0) {
            return smCount;
        }
        
        descretize(nums);
        
        vector <int> bit (nums.size() + 1);
        
        for (int i = nums.size()-1; i >= 0; --i) {
            smCount[i] = getCount(bit, nums[i] - 1);
            bitUpdate(bit, nums[i]);
        }
        
        return smCount;
    }
    
    void descretize(vector<int> & nums) {
        vector<int> newnums (nums);
        sort(newnums.begin(), newnums.end());
        unordered_map<int, int> newnumsIndex;

        int j = 1;
        newnumsIndex[newnums[0]] = j;
        for (int i=1; i<newnums.size(); ++i) {
            if (newnumsIndex.find(newnums[i]) == newnumsIndex.end()) {
                ++j;
            }
            newnumsIndex[newnums[i]] = j;
        }

        for (int i=0; i<nums.size(); ++i) {
            nums[i] = newnumsIndex[nums[i]];
        }
    }
    
    void bitUpdate(vector<int> &bit, int index) {
        for (int i = index; i < bit.size(); i += (i & (-i))) {
            ++bit[i];
        }
    }
    
    int getCount(vector<int> const &bit, int index) {
        int count = 0;
        for (int i = index; i > 0; i -= (i & (-i))) {
            count += bit[i];
        }
        return count;
    }
};