class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(),
            n = obstacleGrid[0].size();
        
        obstacleGrid[0][0] = !obstacleGrid[0][0];
        
        for (int i=1; i<m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                obstacleGrid[i][0] = 0;
                continue;
            }
            obstacleGrid[i][0] = obstacleGrid[i-1][0];
        }
        
        for (int j=1; j<n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                obstacleGrid[0][j] = 0;
                continue;
            }
            obstacleGrid[0][j] = obstacleGrid[0][j-1];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = !obstacleGrid[i][j];
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
                }
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }
};
