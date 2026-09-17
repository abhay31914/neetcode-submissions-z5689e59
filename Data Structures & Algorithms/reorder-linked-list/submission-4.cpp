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
    ListNode* reverse(ListNode* head){

        ListNode* cur = head;
        ListNode* prev = nullptr;

        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
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
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* head2 = reverse(mid);

        while(head2){
            ListNode* nxt1 = head->next;
            ListNode* nxt2 = head2->next;

            head->next = head2;
            head2->next = nxt1;

            head = nxt1;
            head2 = nxt2;
        }
        
    }
};
