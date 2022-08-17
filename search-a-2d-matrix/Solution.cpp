// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    
    int lb(vector<int>bh,int target)
    {
        int l=0;
        int r=bh.size()-1;
        int ans=-1;
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            if(bh[mid] > target)
            {
                r=mid-1;
            }
            else{
                ans=max(ans,mid);
                l=mid+1;
            }
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        vector<int>bh;
        for(int i=0;i<matrix.size();i++)
            bh.push_back(matrix[i][0]);
        int index=lb(bh,target);
        cout<<index<<endl;
        if(index==-1)
            return false;
        bool result=binary_search(matrix[index].begin(),matrix[index].end(),target);
        return result;
    }
};