class Solution {
public:
    int evalRPN(vector<string>& tokens){

    stack<int> s;

    for(string ele: tokens){

        if(ele == "+" || ele == "-" || ele == "*" || ele == "/"){

            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();

            if(ele == "+") s.push(second + first);
            else if(ele == "-") s.push(second - first);
            else if(ele == "*") s.push(second* first);
            else s.push(second/first);
        }
        else{
            s.push(stoi(ele));
        }
    }
    return s.top();

}
};
