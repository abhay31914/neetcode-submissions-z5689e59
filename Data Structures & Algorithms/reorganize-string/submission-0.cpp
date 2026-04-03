class Solution {
public:
    string reorganizeString(string s){

    int maxCount = 0;
    int size = s.size();
    vector<int> count(26, 0);


    for(char x: s){
        count[x-'a']++;
        maxCount = max(maxCount, count[x-'a']);
    }

    if(maxCount > (size +1)/2) return "";

    priority_queue<pair<int, char>> pq;

    for(int i = 0; i< 26; i++){
        if(count[i]){
            pq.push({count[i], 'a'+i});
        }
    }

    string str= "";

    while(pq.size() > 1){
        
        pair<int, char> x = pq.top();
        str += x.second;
        pq.pop();

        pair<int, char> y = pq.top();
        str += y.second;
        pq.pop();

        if(x.first -1 > 0) pq.push({x.first -1, x.second});
        if(y.first -1 > 0) pq.push({y.first -1, y.second});
    }

    if(!pq.empty()){
        pair<int, char> x = pq.top();
        str += x.second;
        pq.pop();
    }
    return str;   
}
};