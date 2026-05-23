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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* lp1 = l1;
        ListNode* lp2 = l2;
        int first = l1->val + l2->val;
        if(first >= 10){
            first -= 10;
            carry = 1;
        }
        ListNode* curr = new ListNode(first);
        ListNode* head = curr;
        lp1 = lp1->next;
        lp2 = lp2->next;
        while(lp1 && lp2){
            int v = lp1->val + lp2->val + carry;
            if(v >= 10){
                v -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* newN = new ListNode(v);
            curr->next = newN;
            curr = newN;
            lp1 = lp1->next;
            lp2 = lp2->next;
        }
        while(lp1){
            int v = lp1->val + carry;
            if(v == 10){
                v = 0;
            } else {
                carry = 0;
            }
            ListNode* newN = new ListNode(v);
            curr->next = newN;
            curr = newN;
            lp1 = lp1->next;
        }
        while(lp2){
            int v = lp2->val + carry;
            if(v == 10){
                v = 0;
            } else {
                carry = 0;
            }
            ListNode* newN = new ListNode(v);
            curr->next = newN;
            curr = newN;
            lp2 = lp2->next;
        }
        if(carry){
            ListNode* end = new ListNode(1);
            curr->next = end;
        }
        return head;
    }
};
