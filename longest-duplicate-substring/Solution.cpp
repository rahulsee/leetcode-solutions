// https://leetcode.com/problems/longest-duplicate-substring

typedef long long ll;
#define d 26
long long mod=(long long)(1<<32);
class Solution {
public:
    
    string duplicate(string S, int mid){
        vector<ll>hash(S.length(),0);
        ll p=0;
        ll h=1;
        unordered_set<ll>s;
        for(int i=0;i<mid-1;i++){
            h=(h*d)%mod;
        }
        for(int i=0;i<mid;i++){
            p=(p*d+S[i])%mod;
        }
        s.insert(p);
        int len=S.length();
        for(int i=mid;i<len;i++){
            p = (d*(p - S[i-mid]*h) + S[i])%mod;  
            if (p < 0)  
                p = (p + mod);  
            if(s.find(p)!=s.end())
            {
                string pat=S.substr(i-mid+1,mid);
                int first=S.find(pat);
                if(S.find(pat,first+1)!=string::npos)
                    return pat;
            }
            s.insert(p);
        }
        return "";
    }
    
    string longestDupSubstring(string S) {
        ll low=1;
        ll ans=0;
        ll high=S.length();
        string s_ans="";
        while(low <= high){
            ll mid=low+(high-low)/2;
            string ans=duplicate(S,mid);
            if(ans.length() > s_ans.length())
            {
                s_ans=ans;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return s_ans;
    }
};