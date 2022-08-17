// https://leetcode.com/problems/longest-common-subpath

typedef long long ll;
class Solution {
public:
    
    const ll p = 100007; 
    const ll m = 1e11L + 7;
    vector<ll>p_pow;
    
    bool works(vector<vector<ll> >paths, ll len){
        
        unordered_set<ll>s;
        for(ll i=0;i<(int)paths.size();i++)
        {
            ll h=0;
            unordered_set<ll>ss;
            for(ll j=0;j<len;j++){
                h=(h+(paths[i][j]*p_pow[len-1-j])%m)%m;
            }
            if(i==0)
                ss.insert(h);
            else if(s.find(h)!=s.end()){
                ss.insert(h);
            }
            for(ll j=len;j<(ll)paths[i].size();j++){
                h=(h+m-(paths[i][j-len]*p_pow[len-1])%m)%m;
                h=(h*p)%m;
                h=(h+paths[i][j])%m;
                if(i==0)
                    ss.insert(h);
                else if(s.find(h)!=s.end()){
                    ss.insert(h);
                }
            }
            s=ss;
            if(s.size()==0)
                return false;
        }
        
        return s.size()>0;
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& pathParam) {
        
        vector<vector<ll> >paths;
        ll min_len=numeric_limits<ll>::max();
        for(vector<int>v: pathParam)
        {
            vector<ll>temp;
            for(int num: v )
                temp.push_back(num);
            paths.push_back(temp);
            min_len=min(min_len, (ll)temp.size());
        }
        
        p_pow=vector<ll>(100001);
        p_pow[0]=1;
        for(int i=1;i<=100000;i++)
        {
            p_pow[i]=(p_pow[i-1]*p)%m;
        }
        
        ll low=1;
        ll high=min_len;
        ll ans=0;
        
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(works(paths, mid))
            {
                ans=max(ans, mid);
                low=mid+1;
            }
            else {
                //cout<<mid<<" does not work"<<endl;
                high=mid-1;
            }
        }
        return ans;
    }
};