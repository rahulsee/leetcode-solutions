// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push(-1);
        for(char c: s){
            if(st.top()=='{' && c=='}' || st.top()=='(' && c==')' || st.top()=='[' && c==']'){
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.top()==-1;
    }
};