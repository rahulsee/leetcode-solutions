// https://leetcode.com/problems/partition-labels


class Solution {
public:
    bool overlap(pair<int,int>a, pair<int,int>b){
        return a.second>=b.first;
    }
    
    pair<int,int> merge(pair<int,int>a, pair<int,int>b){
        return make_pair(min(a.first, b.first), max(a.second, b.second));
    }
    
    vector<int> partitionLabels(string S) {
        vector<pair<int,int> >fl(26);
        for(int i=0;i<26;i++){
            fl[i].first=fl[i].second=-1;
        }
        for(int i=0;i<S.length();i++){
            if(fl[S[i]-'a'].first==-1){
                fl[S[i]-'a'].first=i;
                fl[S[i]-'a'].second=i;
            }
            else {
                fl[S[i]-'a'].second=i;
            }
        }
        sort(fl.begin(), fl.end());
        stack<pair<int,int> >st;
        for(int i=0;i<26;i++){
            if(fl[i].first==-1 || fl[i].second==-1)
                continue;
            if(st.empty()){
                st.push(fl[i]);
                continue;
            }
            if(overlap(st.top(), fl[i])){
                pair<int,int>p=st.top();
                st.pop();
                st.push(merge(fl[i], p));
            }
            else {
                st.push(fl[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            cout<<st.top().first<<" "<<st.top().second<<endl;
            ans.push_back(st.top().second-st.top().first+1);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};