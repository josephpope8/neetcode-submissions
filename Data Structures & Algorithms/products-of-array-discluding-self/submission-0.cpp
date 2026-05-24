class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZ = 0;
        int prod = 1;
        int locZ;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(x == 0){
                numZ++;
                locZ = i;
            } else {
                prod *= x;
            }
        }
        if(numZ >= 2){
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        if(numZ == 1){
            vector<int> ans(nums.size(), 0);
            ans[locZ] = prod;
            return ans;
        }
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            ans[i] = prod/nums[i];
        }
        return ans;
    }
};
