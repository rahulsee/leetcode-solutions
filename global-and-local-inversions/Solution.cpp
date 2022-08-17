// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    int BITree[5007];
    int n=5005;
    int getSum(int index)
    {
        int sum = 0;
        while (index>0)
        {
            sum += BITree[index];
            index -= index & (-index);
        }
        return sum;
    }

    void updateBIT(int index, int val)
    {
        while (index <= n)
        {
            BITree[index] += val;
            index += index & (-index);
        }
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int global_inv=0;
        int local_inv=0;
        memset(BITree, 0, sizeof(BITree));
        updateBIT(A[0]+1, 1);
        for(int i=1;i<A.size();i++){
            if(A[i]<A[i-1])
                local_inv++;
            global_inv+=getSum(n+1)-getSum(A[i]+1);
            updateBIT(A[i]+1,1);
        }
        return global_inv==local_inv;
    }
};