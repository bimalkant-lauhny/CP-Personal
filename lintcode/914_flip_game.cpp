class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        vector<string> result;
        for(int i = s.size() - 1; i>0; --i) {
            if (s[i] == '+' && s[i-1] == '+') {
                s[i] = '-'; s[i-1] = '-';
                result.push_back(s);
                s[i] = '+'; s[i-1] = '+';
            }
        }
        return result;
    }
};
