class SpecialStack {
    stack<pair<int,int>> st;   

  public:
    SpecialStack() {
       
    }

    void push(int x) {
        if(st.size() == 0){
            st.push({x, x});
        }
        else{
            st.push({x, min(st.top().second, x)});
        }
    }

    void pop() {
        if(!st.empty())
            st.pop();
    }

    int peek() {
        if(st.empty())
            return -1;
        return st.top().first;
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if(st.empty())
            return -1;
        return st.top().second;
    }
};