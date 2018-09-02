class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void minHeapify(vector<int> &A, int i) {
        int left = 2*i+1,
            right = left + 1;
        
        int smallest = i;
        
        if (left < A.size() && A[i] > A[left]) {
            smallest = left;
        }
        
        if (right < A.size() && A[smallest] > A[right]) {
            smallest = right;
        }
        
        if (smallest != i) {
            swap(A[i], A[smallest]);
            minHeapify(A, smallest);
        }
    }
    
    void heapify(vector<int> &A) {
        for (int i = A.size()/2 - 1; i >= 0; --i) {
            minHeapify(A, i);
        }
    }
};
