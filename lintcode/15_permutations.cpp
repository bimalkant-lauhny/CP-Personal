// recursive solution
class Solution {
public:

    vector<vector<int>> res;
    vector<bool> used;
    vector<int> cur;
    vector<int> nums;
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */ 
    bool allUsed() {
        for (int i=0; i<used.size(); ++i) {
            if (used[i] == false) {
                return false;
            }
        }
        return true;
    }
    
    void recurse(int depth) {
        if (allUsed()) {
            res.push_back(cur);
            return;
        }
        
        for (int i=0; i<used.size(); ++i) {
            if (used[i] == false) {
                cur[depth] = nums[i];
                used[i] = true;
                recurse(depth+1);
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() <= 1) {
            res.push_back(nums);
            return res;
        } 
        
        // write your code here
        this->nums = nums;
        this->used.resize(nums.size());
        fill(this->used.begin(), this->used.end(), false);
        this->cur.resize(nums.size());
        recurse(0);
        return res; 
    }
};

// non recursive solution


