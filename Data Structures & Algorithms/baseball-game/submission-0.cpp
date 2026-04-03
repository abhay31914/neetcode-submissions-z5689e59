class Solution {
public:
    int calPoints(vector<string>& operations){

    stack<int> S;

    for(auto x: operations){

        if(x == "C"){
            S.pop();
        }

        else if(x == "D"){
            int n = S.top();
            S.push(2*n);
            
        }
        else if(x == "+"){
            int n1 = S.top();
            S.pop();
            int n2 = S.top() + n1;
            S.push(n1);
            S.push(n2);
        }
        else{
            S.push(stoi(x));
        }

    }

    int sum = 0;

    while(!S.empty()){
        
        sum += S.top();
        S.pop();
    }
    return sum;

}
};