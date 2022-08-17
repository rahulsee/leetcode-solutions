// https://leetcode.com/problems/meeting-scheduler

class Solution {
public:
    
    pair<int,int> intersect(pair<int,int>a, pair<int,int>b){
        return make_pair(max(a.first, b.first), min(a.second, b.second));
    }
    
    struct compare {
        bool operator()(vector<int>a, vector<int>b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        }
    };
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int m=slots1.size();
        int n=slots2.size();
        sort(slots1.begin(), slots1.end(), compare());
        sort(slots2.begin(), slots2.end(), compare());
        int i=0;
        int j=0;
        while(i<m && j<n){
            pair<int,int>p={slots1[i][0],slots1[i][1]};
            pair<int,int>q={slots2[j][0],slots2[j][1]};
            pair<int,int>r=intersect(p,q);
            if(r.second-r.first>=duration){
                vector<int>x={r.first, r.first+duration};
                return x;
            }
            if(p.second<q.second){
                i++;
            }
            else {
                j++;
            }
        }
        vector<int>x;
        return x;
    }
};