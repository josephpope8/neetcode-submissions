class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < board.size(); r++){
            unordered_set<char> seen;
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == '.'){
                    continue;
                }
                if(seen.count(board[r][c])){
                    return false;
                }
                seen.insert(board[r][c]);
            }
        }
        for(int c = 0; c < 9; c++){
            unordered_set<char> seen;
            for(int r = 0; r < 9; r++){
                if(seen.count(board[r][c])){
                    return false;
                }
                if(board[r][c] != '.'){
                    seen.insert(board[r][c]);
                }
            }
        }
        for(int r = 0; r <= 6; r += 3){
            for(int c = 0; c <= 6; c += 3){
                unordered_set<char> seen;
                for(int r1 = 0; r1 < 3; r1++){
                    for(int c1 = 0; c1 < 3; c1++){
                        if(seen.count(board[r + r1][c + c1])){
                            return false;
                        }
                        if(board[r + r1][c + c1] != '.'){
                            seen.insert(board[r + r1][c + c1]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
