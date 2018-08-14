class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    int lowerBound(vector<vector<int>> &matrix, int rc, int lu, int rd, int target, bool isRow) {
        int pos = isRow? matrix[0].size(): matrix.size();
        
        if (isRow) {
            if (target > matrix[rc][rd- 1]) {
               return pos; 
            }
        } else {
            if (target > matrix[rd-1][rc]) {
               return pos; 
            }
        }
        
        int mid;
        while(lu <= rd) {
            mid = lu + (rd - lu)/2;
            if (isRow) {
                if (matrix[rc][mid] >= target) {
                    pos = min(pos, mid);
                    rd = mid - 1;
                } else {
                    lu = mid + 1;
                }
            } else {
                if (matrix[mid][rc] >= target) {
                    pos = min(pos, mid);
                    rd = mid - 1;
                } else {
                    lu = mid + 1;
                }
            }
        }
        return pos;
    }
    
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        int i = 0, j = n - 1;  
        while (i < m && j >= 0) {
            i = lowerBound(matrix, j, i, m, target, false); 
            if (i == m)
                return false;
            if (matrix[i][j] == target)
                return true;
            --j;
            j = lowerBound(matrix, i, 0, j+1, target, true); 
            if (j == n) 
                return false;
            if (matrix[i][j] == target)
                return true;
            ++i;
        }
        return false;
    }
};
