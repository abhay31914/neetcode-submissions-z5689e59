class Node{
    public:
    int val;
    Node* next;

    Node(int n, Node* node=nullptr ): val(n), next(node){}
    Node() = delete;
};

class MyHashSet{

    vector<Node*> hash;
    const int SIZE = 100;

    int hashFunc(int key){
        return key % SIZE;
    }

    public:
    MyHashSet(): hash(SIZE, nullptr) {}
    
    void add(int key) {

        int index = hashFunc(key);

        Node* cur = hash[index];

        while(cur){
            if(cur->val == key) return;
            cur = cur->next;
        }
        hash[index] = new Node(key, hash[index]);    
    }
    
    void remove(int key) {

        int index = hashFunc(key);

        Node* cur = hash[index];
        Node* prev = nullptr;

        while(cur && cur->val != key){
            prev = cur;
            cur = cur->next;
        }
        if(!cur) return;

        if(prev){
            prev->next = cur->next;
        }
        else{
            hash[index] = cur->next;
        }
        delete cur;
        cur = nullptr;   
    }
    
    bool contains(int key) {

        int index = hashFunc(key);

        Node* cur = hash[index];

        while(cur){
            if(cur->val == key) return true;
            cur = cur->next;
        }
        return false;   
    }

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */