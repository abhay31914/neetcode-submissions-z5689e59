class Solution {
public:
    vector<int> partitionLabels(string s){

    unordered_map<char, pair<int, int>> map;

    int n = s.size();

    for(int i = 0; i< n; i++){
        if(map.find(s[i]) != map.end()){
            map[s[i]].second = i;
        }
        else{
            map[s[i]].first = i;
            map[s[i]].second = i;
        }
    }
    vector<pair<char, pair<int,int>>> vec(map.begin(), map.end());

    sort(vec.begin(), vec.end(),
     [](const auto& a, const auto& b) {
         return a.second.first < b.second.first;
     });

    //printVector(vec);

    vector<pair<int, int>> intervals;

    intervals.push_back({-1, -1});

    for(const auto& [key, value]: vec){

        pair<int, int> x = intervals.back();

        if(value.first > x.second) intervals.push_back(value);

        else{
            intervals.pop_back();
            intervals.push_back({min(x.first, value.first), max(x.second, value.second)});
        }
    }

    vector<int> result;

    for(int i = 1; i < intervals.size(); i++){
        result.push_back(intervals[i].second - intervals[i].first +1);
    }

    return result;
        
}
};
