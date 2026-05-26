class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> RtL(n, 0);
        vector<int> LtR(n, 0);

        int Rmax = 0;
        int Lmax = 0;

        for(int i= n-1; i>=0; i--){
            Rmax = max(Rmax, height[i]);
            RtL[i] = Rmax- height[i];
        }

        for(int i =0; i< n; i++){
            Lmax = max(Lmax, height[i]);
            LtR[i] = Lmax - height[i];
        }

        int count = 0;

        for(int i = 0; i< n; i++){
            count+= min(RtL[i], LtR[i]);
        }
        return count;
        
    }
};
