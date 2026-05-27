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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return nullptr;
        }
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head;
        if(curr1->val <= curr2->val){
            head = curr1;
            curr1 = curr1->next;
        } else {
            head = curr2;
            curr2 = curr2->next;
        }
        ListNode* prev = head;
        while(curr1 && curr2){
            if(curr1->val <= curr2->val){
                prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;
            } else {
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
        }
        while(curr1){
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        while(curr2){
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
        return head;
    }
};
