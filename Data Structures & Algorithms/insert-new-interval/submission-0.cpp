class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() == 0) return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    
    vector<int> temp = intervals[0];

    result.push_back(temp);

    for(int i = 1; i< intervals.size(); i++){

        temp = result.back();

        if(temp[1] < intervals[i][0]) {
            result.push_back(intervals[i]);
        }
        else{
            if(temp[1] < intervals[i][1]){
                result.pop_back();
                result.push_back({temp[0], intervals[i][1]});
            }
        }
    }
    return result;
        
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.push_back(newInterval);

        return merge(intervals);
        
    }
};
