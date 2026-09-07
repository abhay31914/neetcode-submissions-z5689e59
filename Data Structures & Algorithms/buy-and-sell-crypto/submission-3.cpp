class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int b = INT_MAX;
        int s = 0;

        for(int x: prices){
            s = max(s, x-b);
            b = min(b, x);
        }

        return s;
        
    }
};
