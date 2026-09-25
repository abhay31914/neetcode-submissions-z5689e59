class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = heights.size()-1;

        int maxW = 0;

        while(l < r){

            maxW = max(maxW, min(heights[l], heights[r])*(r-l));

            if(heights[l] < heights[r]) l++;
            else{
                r--;
            }
        }

        return maxW;
        
    }
};
