class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        
        vector<vector<int>> up(m, vector<int>(n));
        
        fill(up[0].begin(), up[0].end(), 1);
        for (int i=1; i<m; ++i){
            up[i][0] = 1;
        }
        
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                up[i][j] = up[i-1][j] + up[i][j-1];
            }
        }
        
        return up[m-1][n-1];
    }
};
