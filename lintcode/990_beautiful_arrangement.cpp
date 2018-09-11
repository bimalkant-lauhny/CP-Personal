class Solution {
    public:
        /**
         * @param N: The number of integers
         * @return: The number of beautiful arrangements you can construct
         */
        int recCount(int N, int i, vector<bool>& inc) {
            if (i > N)
                return 1;
            int cnt = 0;
            for(int j=1; j<=N; ++j) {
                // check if element satisfies condition and already in inc
                if ((i % j == 0 || j % i == 0) && 
                        (inc[j] == false)) {
                    inc[j] = true;
                    cnt += recCount(N, i+1, inc);
                    inc[j] = false;
                }
            }
            return cnt;
        }

        int countArrangement(int N) {
            vector <bool> inc(N+1, false);
            return recCount(N, 1, inc);
        }
};
