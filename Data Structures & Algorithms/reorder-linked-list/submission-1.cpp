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

    ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;

    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

void reorderList(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);

    ListNode* front = head;

    while(slow->next){
        ListNode* temp = front->next;

        front->next = slow->next;

        slow->next = slow->next->next;

        front->next->next = temp;

        front = temp;
    }

}
};
