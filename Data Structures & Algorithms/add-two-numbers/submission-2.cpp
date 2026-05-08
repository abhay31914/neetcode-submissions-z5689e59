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

        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;

        int carry = 0;

        while(l1 || l2 || carry){

            int val1 = l1 ? l1->val: 0;
            int val2 = l2 ? l2->val: 0;

            int sum = val1 + val2 + carry;

            temp->next = new ListNode(sum%10);
            carry = sum> 9 ? 1: 0;

            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return dummyHead->next;
        
    }
};
