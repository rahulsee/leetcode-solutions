// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if(nums.size()==0)
        {
            vector<int>answer;
            return answer;
        }
        
        sort(nums.begin(),nums.end());
        
        vector<int>prev(nums.size(),-1);
        vector<int>div(nums.size(),1);
        vector<int>ans;
        
        int lind=0;
        int maxval=0;
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0)
                {
                    if(div[i] < div[j]+1)
                    {
                        div[i]=div[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(div[i] > maxval){
                maxval=div[i];
                lind=i;
            }
            
        }
        
        int k=lind;
        while(k>=0){
            ans.push_back(nums[k]);
            k=prev[k];
        }
        
        return ans;
        
    }
};