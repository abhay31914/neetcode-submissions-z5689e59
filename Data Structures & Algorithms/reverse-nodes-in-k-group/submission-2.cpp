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
    int getLength(ListNode* head){

    int size =0;

    while(head){
        head = head->next;
        size++;
    }
    return size;
}

pair<ListNode*, ListNode*> reverse(ListNode* head, int k){

    ListNode* lastS = head;
    ListNode* prev = nullptr;
    ListNode* cur = head;

    int i = 0;

    while(i < k){
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        i++;
    }
    lastS->next = cur;
    return {prev, lastS};
}


ListNode* reverseKGroup(ListNode* head, int k){

    int size = getLength(head);

    int n = size/k;

    ListNode* Thead = new ListNode(-1);
    Thead->next = head;

    ListNode* temp = Thead;
    
    int i = 0;

    while(i < n){

        auto X = reverse(temp->next, k);

        temp->next = X.first;
        temp = X.second;
        i++;
    }
    return Thead->next;       
}
};
