class Solution {
public:
    /**
     * @param num: a positive integer
     * @return: if num is a perfect square else False
     */
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        int squareRoot = 1;
        int start = 1, end = num/2;
        int mid = 0;
        long long guessroot;
        while(start <= end) {
            mid = end  - (end - start) / 2;
            guessroot = (long long)mid * (long long)mid; 
            if (guessroot == (long long)num) {
                return true;
            }
            
            if (guessroot < (long long)num) {
                start = mid + 1;
            } else {
                end = mid - 1; 
            }
        }
        return false;
    }
};
