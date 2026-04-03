/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head){

    if(head == nullptr) return nullptr;

    unordered_map<Node* , Node*> Rmap;
    unordered_map<Node* , Node*> Omap;

    Node* newHead = new Node(head->val);
    Node* oldCurr = head->next;
    Node* newCurr = newHead;
    
    Rmap[newHead] = head->random;
    Omap[head] = newHead;

    while(oldCurr){

        newCurr->next = new Node(oldCurr->val);
        
        Rmap[newCurr->next] = oldCurr->random;
        Omap[oldCurr] = newCurr->next;

        newCurr = newCurr->next;
        oldCurr = oldCurr->next; 
    }

    Node* temp = newHead;

    while(temp){

        if(Rmap[temp] == nullptr) temp->random = nullptr;

        else{
            temp->random = Omap[Rmap[temp]];
        }
        temp = temp->next;
    }
    return newHead;
}
};
