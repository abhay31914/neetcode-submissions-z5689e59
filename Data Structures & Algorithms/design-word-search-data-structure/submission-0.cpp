class WordDictionary {
private:

struct TrieNode{
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

TrieNode* root;

bool dfs(TrieNode* root, int start, string word){
    TrieNode* node = root;

    for(int i = start; i < word.size(); i++){

        char x = word[i];

        if(x == '.'){
            for(auto child: node->children){
                if(child && dfs(child, i+1, word)) return true;
            }
            return false;
        }
        else{
            if(!node->children[x-'a']) return false;
            node = node->children[x-'a'];
        }
    }
    return node->isEnd; 
}


public:
    WordDictionary() : root(new TrieNode){
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for(char x: word){

            int idx = x - 'a';

            if(!node->children[idx]){
                node->children[idx] = new TrieNode;
            }
            node = node->children[idx];
        }
        node->isEnd = true;
        
    }
    
    bool search(string word) {

        return dfs(root, 0, word);
        
    }
};
