class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(abs(l - r) > 1){
            int mid = (l + r)/2;
            if(nums[mid] > nums[r]){
                l = mid;
            } else {
                r = mid;
            }
        }
        int lc = l;
        int hc = r;
        l = 0;
        r = lc;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = hc;
        r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
