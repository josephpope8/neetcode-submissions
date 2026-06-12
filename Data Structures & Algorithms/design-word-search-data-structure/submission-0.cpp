class WordDictionary {
private:
    struct Node {
        vector<Node*> children{26, nullptr};
        bool isWord = false;
    };

    Node* root;

    bool recSearch(string w, int i, Node* curr){
        if(i == w.size()){
            return curr->isWord;
        }
        if(w[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(curr->children[j] != nullptr){
                    bool found = recSearch(w, i + 1, curr->children[j]);
                    if(found == true){
                        return true;
                    }
                }
            }
            return false;
        } else {
            if(curr->children[w[i] - 'a'] == nullptr){
                return false;
            }
            return recSearch(w, i + 1, curr->children[w[i] - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return recSearch(word, 0, root);
    }
};
