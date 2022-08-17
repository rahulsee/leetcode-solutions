// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:

    vector<int> shortestToChar(string s, char c) {
        stack<int>st;
        vector<int>right(s.length(), -1);
        for(int i=0;i<s.length();i++){
            if(s[i]==c){
                while(!st.empty()){
                    right[st.top()]=i-st.top();
                    st.pop();
                }
                right[i]=0;
            }
            else {
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int>left(s.length(), -1);
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==c){
                while(!st.empty()){
                    left[st.top()]=st.top()-i;
                    st.pop();
                }
                left[i]=0;
            }
            else {
                st.push(i);
            }
        }
        vector<int>ans(left.size(), -1);
        for(int i=0;i<left.size();i++){
            if(left[i]==-1){
                ans[i]=right[i];
            }
            else if(right[i]==-1){
                ans[i]=left[i];
            }
            else {
                ans[i]=min(left[i], right[i]);
            }
        }
        return ans;
    }
};