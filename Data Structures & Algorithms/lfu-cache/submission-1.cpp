struct Node{
    int key;
    int val;
    int freq;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int i, int j): key(i), val(j), freq(1){}
};

class DLL{
public:
    int size;
    Node* head;
    Node* tail;

    DLL(): size(0){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void insertFront(Node* node){
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;

        size++;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        size--;
    }

    Node* removeLast(){
        Node* temp = tail->prev;
        remove(temp);

        return temp;
    }
};

class LFUCache 
{
private:
    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    void updateFreq(Node* node){
        int idx = node->freq;

        freqMap[idx]->remove(node);

        if(idx == minFreq && freqMap[idx]->size == 0){
            minFreq++;
        }
        node->freq++;

        if(freqMap.find(node->freq) == freqMap.end()){
            freqMap[node->freq] = new DLL();
        }
        freqMap[node->freq]->insertFront(node);
    }

public:
    LFUCache(int capacity): capacity(capacity), minFreq(0){}
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end()) return -1;
        
        updateFreq(keyMap[key]);
        return keyMap[key]->val;        
    }
    
    void put(int key, int value) {

        if(keyMap.find(key) != keyMap.end())
        {
            keyMap[key]->val = value;

            updateFreq(keyMap[key]);
            return;
        }

        if(keyMap.size() == capacity)
        {
            Node* temp = freqMap[minFreq]->removeLast();
            keyMap.erase(temp->key);
            delete temp;
        }

        Node* temp = new Node(key, value);
        keyMap[key] = temp;

        minFreq = 1;

        if(freqMap.find(minFreq) == freqMap.end())
        {
            freqMap[minFreq] = new DLL();
        }

        freqMap[minFreq]->insertFront(temp);
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */