class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        for(int i = 0; i < s.size(); i++){
            f1[s[i] - 'a']++;
            f2[t[i] - 'a']++;
        }
        return f1 == f2;
    }
};
