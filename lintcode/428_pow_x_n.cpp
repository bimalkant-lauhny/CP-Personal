class Solution {
    public:
        /*
         * @param x: the base number
         * @param n: the power number
         * @return: the result
         */
        double myPow(double x, int n) {
            double result = 1;
            double base = x;
            long long expt = n;

            if (n < 0) {
                base = 1.0/base;
                expt = abs(expt);
            }

            while (expt) {
                if (expt & 1) {
                    result *= base; 
                }
                base *= base;
                expt = expt >> 1;
            }

            return result;
        }
};
