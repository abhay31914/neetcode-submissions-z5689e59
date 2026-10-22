struct Node{
        int key;
        int val;
        Node* prev = nullptr;
        Node* next = nullptr;

        Node(int i, int j): key(i), val(j){}
    };

class LRUCache {

private:
    int limit;
    Node* head;
    Node* tail;

    unordered_map<int, Node*> map;

    void insert(Node* node){
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    
    LRUCache(int capacity): limit(capacity){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;        
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;

        Node* temp = map[key];
        remove(temp);
        insert(temp);

        return temp->val;
        
    }
    
    void put(int key, int value) {

        if(map.find(key) != map.end()){
            Node* oldNode = map[key];
            remove(oldNode);
            delete oldNode;
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        map[key] = newNode;

        if(map.size() > limit){
            Node* temp = tail->prev;
            remove(temp);
            map.erase(temp->key);
            delete temp;
        }

        
    }
};
