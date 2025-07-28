class MinStack {
public:
    stack< pair<int, int> > st;
    int mini = INT_MAX;

    MinStack() {

        
    }
    
    void push(int val) {
        if(val <= mini){
            mini = val;
        }
        pair<int, int> p;
        p.first= val;
        p.second = mini;
        st.push(p);
        
    }
    
    void pop() {
        st.pop();
        if(!st.empty()){
            mini = st.top().second;
        }
        else{
            mini = INT_MAX;
        }
        
    }
    
    int top() {
        pair<int, int> p = st.top();
        return p.first;
    }
    
    int getMin() {
        pair<int, int> p = st.top();
        return p.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */