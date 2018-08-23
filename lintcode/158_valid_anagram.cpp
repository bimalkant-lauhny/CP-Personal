class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
        vector<int> cnt(26, 0);
        
        for (auto const &i: s) {
            ++cnt[i - 'a'];
        }
        
        for (auto const &i: t) {
            --cnt[i - 'a'];
        }
        
        for (auto const &i: cnt) {
            if (i != 0)
                return false;
        }
        
        return true; 
    }
};
