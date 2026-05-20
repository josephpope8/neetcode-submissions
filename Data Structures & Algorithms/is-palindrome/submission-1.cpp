class Solution {
public:
    bool isPalindrome(string s) {
        string news = "";
        for(char c : s){
            c = tolower(c);
            if(c >= 'a' && c <= 'z' || (c >= '0' && c <= '9')){
                news += c;
            }
        }
        s = news;
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};
