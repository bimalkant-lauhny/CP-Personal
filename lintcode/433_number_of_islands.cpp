class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // find connected components having 1 value
        
        if (grid.size() == 0)
            return 0;
            
        // visited array to maintain the visited pairs
        vector < vector<bool> > visited (grid.size(), 
            vector<bool>(grid[0].size(), false));
        
        // queue for BFS
        queue < pair<int, int> > q;
        
        // res stores number of connected components
        int res = 0;
        
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if (visited[i][j] || grid[i][j] == 0) {
                    // if pair already visited, or, pair value is not 1
                    continue;
                }
                
                // if not visited, the pair must belong to new component
                ++res;
                
                // run BFS to find this connected component
                q.push(make_pair(i, j));
                visited[i][j] = true;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    // check for reachable pairs from cur
                    int u = cur.first; int v = cur.second;
                    if (u-1 >= 0 && !visited[u-1][v] && grid[u-1][v] == 1) {
                        q.push(make_pair(u-1, v));
                        visited[u-1][v] = true;
                    }
                    if (v-1 >= 0 && !visited[u][v-1] && grid[u][v-1] == 1) {
                        q.push(make_pair(u, v-1));
                        visited[u][v-1] = true;
                    }
                    if (u+1 < grid.size() && !visited[u+1][v] && grid[u+1][v] == 1) {
                        q.push(make_pair(u+1, v));
                        visited[u+1][v] = true;
                    }
                    if (v+1 < grid[0].size() && !visited[u][v+1] && grid[u][v+1] == 1) {
                        q.push(make_pair(u, v+1));
                        visited[u][v+1] = true;
                    }
                }
            }
        }
        // return the number of components
        return res;
    }
};
