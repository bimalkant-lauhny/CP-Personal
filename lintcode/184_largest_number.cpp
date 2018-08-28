class Solution {
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    
    string largestNumber(vector<int> &nums) {
        if (nums.size() == 0) {
            return "0";
        }
        
        vector <string> strnums(nums.size()); 
        for (int i=0; i<nums.size(); ++i) {
            strnums[i] = to_string(nums[i]);
        }
        
        sort(strnums.begin(), strnums.end(), [](string s1, string s2){
            if ((s1+s2) > (s2+s1)) {
                return true;    
            } else {
                return false;
            }
        });
        
        if (strnums[0].compare("0") == 0) {
            return "0";
        }
        
        string res = "";
        for (string const &s: strnums) {
            res += s;    
        }
        
        return res; 
    }
};
