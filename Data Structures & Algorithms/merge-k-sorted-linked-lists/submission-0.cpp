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

 struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* result = new ListNode();

        for(auto ele: lists){
            pq.push(ele);
        }
        ListNode* temp = result;

        while(!pq.empty()){
            ListNode* node = pq.top();

            pq.pop();

            temp->next = node;

            if(node->next){
                pq.push(node->next);
            }
            temp = temp->next; 
        }

        return result->next;
        
    }
};
