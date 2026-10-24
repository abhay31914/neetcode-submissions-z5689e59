class Solution {
public:

    int stTOint(string& str){

        int result = 0;
        int carry = 1;

        for(char c: str){

            if(c == '-') {
                carry = -1;
                continue;
            }

            result = result*10 + (c-'0');
        }

        return carry*result;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(auto x: tokens){

            if(x == "+" || x == "-" || x == "*" || x == "/"){
                int e1 = st.top();
                st.pop();
                int e2 = st.top();
                st.pop();

                if(x == "+") st.push(e1+e2);
                else if(x == "-") st.push(e2-e1);
                else if(x == "*") st.push(e1*e2);
                else st.push(e2/e1);
            }

            else{
                st.push(stTOint(x));
            }
        }

        return st.top();
        
    }
};
