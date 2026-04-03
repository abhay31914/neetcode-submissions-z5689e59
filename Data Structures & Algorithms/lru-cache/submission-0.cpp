class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int i, int j): key(i), value(j), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache_map;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;       
    }
    
    int get(int key) {

        if(cache_map.find(key) == cache_map.end()) return -1;

        Node* tempNode = cache_map[key];
        remove(tempNode);
        add(tempNode);
        return tempNode->value;        
    }
    
    void put(int key, int value) {

        if(cache_map.find(key) != cache_map.end()){
            Node* oldNode = cache_map[key];
            remove(oldNode);
            delete oldNode;
        }

        Node* newNode = new Node(key, value);
        add(newNode);
        cache_map[key] = newNode;

        if(cache_map.size() > capacity){
            Node* todelete = tail->prev;
            cache_map.erase(todelete->key);
            remove(todelete);
            delete todelete;
        }
        
    }

    void add(Node* node){
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};
