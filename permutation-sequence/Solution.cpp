// https://leetcode.com/problems/permutation-sequence

typedef long long ll;
class Solution {
public:
    ll factorial(ll n){
        ll f=1;
        for(long long i=1;i<=n;i++)
            f=f*i;
        return f;
    }
    
    string getPermutation(int n, int k) {
        ll nn=n;
        ll g=factorial(nn-1);
        ll kk=(ll)k-1;
        vector<int>indices;
        int m=n;
        while(nn>1){
            indices.push_back(kk/g);
            kk=kk%g;
            cout<<"G IS "<<g<<endl;
            nn--;
            g=factorial(nn-1);
        }
        string ans;
        string begin;
        for(int i=1;i<=m;i++)
            begin.push_back(i+'0');
        cout<<begin<<endl;
        for(int i=0;i<indices.size();i++)
        {
            cout<<"INDEX IS "<<indices[i]<<endl;
            ans.push_back(begin[indices[i]]);
            begin.erase(remove(begin.begin(), begin.end(), begin[indices[i]]), begin.end());
        }
        ans.push_back(begin[0]);
        return ans;
    }
    
};