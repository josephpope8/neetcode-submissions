/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        Node* newHead = new Node(head->val);
        Node* it = head->next;
        Node* curr = newHead;
        m[head] = newHead;
        while(it){
            Node* newN = new Node(it->val);
            curr->next = newN;
            curr = newN;
            m[it] = newN;
            it = it->next;
        }
        curr = newHead;
        it = head;
        while(it){
            curr->random = m[it->random];
            it = it->next;
            curr = curr->next;
        }
        return newHead;
    }
};
