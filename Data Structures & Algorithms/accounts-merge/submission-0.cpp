class DSU{
    public:
    vector<int> parent;

    DSU(int n){
        parent.resize(n);
        for(int i=0; i< n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int a, int b){
        
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            parent[pb] = pa;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

    int size = accounts.size();
    unordered_map<string ,int> mail_map;
    DSU dsu(size);
    
    for(int i = 0; i< size; i++){
        for(int j = 1; j< accounts[i].size(); j++){
            string mail = accounts[i][j];
            
            if(mail_map.find(mail) != mail_map.end()){
                dsu.unite(i, mail_map[mail]);
            }
            else{
                mail_map[mail] = i;
            }
        }
    }

    unordered_map<int, set<string>> merged;

    for(auto &[mail, idx] : mail_map){
        int root = dsu.find(idx);
        merged[root].insert(mail);
    }

    vector<vector<string>> result;

    for(auto &[idx, mails]: merged){
        vector<string> temp;
        temp.push_back(accounts[idx][0]);
        temp.insert(temp.end(), mails.begin(), mails.end());
        result.push_back(temp);
    }

    return result;
}

};