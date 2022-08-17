// https://leetcode.com/problems/create-maximum-number

class Solution {
public:
    
    string maxNum(vector<int>nums, int k)
    {
        if(k==0)
            return "";
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && (st.size()+nums.size()-i)>k && st.top()<nums[i])
            {
                st.pop();
            }
            if(st.size()<k)
                st.push(nums[i]);
        }
        string ans;
        int cnt=0;
        while(!st.empty())
        {
            ans.push_back(st.top()+'0');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool greater(string a, string b)
    {
        if(a.length()==b.length())
        {
            return a>b;
        }
        return a.length()>b.length();
    }
    
    bool func(string a, int i, string b, int j)
    {
        while(i<a.length() && j<b.length() && a[i]==b[j])
        {
            i++;
            j++;
        }
        if(j==b.length())
            return true;
        return i<a.length() && a[i]>b[j];
    }
    
    string merge(string a, string b)
    {
        string ans;
        int i=0,j=0;
        while(i<a.length() && j<b.length())
        {
            if(func(a,i,b,j)) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<a.length())
        {
            ans.push_back(a[i]);
            i++;
        }
        while(j<b.length())
        {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        string finalAns="";
        for(int i=0;i<=k;i++)
        {
            if(i<=nums1.size() && (k-i)<=nums2.size())
            {
                string x=maxNum(nums1, i);
                string y=maxNum(nums2, k-i);
                // cout<<x<<" "<<y<<endl;
                string ans=merge(x,y);
                if(greater(ans, finalAns))
                    finalAns=ans;
            }
        }
        vector<int>vec;
        for(char c: finalAns)
            vec.push_back(c-'0');
        return vec;
    }
};