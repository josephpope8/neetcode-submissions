class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int sum, int i, int target){
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(i == nums.size()){
            return;
        }
        unordered_set<int> seen;
        for(int j = i; j < nums.size(); j++){
            if(sum + nums[j] > target || seen.count(nums[j])){
                continue;
            }
            seen.insert(nums[j]);
            curr.push_back(nums[j]);
            backtrack(ans, nums, curr, sum + nums[j], j + 1, target);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, candidates, curr, 0, 0, target);
        return ans;
    }
};
