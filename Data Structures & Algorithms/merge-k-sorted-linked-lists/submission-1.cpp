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

 class cmp{
    public:
    bool operator()(ListNode* first, ListNode* second){
        return first->val > second->val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* dummy_head = new ListNode(-1);
        ListNode* temp = dummy_head;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto node: lists){
            pq.push(node);
        }

        while(!pq.empty()){

            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;

            if(node->next){
                pq.push(node->next);
            }

            temp = temp->next;            
        }

        return dummy_head->next;
        
    }
};
