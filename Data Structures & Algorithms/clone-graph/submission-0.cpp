/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<int, Node*> seen;
        unordered_set<int> processed;
        Node* newFirst = new Node(node->val);
        processed.insert(node->val);
        seen[1] = newFirst;
        queue<Node*> p;
        p.push(node);
        while(!p.empty()){
            Node* front = p.front();
            p.pop();
            for(Node* n : front->neighbors){
                if(!seen.count(n->val)){
                    Node* newN = new Node(n->val);
                    seen[n->val] = newN;
                }
                seen[front->val]->neighbors.push_back(seen[n->val]);
                if(!processed.count(n->val)){
                    p.push(n);
                    processed.insert(n->val);
                }
            }
        }
        return newFirst;
    }
};
