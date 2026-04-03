class Solution {
public:
    bool isHappy(int n){

    int sum = n;
    unordered_set<int> s;

    while(true){

        n = sum;
        if(sum == 1) return true;
        if(s.find(sum) != s.end()) return false;

        s.insert(sum);
        sum = 0;
        while(n){
            int x = n%10;
            n = n/10;
            sum += x*x;
        }
    }

}
};
