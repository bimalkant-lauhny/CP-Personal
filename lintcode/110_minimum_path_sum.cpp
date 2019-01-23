class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid[0].size(),
            m = grid.size();
            
        for (int j=1; j<n; ++j){
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i=1; i<m; ++i){
            grid[i][0] += grid[i-1][0];
        }
        
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};
