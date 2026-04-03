class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int count5 = 0;
        int count10 = 0;

        for(int x: bills){

            if(x == 5) count5++;

            else if(count5 < 1) return false;

            else if(x == 10){
                    count10++;
                    count5--;
            }
            else{
                if(count5 < 3 && count10 < 1) return false;

                if(count10 >= 1){
                    count10--;
                    count5--;
                }
                else{
                    count5 -= 3;
                }
            }
            
        }
        return true;
        
    }
};