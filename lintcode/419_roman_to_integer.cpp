class Solution {
public:
    /**
     * @param s: Roman representation
     * @return: an integer
     */
    int romval(char c) {
        switch (c) {
           case 'I': return 1;
           case 'V': return 5;
           case 'X': return 10;
           case 'L': return 50;
           case 'C': return 100;
           case 'D': return 500;
           case 'M': return 1000;
        }
        return -1;
    }
    
    int romanToInt(string &s) {
        int res = romval(s[0]);
        for (int i=1; i<s.size(); ++i) {
            int cur = romval(s[i]), prev = romval(s[i-1]);
            if (prev >= cur) {
                res += cur;
            } else {
                res -= (2*prev);
                res += cur; 
            }
        }
        return res;
    }
};
