// https://leetcode.com/problems/optimal-division

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==0)
            return "";
        if(nums.size()==1)
        {
            return to_string(nums[0]);
        }
        if(nums.size()==2)
        {
            return to_string(nums[0])+"/"+to_string(nums[1]);
        }
        string res="";
        for(int i=0;i<nums.size();i++)
        {
            
            if(i==0)
                res+=to_string(nums[i]);
            else if(i==1){
                res+=("/("+to_string(nums[i]));
            }
            else if(i==nums.size()-1)
            {
                res+=("/"+to_string(nums[i])+")");
            }
            else
            {
                res+=("/"+to_string(nums[i]));
            }
            
        }
        return res;
        
    }
};