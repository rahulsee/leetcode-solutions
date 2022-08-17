// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target

class Solution {
public:
    
    int lb(vector<int>&arr, int key)
    {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(key>arr[mid])
            {
                low=mid+1;
                ans=max(ans, mid);
            }
            else 
            {
                high=mid-1;
            }
        }
        return ans;
    }
    
    int fb_lower(vector<int>&arr, vector<int>&psum, int target, int &sum)
    {
        int n=arr.size();
        int low=0;
        int high=arr[n-1];
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int pos=lb(arr, mid);
            int tot;
            if(pos==-1)
                tot=mid*n;
            else
                tot=psum[pos]+(n-1-pos)*mid;
            if(tot>target)
                high=mid-1;
            else
            {
                if(mid >= ans)
                {
                    ans=mid;
                    sum=tot;
                }
                low=mid+1;
            }
        }
        return ans;
    }
    
    int fb_upper(vector<int>&arr, vector<int>&psum, int target, int &sum)
    {
        int n=arr.size();
        int low=0;
        int high=arr[n-1];
        int ans=high+1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int pos=lb(arr, mid);
            int tot;
            if(pos==-1)
                tot=mid*n;
            else
                tot=psum[pos]+(n-1-pos)*mid;
                        
            if(tot>=target)
            {
                high=mid-1;
                if(mid < ans)
                {
                    ans=mid;
                    sum=tot;
                }
            }
            else 
            {
                low=mid+1;
            }
        }
        return ans;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int>psum(arr);
        int n=arr.size();
        for(int i=1;i<n;i++)
            psum[i]+=psum[i-1];
        int p=-1, q=-1;
        int x=fb_upper(arr, psum, target, p);
        int y=fb_lower(arr, psum, target, q);
        
        if(p==-1)
            return y;
        if(q==-1)
            return x;
        
        if(p-target < target-q)
        {
            return x;
        }
        else if(p-target > target-q)
        {
            return y;
        }
        else 
        {
            return min(x,y);
        }
    }
};