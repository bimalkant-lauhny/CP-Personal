class Solution {
public:
    /**
     * @param s: the string that represents a number
     * @return: whether the string is a valid number
     */
    bool isNumber(string &s) {
        enum INPUT_TYPE {
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPO
        }; 
        
        vector < vector <int> > trans {
            {0, 1, 2, 9, -1},
            {-1, -1, 2, 3, -1},
            {8, -1, 2, 3, 5},
            {8, -1, 4, -1, 5},
            {8, -1, 4, -1, 5},
            {-1, 6, 7, -1, -1},
            {-1, -1, 7, -1, -1},
            {8, -1, 7, -1, -1},
            {8, -1, -1, -1, -1},
            {-1, -1, 4, -1, -1}
        };
        
        int state = 0; 
        for (int i=0; i<s.size(); ++i) {
            int input; 
            if (s[i] == ' ')
                input = SPACE;
            else if (s[i] == '+' || s[i] == '-')
                input = SIGN;
            else if (s[i] >= '0' && s[i] <= '9')
                input = DIGIT;
            else if (s[i] == '.')
                input = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                input = EXPO;
            else
                return false;
                
            state = trans[state][input];
            if (state == -1)
                return false;
        }
        if (state == 2 || state == 3 || state == 4 || state == 7 || state == 8) 
            return true;
        else 
            return false;
    }
};
