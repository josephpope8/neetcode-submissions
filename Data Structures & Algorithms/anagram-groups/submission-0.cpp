class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqMap;
        for(string s : strs){
            vector<int> freq(26, 0);
            for(char c : s){
                freq[c - 'a']++;
            }
            string key = to_string(freq[0]);
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(freq[i]);
            }
            freqMap[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& p : freqMap){
            ans.push_back(p.second);
        }
        return ans;
    }
};
