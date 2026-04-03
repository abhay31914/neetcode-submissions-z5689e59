class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) return 0;

        int base = 0;
        int mid = 1;
        int latest = 1;

        for(int i=3; i<= n; i++){
            int temp = latest+mid+base;

            base = mid;
            mid = latest;
            latest = temp;
        }
        return latest;
        
    }
};