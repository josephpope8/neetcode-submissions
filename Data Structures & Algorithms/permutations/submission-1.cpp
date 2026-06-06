class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, unordered_set<int>& used, int num, vector<int>& st){
        if(num == nums.size()){
            ans.push_back(st);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used.count(nums[i])){
                used.insert(nums[i]);
                st.push_back(nums[i]);
                backtrack(ans, nums, used, num + 1, st);
                st.pop_back();
                used.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> used;
        vector<int> st = {};
        backtrack(ans, nums, used, 0, st);
        return ans;
    }
};
