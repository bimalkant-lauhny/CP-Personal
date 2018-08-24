class Solution {
    public:
        /**
         * @param A: an integer array
         * @return: nothing
         */
        void sortIntegers2(vector<int> &A) {
            mergeSort(A, 0, A.size()-1);
        }

        void mergeSort(vector <int> &A, int l, int r) {
            if (l >= r)
                return;

            int m = l + (r - l) / 2;
            mergeSort(A, l, m);
            mergeSort(A, m + 1, r);

            // merge
            vector <int> T ( r - l + 1);
            int i=l, j=m+1, k = 0;
            while (i <= m && j <= r) {
                if (A[i] <= A[j]) {
                    T[k] = A[i];
                    ++i;
                } else {
                    T[k] = A[j];
                    ++j;
                }
                ++k;
            }

            while (i<=m) {
                T[k] = A[i];
                ++i;
                ++k;
            }

            while(j <= r) {
                T[k] = A[j];
                ++j;  
                ++k;
            }

            for(int i=l; i<=r; ++i) {
                A[i] = T[i - l];
            }
        }
};
