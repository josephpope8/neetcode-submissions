class PrefixTree {
private:
    struct Node {
        vector<Node*> children{26, nullptr};
        bool isWord = false;
    };
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char ch : word){
            if(curr->children[ch - 'a'] == nullptr){
                Node* newL = new Node();
                curr->children[ch - 'a'] = newL;
            }
            curr = curr->children[ch - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char ch : word){
            if(curr->children[ch - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch : prefix){
            if(curr->children[ch - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return true;
    }
};
