class Solution {
public:
    bool bfs(string word, vector<vector<char>>& board, int curr, int r1, int c1, vector<vector<bool>>& visited){
        if(curr == word.size()){
            return true;
        }
        for(int r = -1; r <= 1; r++){
            for(int c = -1; c <= 1; c++){
                if(!(abs(r) == abs(c)) && r1 + r >= 0 && r1 + r < board.size() && c1 + c >= 0 && c1 + c < board[0].size() && !visited[r1 + r][c1 + c]){
                    if(word[curr] == board[r + r1][c + c1]){
                        visited[r + r1][c + c1] = true;
                        if(bfs(word, board, curr + 1, r + r1, c + c1, visited)){
                            return true;
                        }
                        visited[r + r1][c + c1] = false;
                    }
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    if(bfs(word, board, 1, i, j, visited)){
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
