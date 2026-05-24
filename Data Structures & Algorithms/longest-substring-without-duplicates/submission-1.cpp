class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int maxL = 0;
        int ind = 0;
        for(int i = 0; i < s.size(); i++){
            if(seen.count(s[i])){
                for(int j = ind; j < seen[s[i]]; j++){
                    seen.erase(s[j]);
                }
                ind = seen[s[i]] + 1;
                seen[s[i]] = i;
            } else {
                if(i - ind + 1 > maxL){
                    maxL = i - ind + 1;
                }
                seen[s[i]] = i;
            }
        }
        return maxL;
    }
};
