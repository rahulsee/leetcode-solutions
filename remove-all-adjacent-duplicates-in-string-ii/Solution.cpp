// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<string>st;
        string ans;
        for(char ch: s){
            if(st.empty()){
                st.push(string(1,ch));
            }
            else if(ch==st.top()[0]){
                string str=st.top();
                st.pop();
                str.push_back(ch);
                if(str.length()<k)
                    st.push(str);
            }
            else {
                st.push(string(1,ch));
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};