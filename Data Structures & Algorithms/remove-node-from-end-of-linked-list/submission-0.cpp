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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;

        for(int i = 0; i< n; i++){
            fast = fast->next;
        }

        ListNode* slow = head;
        ListNode* prev = nullptr;

        while(fast){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        
        if(slow == head){
            head = head->next;
        }
        
        else{
            prev->next = slow->next;
            delete slow;
            slow = nullptr;
        }
        return head;
        
    }
};
