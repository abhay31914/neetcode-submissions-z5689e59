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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

    if(left == right) return head;

    ListNode* dummy = new ListNode(0, head);

    ListNode* lTemp = dummy;

    int count = 1;

    while(count < left){
        lTemp = lTemp->next;

        count++;
    }

    ListNode* prev = nullptr;
    ListNode* cur = lTemp->next;

    while(count < right){
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;

        count++;
    }
    lTemp->next->next = cur->next;
    cur->next = prev;
    lTemp->next = cur;

    return dummy->next;       
}
};