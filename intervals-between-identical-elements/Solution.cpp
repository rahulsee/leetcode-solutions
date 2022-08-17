// https://leetcode.com/problems/intervals-between-identical-elements

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<long long> >um;
        for(int i=0;i<arr.size();i++)
        {
            um[arr[i]].push_back(i);
        }
        vector<long long>ans(arr.size());
        for(auto it=um.begin();it!=um.end();it++)
        {
            vector<long long>vec=it->second;
            vector<long long>psum=vec;
            for(int i=psum.size()-2;i>=0;i--)
            {
                psum[i]+=psum[i+1];
            }
            long long x=psum[0]-vec[0]*vec.size();
            ans[vec[0]]=x;
            for(long long i=1;i<psum.size();i++)
            {
                long long y=vec[i]*vec.size()-psum[0];
                long long z=abs(((long long)vec.size()-i)*vec[i]-psum[i]);
                ans[vec[i]]=y+2*z;
            }
        }
        return ans;
    }
};