class Solution {
public:
    int searchInsert(vector<int>& V, int val) {
        int l = 0;
    int r = V.size();

    while(l<r){
        int mid = l + (r-l)/2;

        if(V[mid] < val){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return l;
        
    }
};