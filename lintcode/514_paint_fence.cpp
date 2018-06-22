class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if (n == 0)
            return 0;
            
        int diff = k;
        int same = 0;
        int total = diff + same;
        
        for (int i=2; i<=n; ++i) {
            same = diff;
            diff  = total * (k-1);
            total = diff + same;
        }
        
        return total;
    }
};
