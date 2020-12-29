class CustomStack {
public:
    vector<int> st;
    int mx;
    vector<int> inc;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(st.size() < mx)
        {
            st.push_back(x);
            inc.push_back(0);
        }
    }
    int pop() {
        if(st.empty()) return(-1);
        int i = st.size()-1;
        if(i)
            inc[i-1] += inc[i];
        int temp = st[i] + inc[i];
        st.pop_back();
        inc.pop_back();
        return(temp);
    }
    
    void increment(int k, int val) {
        k = min(k,(int)st.size());
        if(k) inc[k-1]+=val;
    }
};
​
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
