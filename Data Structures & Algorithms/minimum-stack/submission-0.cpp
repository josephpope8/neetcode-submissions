class MinStack {
private:
    stack<int> st;
    stack<int> ext;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(ext.empty() || val < ext.top()){
            ext.push(val);
        } else {
            ext.push(ext.top());
        }
    }
    
    void pop() {
        ext.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ext.top();
    }
};
