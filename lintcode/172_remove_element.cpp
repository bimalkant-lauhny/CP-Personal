class Solution {
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int len = 0;
        for (int i=0; i<A.size(); ++i) {
            if (A[i] != elem) {
                A[len++] = A[i];
            }
        }
        return len;
    }
};
