// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    
    struct compare {
        bool operator()(vector<int>a, vector<int>b){
            return a[1] < b[1];
        }
    };
    
    vector<int> mergeInterval(vector<int>a, vector<int>b){
        vector<int>ans;
        ans.push_back(min(a[0], b[0]));
        ans.push_back(max(a[1], b[1]));
        return ans;
    }
    
    bool overlap(vector<int>a, vector<int>b){
        return a[1]>=b[0];
    }
        
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0 || intervals.size()==1)
            return intervals;
        sort(intervals.begin(),intervals.end(), compare());
        stack<vector<int> >st;
        for(int i=0;i<intervals.size();i++){
            vector<int>tmp=intervals[i];
            while(!st.empty() && overlap(st.top(), tmp)){
                tmp=mergeInterval(st.top(), tmp);
                st.pop();
            }
            st.push(tmp);
        }
        vector<vector<int> >ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};