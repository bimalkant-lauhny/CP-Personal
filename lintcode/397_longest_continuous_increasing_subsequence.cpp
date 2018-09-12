class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        if (A.size() == 0)
            return 0;
            
        int ascMax = 1, ascCur = 1;
        int desMax = 1, desCur = 1; 
        for (int i=1; i<A.size(); ++i) {
            if (A[i]>A[i-1]) {
                ++ascCur; 
            } else {
                ascMax = max(ascMax, ascCur);
                ascCur = 1;
            }
            
            if (A[i]<A[i-1]) {
                ++desCur; 
            } else {
                desMax = max(desMax, desCur);
                desCur = 1;
            }
        }
        ascMax = max(ascMax, ascCur); 
        desMax = max(desMax, desCur); 
        
        return max(ascMax, desMax); 
    }
};
