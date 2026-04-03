class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){

    vector<int> result;
    stack<int> st;
    bool flag = true;

    for(int ast: asteroids){

        if(ast > 0) st.push(ast);

        else{
            while(true){
                flag = true;

                if(st.empty()){
                    st.push(ast);
                    break;
                }
                int top = st.top();

                if(top < 0 ){
                    st.push(ast);
                    break;
                }

                if(ast+top > 0) break;

                else if(ast + top == 0){
                    st.pop();
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
    }
    while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
    }

   reverse(result.begin(), result.end());
    return result;
    
}
};