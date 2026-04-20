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
    ListNode* addTwoNumbers(ListNode* l1 , ListNode* l2){

    int carry = 0;
    ListNode* head = new ListNode(-1);
    ListNode* temp = head;

    while(l1 || l2){
        int val1 = 0, val2 = 0;

        if(l1) val1 = l1->val;
        if(l2) val2 = l2->val;

        int s = val1 + val2 + carry;

        temp->next = new ListNode(s%10);

        carry = s/10;

        temp = temp->next;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }

    if(carry) temp->next = new ListNode(carry);

    return head->next;
}
};
