class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1){
            return stoi(tokens[0]);
        }
        stack<int> st;
        st.push(stoi(tokens[0]));
        st.push(stoi(tokens[1]));
        for(int i = 2; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first + sec);
            } else if(tokens[i] == "-"){
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first - sec);
            } else if(tokens[i] == "/"){
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first / sec);
            } else if(tokens[i] == "*"){
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first * sec);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
