class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> track(n, false);
        vector<int> degree(n, 0);

        for(auto &t : trust){
            track[t[0]-1] = true;
            degree[t[1]-1]++;
        }

        for(int i = 0; i< n; i++){
            if(track[i] == false && degree[i] == n-1) return i+1;
        }
        return -1;       
    }
};