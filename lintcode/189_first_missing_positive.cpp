class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> &A) {
        int i = 0;
        while (i < A.size()) {
            if (A[i] > 0 && A[i] <= A.size()) {
                int idx = A[i] - 1;
                if (A[idx] != A[i]) {
                    swap(A[idx], A[i]);
                    continue;
                }
            }
            ++i;
        }
        
        for (int i=0; i<A.size(); ++i) {
            if (A[i] != i+1) {
                return i+1;
            }
        }
        
        return A.size()+1;
    }
};
