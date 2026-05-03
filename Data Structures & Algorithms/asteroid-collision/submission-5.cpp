class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){

    vector<int> result;
    stack<int> st;

    for(int ast: asteroids){

        if(ast > 0) st.push(ast);

        else{

            while(true){

                if(st.empty()){
                    st.push(ast);
                    break;
                }

                int top = st.top();

                if(top < 0){
                    st.push(ast);
                    break;
                }

                if(top + ast > 0) break;

                else{
                    st.pop();
                    if(top + ast == 0) break;
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