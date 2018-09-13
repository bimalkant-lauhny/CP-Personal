class Solution {
    public:
        /**
         * @param A: an integer array
         * @param target: An integer
         * @param k: An integer
         * @return: an integer array
         */
        vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
            vector<int> kclosest;
            if (k == 0) {
                return kclosest;
            }

            int p = lower_bound(A.begin(), A.end(), target) - A.begin();

            if (p < A.size() && p > 0) {
                if (abs(A[p] - target) >= abs(A[p-1] - target))
                    --p;
            } else if (p == A.size()) {
                --p;
            }

            kclosest.push_back(A[p]);
            int i=1;
            int l = p - 1;
            int r = p + 1;
            while (i < k && l >= 0 && r < A.size()) {
                if (abs(A[l] - target) <= abs(A[r] - target)) {
                    kclosest.push_back(A[l]);
                    --l;
                } else {
                    kclosest.push_back(A[r]);
                    ++r;
                }
                ++i;
            }

            while (i < k && l>=0) {
                kclosest.push_back(A[l]);
                --l;
                ++i;
            }

            while (i < k && r<A.size()) {
                kclosest.push_back(A[r]);
                ++r;
                ++i;
            }

            return kclosest;
        }
};
