// https://leetcode.com/problems/count-of-smaller-numbers-after-self


class Solution {
public:    
    
    int bitree[20007];
    int MAX=20007;
    int OFFSET=10001;
    
    inline int getIndex(int num){
        return num+OFFSET;
    }
    
    void update(int index){
        while(index < MAX){
            bitree[index]++;
            index+=(index & (-index));
        }
    }
    
    int getSum(int index){
        int sum=0;
        while(index>0){
            sum+=bitree[index];
            index-=(index & (-index));
        }
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        memset(bitree, 0, sizeof(bitree));
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(getSum(getIndex(nums[i])-1));
            update(getIndex(nums[i]));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};