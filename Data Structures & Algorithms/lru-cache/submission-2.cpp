struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int i, int j): key(i), val(j), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache_map;

    void addNode(Node* node){
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
    LRUCache(int capacity): cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {

        if(cache_map.find(key) == cache_map.end()) return -1;

        Node* node = cache_map[key];
        remove(node);
        addNode(node);
        return node->val;        
    }
    
    void put(int key, int value) {

        if(cache_map.find(key) != cache_map.end()){
            Node* oldNode = cache_map[key];
            remove(oldNode);
            delete oldNode;
        }

        Node* toAdd = new Node(key, value);

        addNode(toAdd);
        cache_map[key] = toAdd;

        if(cache_map.size() > cap){
            Node* toRemove = tail->prev;
            remove(toRemove);
            cache_map.erase(toRemove->key);
            delete toRemove;
        }
        
    }
};
