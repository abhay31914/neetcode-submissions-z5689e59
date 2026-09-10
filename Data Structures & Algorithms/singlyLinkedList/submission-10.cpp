struct Node{
    int val;
    Node* next;

    Node(int x = -1): val(x){
        next = nullptr;
    }
};

class LinkedList {

private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
        
    }

    int get(int index) {

        Node* temp = head;

        if(!temp) return -1;

        for(int i = 0; i< index; i++){
            if(!temp) return -1;
            temp = temp->next;
        }
        return temp ? temp->val : -1;

    }

    void insertHead(int val) {

        Node* temp = new Node(val);

        temp->next = head;
        head = temp;
        
    }
    
    void insertTail(int val) {

        if(!head){
            head = new Node(val);
            return;
        }

        Node* temp = head;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = new Node(val);

    }

    bool remove(int index) {

        if(!head) return false;

        Node* prev = nullptr;
        Node* cur = head;

        for(int i = 0; i< index; i++){
            if(!cur) return false;
            prev = cur;
            cur = cur->next;
        }
        if(!cur) return false;
        if(prev) prev->next = cur->next;

        else{
            head = cur->next;
        }

        delete cur;
        cur = nullptr;  

        return true;      
    }

    vector<int> getValues() {

        vector<int> result;

        Node* temp = head;

        while(temp){
            result.push_back(temp->val);
            temp = temp->next;
        }

        return result;
        
    }
};
