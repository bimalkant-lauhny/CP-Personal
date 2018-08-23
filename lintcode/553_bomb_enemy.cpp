class Solution {
    public:
        /**
         * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
         * @return: an integer, the maximum enemies you can kill using one bomb
         */
        int maxKilledEnemies(vector<vector<char>> &grid) {
            int m = grid.size();
            int n = m ? grid[0].size(): 0;
            if (m == 0 || n == 0) {
                return 0;
            }

            int res = 0;
            int rowKills = 0, colKills[n] = {0};

            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (j == 0 || grid[i][j-1] == 'W') {
                        rowKills = 0;
                        for (int k=j; k<n && grid[i][k]!='W'; ++k) {
                            if (grid[i][k] == 'E') {
                                ++rowKills;
                            }
                        }
                    }

                    if (i == 0 || grid[i-1][j] == 'W') {
                        colKills[j] = 0;
                        for (int k=i; k<m && grid[k][j]!='W'; ++k) {
                            if (grid[k][j] == 'E') {
                                ++colKills[j];
                            }
                        }
                    }

                    if (grid[i][j] =='0') {
                        res = max(res, rowKills + colKills[j]);
                    }
                }
            }

            return res;
        }
};
