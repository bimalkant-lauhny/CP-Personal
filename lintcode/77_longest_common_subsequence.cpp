class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        int m = A.size(), n = B.size();
        if (m == 0 or n == 0) {
            return 0;     
        }
        
        vector<vector<int>> lcs(m+1, vector<int>(n+1)); 
        
        for (int i=0; i<=m; ++i)
            lcs[i][0] = 0;
            
        for (int j=0; j<=n; ++j)
            lcs[0][j] = 0;
        
        for (int i = 1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (A[i-1] != B[j-1]) {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                } else {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
            }
        }
        
        return lcs[m][n];
    }
};
