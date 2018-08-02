class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // using Kadane's Algo to find Max Sum Subarray
        // but we've to return indexes
        // the idea is to reset both indexes whenver maxCurrent is -ve
        // update only end index if maxCurrent is +ve 
         
        vector <int> res {0, 0};
        int maxGlobal = A[0];
        int maxCurrent = A[0];
        int start = 0, end = 0;
        for (int i=1; i<A.size(); ++i) {
            if (maxCurrent < 0) {
                // NOTE if A[i] is -ve, maxCurrent + A[i] < A[i]
                maxCurrent = A[i];
                start = end = i;
            } else {
                maxCurrent += A[i];
                end = i;
            }
            if (maxGlobal < maxCurrent) {
                maxGlobal = maxCurrent;
                res[0] = start;
                res[1] = end;
            }
        }
        
        return res;
    }
};
