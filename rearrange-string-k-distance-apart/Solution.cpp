// https://leetcode.com/problems/rearrange-string-k-distance-apart

class Solution {
public:
    struct compare {
        bool operator()(vector<int>a, vector<int>b){
            if(a[1]==b[1])
                return a[0]>b[0];
            return a[1]<b[1];
        }
    };
    
    string rearrangeString(string S, int k) {
        if(k==0)
            return S;
        vector<vector<int> >cnt;
        for(int i=0;i<26;i++){
            vector<int>tmp(2,0);
            cnt.push_back(tmp);
        }
        for(int i=0;i<26;i++){
            cnt[i][0]=i;
        }
        int len=S.length();
        for(char ch: S){
            cnt[ch-'a'][1]++;
            if(cnt[ch-'a'][1] > ceil((double)len/(double)k))
                return "";
        }
        priority_queue<vector<int>, vector<vector<int> >, compare>pq;
        for(int i=0;i<26;i++){
            if(cnt[i][1]){
              pq.push(cnt[i]);
            }
        }
        string ans;
        while(!pq.empty()){
            stack<vector<int> >st;
            for(int i=0;i<k;i++){
                if(pq.empty())
                    break;
                vector<int>x=pq.top();
                ans.push_back(x[0]+'a');
                pq.pop();
                x[1]--;
                if(x[1])
                    st.push(x);
            }
            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }
        int prev[26];
        for(int i=0;i<26;i++){
            prev[i]=-1;
        }
        for(int i=0;i<len;i++){
            if(prev[ans[i]-'a']==-1)
               prev[ans[i]-'a']=i;
            else {
                if(i-prev[ans[i]-'a']<k)
                    return "";
                prev[ans[i]-'a']=i;
            }
        }
        return ans;
    }
};