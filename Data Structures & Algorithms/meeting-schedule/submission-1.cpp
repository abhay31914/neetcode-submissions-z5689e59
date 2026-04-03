/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        int n = intervals.size();

        vector<pair<int, int>> vec;

        for(auto x: intervals){
            vec.push_back({x.start, x.end});
        }

        sort(vec.begin(), vec.end());

        for(int i = 1; i< n; i++){
            if(vec[i].first < vec[i-1].second) return false;
        }
    return true;       
} 
};
