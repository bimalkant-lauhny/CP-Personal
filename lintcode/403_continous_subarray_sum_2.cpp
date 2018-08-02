class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        // use Kadane's algo
        // two cases
        // case 1: if not rotated has maxsum, then modified Kandane's algo is enough
        // case 2: if rotated has maxsum, then there must be some continous segment which should be removed from array. It must be minsum segment
        // compare the two, larger one is result
        
        vector<int> minRes{0, 0}, maxRes{0, 0};
        
        int minStart = 0, minEnd = 0, maxStart = 0, maxEnd = 0;
        int maxCurrent = 0, maxGlobal = INT_MIN, minCurrent = 0, minGlobal = INT_MAX;
        
        int totalSum = 0;
        
        for (int i=0; i<A.size(); ++i) {
            
            totalSum += A[i];
            
            if (maxCurrent < 0) {
                maxCurrent = A[i];
                maxStart = maxEnd = i;
            } else {
                maxCurrent += A[i];
                maxEnd = i;
            }
            
            if (maxCurrent > maxGlobal) {
                maxGlobal = maxCurrent;
                maxRes[0] = maxStart;
                maxRes[1] = maxEnd;
            }
            
            if (minCurrent > 0) {
                minCurrent = A[i];
                minStart = minEnd = i;
            } else {
                minCurrent += A[i];
                minEnd = i;
            }
            
            if (minCurrent < minGlobal) {
                minGlobal = minCurrent;
                minRes[0] = minStart;
                minRes[1] = minEnd;
            }
        }
        
        // handle the edge case when all elements are negative
        if (totalSum - minGlobal > maxGlobal && minRes[0] != 0 && minRes[1] != A.size()-1) {
            int temp = minRes[0];
            minRes[0] = minRes[1] + 1;
            minRes[1] = temp - 1;
            return minRes;
        } else {
            return maxRes;
        }
         
    }
};
