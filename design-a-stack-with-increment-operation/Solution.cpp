// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack {
public:
    
    vector<int>inc;
    stack<int>st;
    int maxSize;
    CustomStack(int maxSize) {
        vector<int>vec(1002,0);
        inc=vec;
        stack<int>tmp;
        st=tmp;
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(st.size()==maxSize){
            return;
        }
        st.push(x);
    }
    
    int pop() {
        if(!st.empty()){
            int ans=st.top()+inc[st.size()];
            inc[st.size()-1]+=inc[st.size()];
            inc[st.size()]=0;
            st.pop();
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k=min(k, (int)st.size());
        inc[k]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */