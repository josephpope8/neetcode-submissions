class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int i, int sum, int target){
        if(i == nums.size()){
            return;
        }
        if(sum + nums[i] == target){
            curr.push_back(nums[i]);
            ans.push_back(curr);
            curr.pop_back();
        } else if(sum + nums[i] < target){
            curr.push_back(nums[i]);
            sum += nums[i];
            for(int j = i; j < nums.size(); j++){
                backtrack(ans, nums, curr, j, sum, target);
            }
            sum -= nums[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> c;
        for(int i = 0; i < nums.size(); i++){
            backtrack(ans, nums, c, i, 0, target);
        }
        return ans;
    }
};
