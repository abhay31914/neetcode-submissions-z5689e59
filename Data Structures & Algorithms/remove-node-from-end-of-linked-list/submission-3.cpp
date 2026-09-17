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

        ListNode* fst = head;

        for(int i = 0; i < n; i++){
            fst = fst->next;
        }

        ListNode* sec = head;
        ListNode* prev = nullptr;

        while(fst){
            prev = sec;
            fst = fst->next;
            sec = sec->next;
        }
        if(sec == head) head = head->next;

        else{
            prev->next = sec->next;
        }
        return head;


    
        
    }
};
