class Solution {
    public:
        /**
         * @param A: an array
         * @return: total of reverse pairs
         */
        long long reversePairs(vector<int> &A) {
            return mergeSort(A, 0, A.size() - 1);
        }

        int mergeSort(vector <int> &A, int l, int r) {
            int invCnt = 0;
            if (l >= r)
                return invCnt;

            int m = l + (r - l) / 2;
            invCnt += mergeSort(A, l, m);
            invCnt += mergeSort(A, m + 1, r);

            // merge
            vector <int> T ( r - l + 1);
            int i=l, j=m+1, k = 0;
            while (i <= m && j <= r) {
                if (A[i] <= A[j]) {
                    T[k] = A[i];
                    ++i;
                } else {
                    T[k] = A[j];
                    invCnt += (m - i + 1);
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

            return invCnt;
        }
};
