// https://leetcode.com/problems/reorganize-string

class Solution {
public:
  
    struct compare {
        bool operator()(vector<int>a, vector<int>b){
            if(a[1]==b[1])
                return a[0]>b[0];
            return a[1]<b[1];
        }
    };
    
    string reorganizeString(string S) {
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
            if(cnt[ch-'a'][1] > (len/2+len%2))
                return "";
        }
        priority_queue<vector<int>, vector<vector<int> >, compare>pq;
        for(int i=0;i<26;i++){
            if(cnt[i][1])
             pq.push(cnt[i]);
        }
        string ans;
        while(!pq.empty()){
            vector<int>x=pq.top();
            pq.pop();
            ans.push_back(x[0]+'a');
            if(!pq.empty()){
                vector<int>y=pq.top();
                pq.pop();
                ans.push_back(y[0]+'a');
                y[1]--;
                if(y[1]>0)
                    pq.push(y);
            }
            x[1]--;
            if(x[1]>0)
                pq.push(x);
        }
        return ans;
    }
};