class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> found;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(found.count(comp)){
                return {found[comp], i};
            }
            found[nums[i]] = i;
        }
        return {};
    }
};
