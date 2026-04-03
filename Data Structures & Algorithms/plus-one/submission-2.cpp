class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        long long int sum = 0;

        for(int x: digits){
             sum = sum*10 + x;
        }
        sum += 1;

        vector<int> result;

        //cout<<sum<<endl;

        while(sum){

            result.push_back(sum%10);

            sum = sum/10;
        }

        reverse(result.begin(), result.end());

        return result;




        
    }
};
