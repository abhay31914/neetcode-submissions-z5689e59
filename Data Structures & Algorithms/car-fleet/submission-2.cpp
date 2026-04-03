class Solution {
public:
    //using tracker variable prev & cur
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> cPair;
        int n = position.size();
        for(int i = 0; i< n; i++){
            cPair.push_back({position[i], speed[i]});
        }
        sort(cPair.rbegin(), cPair.rend());

        int fleet = 1;
        double prevTime = (double)(target-cPair[0].first)/cPair[0].second;

        for(int i= 1; i< n; i++){
            double curTime = (double)(target-cPair[i].first)/cPair[i].second;

            if(curTime > prevTime){
                fleet++;
                prevTime = curTime;
            }
        }

    return fleet;    
    }
};
