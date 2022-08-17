// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:

    vector<int>bit;
    int n;
    vector<int>arr;
    
    
    NumArray(vector<int>& nums) {
        vector<int>temp(nums.size()+1,0);
        bit=temp;
        n=nums.size();
        vector<int>temp2(nums.size(),0);
        arr=temp2;
        for(int i=0;i<nums.size();i++){
            updateUtil(i, nums[i]);
        }
    }
    
    void updateUtil(int index, int val){
        int oldval=arr[index];
        arr[index]=val;
        index++;
        while(index<=n){
            bit[index]+=(val-oldval);
            index+=(index & (-index));
        }
    }
    
    void update(int index, int val) {
        updateUtil(index, val);
    }
    
    int getSum(int index){
        index++;
        int sum=0;
        while(index>0){
            sum+=bit[index];
            index-=(index & (-index));
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return getSum(right)-getSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */