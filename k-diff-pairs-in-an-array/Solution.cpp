// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        if(k==0)
        {
            unordered_map<int,int>count;
            for(int i=0;i<nums.size();i++)
            {
                count[nums[i]]++;
            }
            int c=0;
            for(auto it=count.begin();it!=count.end();it++)
            {
                if(it->second >=2)
                    c++;
            }
            return c;
        }
        unordered_multiset<int>s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        unordered_set<string>tmp;
        for(auto it=s.begin();it!=s.end();it++)
        {
            if(s.find(*it+k)!=s.end() && it!=(s.find(*it+k)))
            {
                int a=max(*it,*it+k);
                int b=min(*it,*it+k);
                cout<<a<<" "<<b<<endl;
                tmp.insert(to_string(a)+" "+to_string(b));
            }
        }
        return tmp.size();
    }
};