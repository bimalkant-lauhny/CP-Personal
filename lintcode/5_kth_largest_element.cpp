class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int> &nums, int start, int end) {
        // find position of pivot in sorted array
        int pivot = nums[end];
        int slow = start -1, fast = start;
        while (fast < end){
            if (nums[fast] < pivot) {
                ++slow;
                swap(nums[fast], nums[slow]);
            }
            ++fast;
        }
        ++slow;
        swap(nums[slow], nums[end]);
        return slow;
    }
    
    int kthLargestElement(int n, vector<int> &nums) {
        int desiredIndex = nums.size() - n;
        
        /* using nth_element() function
        nth_element(nums.begin(), nums.begin()+desiredIndex, nums.end());
        return nums[desiredIndex];
        */
        
        // using quickselect algo 
        int start = 0, end = nums.size() - 1;
        int pivotIndex = -1;
        while (desiredIndex != pivotIndex) {
            pivotIndex = partition(nums, start, end); 
            if (pivotIndex < desiredIndex) {
                start = pivotIndex + 1;  
            } else if (pivotIndex > desiredIndex){
                end = pivotIndex - 1; 
            }
        }
        return nums[desiredIndex];
    }
};
