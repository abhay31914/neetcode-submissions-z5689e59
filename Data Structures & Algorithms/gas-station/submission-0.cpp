class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
    int n = gas.size();
    int fuel_Amount = 0;
    int start_pt = -1;

    int i = 0;

    while(i < 2*n){

        if(start_pt == i%n) return start_pt;

        if(fuel_Amount + gas[i%n] < cost[i%n]){ 
            start_pt = -1;
            fuel_Amount = 0;
        }

        else {
            fuel_Amount = fuel_Amount + gas[i%n] - cost[i%n];
            if(start_pt == -1) start_pt = i%n;
        }
        i++;
    }
    return -1;
        
    }
};
