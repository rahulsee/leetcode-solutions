// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>st;
        int left=nums.size();
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                left=min(left, st.top());
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        int right=-1;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                right=max(right, st.top());
                st.pop();
            }
            st.push(i);
        }
        cout<<left<<"  "<<right<<endl;
        if(left==nums.size()){
            return 0;
        }
        else if(right==-1){
            return nums.size();
        }
        return right-left+1;
    }
};