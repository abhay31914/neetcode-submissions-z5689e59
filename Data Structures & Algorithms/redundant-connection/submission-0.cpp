class DSU{
    public:

    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i< n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;       
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){

        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return true;

        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
        else{
            parent[pb] = pa;
            rank[pb] += rank[pa];
        }
    return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){

    int size = edges.size();
    DSU dsu(size);

    for(auto &edge : edges){

        int a = edge[0]-1;
        int b = edge[1]-1;

        if(dsu.unite(a, b)) return {a+1, b+1};
    }
    return {};
}

};
