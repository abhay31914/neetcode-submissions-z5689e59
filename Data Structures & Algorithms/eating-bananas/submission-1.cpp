class Solution {
public:

    int max_ele(vector<int>& piles){
        int res = piles[0];
        for(int i = 1; i< piles.size(); i++){
            res = max(piles[i], res);
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int minV = 1;
        int maxV = max_ele(piles);
        int ans = maxV;

        while(minV <= maxV){
            int mid = (minV + maxV)/2;

            long long time = 0;

            for(int x: piles){
                time+= (x+ mid -1)/mid;
            }

            if(time <= h){
                ans = mid;
                maxV = mid-1;
            }
            else{
                minV = mid+1;
            }

        }
        return ans;
        
    }
};
