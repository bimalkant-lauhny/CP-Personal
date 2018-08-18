class Solution {
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector <int> res; 
        
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        
        int n = matrix[0].size();
        
        
        int T = 0, B = m-1, L = 0, R = n-1;
        int dir = 0;
        
        
        while (T <= B && L <= R) {
            if (dir == 0) {
                // left to right
                for (int i=L; i<=R; ++i) {
                    res.push_back(matrix[T][i]);             
                }
                ++T;
                dir = 1; 
            } else if (dir == 1) {
                // top to bottom
                for (int i=T; i<=B; ++i) {
                    res.push_back(matrix[i][R]);
                }
                --R;
                dir = 2;
            } else if (dir == 2) {
                // right to left
                for (int i=R; i>=L; --i) {
                    res.push_back(matrix[B][i]);
                }
                --B;
                dir = 3;
            } else if (dir == 3) {
                // bottom to top
                for (int i=B; i>=T; --i) {
                    res.push_back(matrix[i][L]);
                }
                ++L;
                dir = 0;
            }
        }
        
        return res;
    }
};
