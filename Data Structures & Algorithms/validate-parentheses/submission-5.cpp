class Solution {
public:
    bool isValid(string st) {

        int n = st.size();

        stack<char> s;

        for(int i = 0; i< n; i++){

            char c = st[i];

            if(c == '(' || c== '{' || c == '['){
                s.push(c);
            }
            else{
                if(s.empty()) return false;

                char t = s.top();
                s.pop();

                if((c == ')' && t != '(') ||
                 (c == '}' && t != '{') ||
                 (c == ']' && t != '[')) return false;
            }
        }

        return s.empty();

        
    }
};
