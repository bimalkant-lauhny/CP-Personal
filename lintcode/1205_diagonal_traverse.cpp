class Solution {
public:
    /**
     * @param matrix: a 2D array
     * @return: return a list of integers
     */
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res; 
        }
        int n = matrix[0].size();
        
        int lastRev = false; 
        for (int i=0; i<n; ++i) {
            vector <int> v;
            int r = 0, c = i;
            while(r < m && c >= 0) {
                v.push_back(matrix[r][c]);
                ++r;
                --c;
            }
            
            if (!lastRev) {
                reverse(v.begin(), v.end());
            }
            lastRev = !lastRev;
            for (auto const &i: v) {
                res.push_back(i);
            }
        }
        
        for (int j=1; j<m; ++j) {
            vector <int> v;
            int r = j, c = n-1;
            while(r < m && c >= 0) {
                v.push_back(matrix[r][c]);
                ++r;
                --c;
            }
            if (!lastRev) {
                reverse(v.begin(), v.end());
            }
            lastRev = !lastRev;
            for (auto const &i: v) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
