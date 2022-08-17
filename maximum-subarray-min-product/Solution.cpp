// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long>arr;
        arr.push_back(0);
        for(int n: nums)
            arr.push_back(n);
        arr.push_back(0);
       
        stack<int>st;
        int len=nums.size();
        vector<int>right(len+2);
        vector<int>left(len+2);
        for(int i=1;i<=len;i++){
            if(!st.empty() && arr[i]>=arr[st.top()]){
                st.push(i);
            }
            else {
                while(!st.empty() && arr[st.top()]>arr[i]){
                    right[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        
        // cout<<"HELLO"<<endl;
        while(!st.empty()){
            right[st.top()]=len+1;
            st.pop();
        }
        
        for(int i=len;i>=1;i--){
            if(!st.empty() && arr[i]>=arr[st.top()]){
                st.push(i);
            }
            else {
                while(!st.empty() && arr[st.top()]>arr[i]){
                    left[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            left[st.top()]=0;
            st.pop();
        }
        
        long long maxi=0;
        long long MOD=1000000007;
        // cout<<"HELLO"<<endl
        
        for(int i=1;i<arr.size();i++){
            arr[i]=(arr[i-1]+arr[i]);
        }
        for(int i=1;i<=len;i++){
            int low=left[i];
            int high=right[i];
            // cout<<low<<"  "<<high<<endl;
            long long psum=(arr[high-1]-arr[low]);
            psum=(nums[i-1]*psum);
            maxi=max(maxi,psum);
        }
        return maxi%MOD;
    }
};