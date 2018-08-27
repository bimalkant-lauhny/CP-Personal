class Solution {
public:
    /**
     * @param n: The integer
     * @return: Roman representation
     */
     
    string intToRoman(int n) {
        vector <string> r {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        vector<int> v {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string res;
        for (int i=0; i<v.size(); ++i) {
            while (n >= v[i]) {
                n -= v[i];
                res += r[i];
            }
        }
        
        return res;
    }
};
