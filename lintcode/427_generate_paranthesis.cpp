class Solution {
    private:
        vector <string> wellFormedParan;
        int n;
    public:
        /**
         * @param n: n pairs
         * @return: All combinations of well-formed parentheses
         */
        vector<string> generateParenthesis(int n) {
            this->n = n;
            string s = "(";
            recursiveParanGen(s, 1, 0);
            return this->wellFormedParan;
        }

        void recursiveParanGen(string s, int lp, int rp) {
            if (rp == this->n) {
                wellFormedParan.push_back(s);
                return;
            } 

            if (lp < this->n) {
                recursiveParanGen(s + "(", lp + 1, rp);
            }

            if (rp < lp) {
                recursiveParanGen(s + ")", lp, rp + 1);
            }
        }
};
