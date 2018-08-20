class Solution {
public:
    /**
     * @param matrix: a lists of integers
     * @return: nothing
     */
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        
        if (n == 0) {
            return;
        }
        
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (auto &v: matrix) {
            reverse(v.begin(), v.end());
        }
    }
};
