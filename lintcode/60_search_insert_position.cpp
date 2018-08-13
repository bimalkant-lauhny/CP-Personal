class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        
        if (A.size() == 0 || A[0] >= target)
            return 0;
            
        if (A[A.size()-1] < target)
            return A.size();
            
        int start = 0, end = A.size() - 1;
        while (start < end) {
            int mid = start + (end - start)/2;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};
