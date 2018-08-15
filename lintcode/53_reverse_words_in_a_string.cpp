class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        string res = "", cur;
        if (s.size() == 0)
            return res;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ' ') {
                if (cur.size() > 0) {
                    if (res.size() > 0)
                        cur += " ";
                    res = cur + res;
                }
                cur = "";
            } else {
                cur += s[i];
            }
        }
        
        if (cur.size() > 0) {
            if (res.size() > 0)
                cur += " ";
            res = cur + res;
        }
        return res;
    }
};
