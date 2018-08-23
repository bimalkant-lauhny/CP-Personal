class Solution {
public:
    /**
     * @param s: the given string
     * @param numRows: the number of rows
     * @return: the string read line by line
     */
    string convert(string &s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string z (s.size(), ' ');
        vector <int> step {2 * (numRows - 1), 0};
        int i = 0, k = 0;
        while(k < numRows) {
           int j = k, a = 0;
           while(j < s.size()) {
                z[i++] = s[j];
                if (step[a] == 0)
                    a = !a;
                j += step[a];
                a = !a;
           }
           step[0] -= 2;
           step[1] += 2;
           ++k;
        }
        return z;
    }
};
