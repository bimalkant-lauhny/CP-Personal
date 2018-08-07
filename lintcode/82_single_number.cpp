class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int res = 0;
        for (int const &i: A) {
            res ^= i;
        }
        return res;
    }
};
