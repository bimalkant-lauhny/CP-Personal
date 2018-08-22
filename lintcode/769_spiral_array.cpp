class Solution {
public:
    /**
     * @param n: a Integer
     * @return: a spiral array
     */
    vector<vector<int>> spiralArray(int n) {
        vector< vector <int> > arr (n, vector<int>(n));
        int T = 0, B = n-1, L = 0, R = n-1;
        int dir = 0;
        int v = 1;
        while (T<=B && L<=R) {
            if (dir == 0) {
                // left to right 
                for (int i=L; i<=R; ++i) {
                    arr[T][i] = v;
                    ++v;
                }
                ++T;
                dir = 1;
            } else if (dir == 1) {
                // top to bottom 
                for (int i=T; i<=B; ++i) {
                    arr[i][R] = v;
                    ++v;
                }
                --R;
                dir = 2;
            } else if (dir == 2) {
                // right to left 
                for (int i=R; i>=L; --i) {
                    arr[B][i] = v;
                    ++v;
                }
                --B;
                dir = 3;
            } else if (dir == 3) {
                // bottom to top 
                for (int i=B; i>=T; --i) {
                    arr[i][L] = v;
                    ++v;
                }
                ++L;
                dir = 0;
            } 
        }
        
        return arr;
    }
};
