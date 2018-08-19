class Solution {
    public:
        /*
         * @param A: An integer array
         * @param B: An integer array
         * @return: a double whose format is *.5 or *.0
         */
        double findMedianSortedArrays(vector<int> &A, vector<int> &B) {

            if (A.size() > B.size()) {
                return findMedianSortedArrays(B, A);    
            }

            int lenA = A.size(),
                lenB = B.size();

            int start = 0, 
                end = lenA;

            int partitionA, partitionB;

            int maxLeftA, maxLeftB;

            int minRightA, minRightB;

            while (start <= end) {

                partitionA = (start + end)/2;
                partitionB = (lenA + lenB + 1) / 2 - partitionA;

                maxLeftA = (partitionA > 0) ? A[partitionA - 1]: INT_MIN;
                minRightA = (partitionA < lenA) ? A[partitionA]: INT_MAX;

                maxLeftB = (partitionB > 0) ? B[partitionB - 1]: INT_MIN;
                minRightB = (partitionB < lenB) ? B[partitionB]: INT_MAX;

                if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                    if ((lenA + lenB) % 2 != 0) {
                        return  static_cast <double> (max(maxLeftA, maxLeftB));
                    } else {
                        return (static_cast <double> (max(maxLeftA, maxLeftB)) + 
                                static_cast <double> (min(minRightA, minRightB))) / 2.0;
                    }
                } else if (maxLeftA > minRightB){
                    end = partitionA - 1;
                } else {
                    start = partitionA + 1;
                }

            }
        }
};
