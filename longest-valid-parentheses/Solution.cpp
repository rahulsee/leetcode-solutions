// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int diff=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                if(st.top()>=0 && s[st.top()]=='('){
                    st.pop();
                    diff=max(diff, i-st.top());
                }
                else {
                    st.push(i);
                }
            }
        }
        return diff;
    }
};