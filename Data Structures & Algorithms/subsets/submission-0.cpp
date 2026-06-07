class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int i, unordered_set<int>& seen){
        ans.push_back(curr);
        if(i == nums.size()){
            return;
        }
        for(int j = i; j < nums.size(); j++){
            if(seen.count(nums[j])){
                continue;
            }
            curr.push_back(nums[j]);
            seen.insert(nums[j]);
            backtrack(ans, curr, nums, j + 1, seen);
            seen.erase(nums[j]);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_set<int> seen;
        backtrack(ans, curr, nums, 0, seen);
        return ans;
    }
};
