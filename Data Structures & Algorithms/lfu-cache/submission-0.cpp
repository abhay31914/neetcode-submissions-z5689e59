class Node{
public:
    int key;
    int val;
    int freq;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int k, int v): key(k), val(v), freq(1){}
};

class DLL{
public:
    int size;
    Node* head;
    Node* tail;

    DLL(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insertFront(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
        size++;    
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast(){
        if(size == 0) return nullptr;

        Node* node = tail->prev;
        remove(node);
        return node;
    }
};

class LFUCache {
private:
    int capacity;
    int minFreq;
    int currSize;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    void updateFreq(Node* node){

        int freq = node->freq;

        freqMap[freq]->remove(node);

        if(freq == minFreq && freqMap[freq]->size == 0){
            minFreq++;
        }

        node->freq++;

        if(freqMap.find(node->freq) == freqMap.end()){
            freqMap[node->freq] = new DLL();
        }

        freqMap[node->freq]->insertFront(node);
    }

public:
    LFUCache(int cap){
        capacity = cap;
        currSize = 0;
        minFreq = 0;
    }
    
    int get(int key){

        if(keyMap.find(key) == keyMap.end()) return -1;

        Node* node = keyMap[key];
        updateFreq(node);

        return node->val;
        
    }
    
    void put(int key, int value){

        if(keyMap.find(key) != keyMap.end()){
            Node* node = keyMap[key];
            node->val = value;

            updateFreq(node);
            return;
        }

        if(currSize == capacity){

            Node* node = freqMap[minFreq]->removeLast();
            keyMap.erase(node->key);
            currSize--;
        }

        Node* node = new Node(key, value);

        minFreq = 1;

        if(freqMap.find(1) == freqMap.end()){
            freqMap[1] = new DLL();
        }
        freqMap[minFreq]->insertFront(node);
        keyMap[key] = node;

        currSize++;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */