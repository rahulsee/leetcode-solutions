// https://leetcode.com/problems/create-sorted-array-through-instructions

class Solution {
public:
    
    void update(int bitree[], int index, int count, int size){
        for(int i=index;i<size;i+=(i&(-i))){
            bitree[i]+=count;
        }
    }
    
    int getSum(int bitree[], int index, int size){
        int sum=0;
        while(index>0){
            sum+=bitree[index];
            index-=(index & (-index));
        }
        return sum;
    }
    
    int createSortedArray(vector<int>& instructions) {
        int ans=0;
        int maxi=0;
        for(int num: instructions){
            maxi=max(num, maxi);
        }
        int bitree[maxi+1];
        memset(bitree, 0, sizeof(bitree));
        for(int i=0;i<instructions.size();i++){
            int l=getSum(bitree, instructions[i]-1, maxi+1);
            int r=i-getSum(bitree, instructions[i], maxi+1);
            ans+=min(l,r);
            ans=ans%(1000000007);
            update(bitree, instructions[i], 1, maxi+1);
        }
        return ans;
    }
};