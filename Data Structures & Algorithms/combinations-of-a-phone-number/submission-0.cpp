class Solution {
private:
    unordered_map<char, vector<char>> map;
public:
    void backtrack(vector<string>& ans, string& stack, string& digits, int i){
        if(i == digits.length()){
            ans.push_back(stack);
            return;
        }
        for(auto c : map[digits[i]]){
            stack.push_back(c);
            backtrack(ans, stack, digits, i + 1);
            stack.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string st = "";
        backtrack(ans, st, digits, 0);
        return ans;
    }
};
