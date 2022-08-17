// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int swaps[n];
        int noswaps[n];
        swaps[0]=1;
        noswaps[0]=0;
        for(int i=1;i<n;i++){
            int s=numeric_limits<int>::max();
            int ns=numeric_limits<int>::max();
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                s=min(s, swaps[i-1]+1);
                ns=min(ns, noswaps[i-1]);
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                s=min(s, noswaps[i-1]+1);
                ns=min(ns, swaps[i-1]);
            }
            swaps[i]=s;
            noswaps[i]=ns;
        }
        return min(swaps[n-1], noswaps[n-1]);
    }
};