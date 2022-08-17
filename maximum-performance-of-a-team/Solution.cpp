// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    
    struct custom {
        bool operator()(pair<int,int>a, pair<int,int>b){
            return a.second > b.second;
        }
    };
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int> >arr(n);
        for(int i=0;i<n;i++){
            arr[i].first=speed[i];
            arr[i].second=efficiency[i];
        }
        sort(arr.begin(), arr.end(), custom());
        priority_queue<int, vector<int>, greater<int>>pq;
        long long maxi=0;
        long long mod=1000000007;
        long long sum=0;
        for(int i=0;i<n;i++){
            long long sp=arr[i].first;
            long long eff=arr[i].second;
            long long tot=sum+sp;
            long long temp=tot*eff;
            maxi=max(temp, maxi);
            pq.push(sp);
            sum+=sp;
            if(pq.size()>(k-1)){
                // cout<<pq.top()<<endl;
                sum-=pq.top();
                pq.pop();
            }
        }
        return maxi%mod;
    }
};