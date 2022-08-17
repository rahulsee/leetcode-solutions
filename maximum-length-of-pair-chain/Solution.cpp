// https://leetcode.com/problems/maximum-length-of-pair-chain

struct sorter
{
   bool operator()(vector<int>a,vector<int>b)
    {
        return a[0]<b[0];
    }
};
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>len(pairs.size(),1);
        int n=pairs.size();
        int maxi=0;
        sort(pairs.begin(),pairs.end(),sorter());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1] < pairs[i][0])
                {
                    len[i]=max(len[i],len[j]+1);
                }
            }
            //cout<<len[i]<<endl;
            maxi=max(maxi,len[i]);
        }
        return maxi;
    }
};