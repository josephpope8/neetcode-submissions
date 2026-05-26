class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size();
        while(l < r){
            int mid = (l + r)/2;
            if(mid == 0 || nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            if(nums[mid] > nums[l]){
                l = mid;
            } else {
                r = mid;
            }
        }
        return nums[0];
    }
};
