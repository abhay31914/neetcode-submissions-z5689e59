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

        ListNode* slow= head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = nullptr;

        ListNode* head2 = reverse(temp);


        while(head && head2){
            ListNode* temp1 = head->next;
            ListNode* temp2 = head2->next;

            head->next = head2;
            head2->next = temp1;

            head = temp1;
            head2 = temp2;
        }
        
    }
};
