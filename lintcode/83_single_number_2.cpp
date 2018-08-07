class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        int n = sizeof(int)*8, res = 0;
        //cout << n << endl;
        for (int i=0; i<n; ++i) {
            int ibits = 0;
            for (auto const &e: A) {
                if (e & (1<<i))
                    ++ibits;
            }
            //cout << ibits << endl;
            if (ibits % 3 == 1) {
                res += (1<<i);
            }
        }
        
        return res;
    }
};
