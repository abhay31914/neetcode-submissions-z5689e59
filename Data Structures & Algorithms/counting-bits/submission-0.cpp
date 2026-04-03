class Solution {
public:
    
    int one(int n){
        int result = 0;
        while(n > 0){
            result += n & 1;
            n >>= 1;
        }
        return result;
    }

    vector<int> countBits(int n) {

        vector<int> result;

        for(int i = 0; i< n+1; i++){
            int temp = one(i);
            result.push_back(temp);
        }  
        return result;      
    }
};
