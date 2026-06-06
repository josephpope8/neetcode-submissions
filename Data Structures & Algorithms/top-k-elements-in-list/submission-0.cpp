class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        map<int, vector<int>> reverseFreq;
        for(auto& it : freq){
            reverseFreq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(auto it = reverseFreq.rbegin(); it != reverseFreq.rend(); ++it){
            for(int x : it->second){
                ans.push_back(x);
                k--;
                if(k == 0){
                    return ans;
                }
            }
        }
        return ans;
    }
};
