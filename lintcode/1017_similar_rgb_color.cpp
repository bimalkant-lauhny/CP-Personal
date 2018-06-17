class Solution {
    public:
        /**
         * @param color: the given color
         * @return: a 7 character color that is most similar to the given color
         */

        int nearestIndex(int const &val) {
            int ind = 0;
            int similarity = 256;
            for (int i=0; i<16; ++i) {
                int newval = abs((16 * i + i) - val);
                if (similarity > newval) {
                    similarity = newval;
                    ind = i;
                }            
            }
            return ind;
        }

        string similarRGB(string &color) {

            std::map<char, int> H2D;
            for (char i='0'; i<='9'; ++i)
                H2D[i] = i - '0';
            H2D['a'] = 10; H2D['b'] = 11; H2D['c'] = 12; H2D['d'] = 13; 
            H2D['e'] = 14; H2D['f'] = 15;

            std::map<int, char> D2H;
            for (char i=0; i<=9; ++i)
                D2H[i] = static_cast<char>(i + '0');
            D2H[10] = 'a'; D2H[11] = 'b'; D2H[12] = 'c'; D2H[13] = 'd'; 
            D2H[14] = 'e'; D2H[15] = 'f';  

            string result = "#";

            // for 1st two hexx
            int val = 16 * H2D[color[1]] + H2D[color[2]];
            int ind = nearestIndex(val);
            result += D2H[ind];
            result += D2H[ind];

            // for 2nd two hexx
            val = 16 * H2D[color[3]] + H2D[color[4]];
            ind = nearestIndex(val);
            result += D2H[ind];
            result += D2H[ind];

            // for 3rd two hexx
            val = 16 * H2D[color[5]] + H2D[color[6]];
            ind = nearestIndex(val);
            result += D2H[ind];
            result += D2H[ind];

            return result;
        }
};
