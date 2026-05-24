/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        stack<ListNode*> st;
        while(secondHalf){
            st.push(secondHalf);
            secondHalf = secondHalf->next;
        }
        ListNode* curr = head;
        while(!st.empty()){
            ListNode* top = st.top();
            st.pop();
            ListNode* temp = curr->next;
            curr->next = top;
            top->next = temp;
            curr = temp;
        }
    }
};
