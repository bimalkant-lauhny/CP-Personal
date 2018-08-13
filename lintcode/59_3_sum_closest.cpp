class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        sort(numbers.begin(), numbers.end());
        int closest = numbers[0] + numbers[1] + numbers[numbers.size()-1];
        for (int i=0; i<numbers.size()-2; ++i) {
            int j = i+1, k = numbers.size() - 1;
            while (j < k) {
                int cursum = numbers[i] + numbers[j] + numbers[k];
                if (abs(target - cursum) < abs(target - closest)) { 
                    closest = cursum;
                }
                
                if (cursum == target) {
                    return cursum;
                } else if (cursum < target){
                    ++j;
                } else {
                    --k; 
                }
            }
        }
        return closest;
    }
};
