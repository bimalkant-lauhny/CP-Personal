class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> findDuplicates(vector<int> &nums) {
        
        // elements are from 1 to n
        nums.insert(nums.begin(), 0);
        
        vector <int> duplicates;
        for (int i=1; i<nums.size(); ++i) {
            int index = abs(nums[i]);
            if (nums[index] < 0) {
                duplicates.push_back(index);
            } else {
                nums[index] = -nums[index];
            }
        }
        
        fill(nums.begin(), nums.end(), 0);
        for (int i=0; i<duplicates.size(); ++i) {
            nums[duplicates[i]] = 1;
        }
        duplicates.clear();
        
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                duplicates.push_back(i);
            }
        }
        
        return duplicates;
    }
};
