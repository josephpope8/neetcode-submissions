class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        unordered_map<char, int> freq;
        int letters = s1.length();
        for(char c : s1){
            freq[c]++;
        }
        for(int i = 0; i < s1.length(); i++){
            if(freq.count(s2[i])){
                if(freq[s2[i]] > 0){
                    letters--;
                }
                freq[s2[i]]--;
            }
        }
        int l = 0;
        if(letters == 0){
            return true;
        }
        for(int i = s1.length(); i < s2.size(); i++){
            if(freq.count(s2[l])){
                if(freq[s2[l]] >= 0){
                    letters++;
                }
                freq[s2[l]]++;
            }
            if(freq.count(s2[i])){
                if(freq[s2[i]] > 0){
                    letters--;
                }
                freq[s2[i]]--;
            }
            if(letters == 0){
                return true;
            }
            l++;
        }
        return false;
    }
};
