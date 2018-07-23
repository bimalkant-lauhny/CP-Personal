class Solution {
public:
    /**
     * @param nums: the given array
     * @return: if any value appears at least twice in the array
     */
    bool containsDuplicate(vector<int> &nums) {
        map <int, bool> present;
        bool res = false;
        
        for (auto const &i: nums) {
            if (present.find(i) == present.end()) {
                present[i] = true;
            } else {
                res = true;
                break;
            }
        }
        
        return res;
    }
};
