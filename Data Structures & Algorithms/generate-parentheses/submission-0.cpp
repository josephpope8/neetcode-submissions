class Solution {
public:
    void backtrack(vector<string>& ans, string curr, int nO, int nC, int n){
        if(nO == n && nC == n){
            ans.push_back(curr);
            return;
        }
        if(nO < n){
            string newO = curr + '(';
            backtrack(ans, newO, nO + 1, nC, n);
        }
        if(nC < nO){
            string newC = curr + ')';
            backtrack(ans, newC, nO, nC + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};
