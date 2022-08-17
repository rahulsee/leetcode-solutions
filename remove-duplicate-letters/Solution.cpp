// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_map<char,int>cnt;
        for(char ch: s)
            cnt[ch]++;
        vector<bool>seen(26, false);
        for(char ch: s){
            if(seen[ch-'a']==true){
                cnt[ch]--;
                continue;
            }
            while(!st.empty() && st.top()>ch && cnt[st.top()]>=1) {
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            seen[ch-'a']=true;
            cnt[ch]--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};