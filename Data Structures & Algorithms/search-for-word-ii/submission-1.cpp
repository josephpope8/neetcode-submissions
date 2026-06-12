class Solution {
private:
    struct Node {
        vector<Node*> children{26, nullptr};
        int isWord = -1;
    };

    Node* root;

    void addWord(string word, int ind){
        Node* curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = ind;
    }

    void dfs(vector<vector<char>>& board, Node* curr, vector<string>& res, vector<string>& words, int r, int c, vector<bool>& found, vector<vector<bool>>& visited){
        if(curr == nullptr){
            return;
        }
        if(curr->isWord != -1 && !found[curr->isWord]){
            res.push_back(words[curr->isWord]);
            found[curr->isWord] = true;
        }
        if(r > 0 && !visited[r - 1][c]){
            visited[r - 1][c] = true;
            dfs(board, curr->children[board[r - 1][c] - 'a'], res, words, r - 1, c, found, visited);
            visited[r - 1][c] = false;
        }
        if(r < board.size() - 1 && !visited[r + 1][c]){
            visited[r + 1][c] = true;
            dfs(board, curr->children[board[r + 1][c] - 'a'], res, words, r + 1, c, found, visited);
            visited[r + 1][c] = false;
        }
        if(c > 0 && !visited[r][c - 1]){
            visited[r][c - 1] = true;
            dfs(board, curr->children[board[r][c - 1] - 'a'], res, words, r, c - 1, found, visited);
            visited[r][c - 1] = false;
        }
        if(c < board[0].size() - 1 && !visited[r][c + 1]){
            visited[r][c + 1] = true;
            dfs(board, curr->children[board[r][c + 1] - 'a'], res, words, r, c + 1, found, visited);
            visited[r][c + 1] = false;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        vector<string> res;
        vector<bool> found(words.size(), false);
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < words.size(); i++){
            addWord(words[i], i);
        }

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                visited[r][c] = true;
                dfs(board, root->children[board[r][c] - 'a'], res, words, r, c, found, visited);
                visited[r][c] = false;
            }
        }
        return res;
    }
};
