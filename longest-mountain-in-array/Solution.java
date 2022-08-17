// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
    public int longestMountain(int[] A) {
        if(A==null || A.length <=2)
            return 0;
        int maxInc[]=new int[A.length];
        int maxDec[]=new int[A.length];
        
        if(A[0] < A[1])
            maxInc[1]=2;
        else 
            maxInc[1]=1;
        int n=A.length;
        if(A[n-2] > A[n-1])
            maxDec[n-2]=2;
        else 
            maxDec[n-2]=1;
        maxInc[0]=maxDec[n-1]=1;
        int maxLen=0;
        for(int i=2;i<A.length;i++) {
            if(A[i] > A[i-1])
                maxInc[i]=maxInc[i-1]+1;
            else
                maxInc[i]=1;
        }
        for(int i=n-3;i>=0;i--){
            if(A[i] > A[i+1])
                maxDec[i]=maxDec[i+1]+1;
            else
                maxDec[i]=1;
        }
        for(int i=0;i<n;i++){
            if(maxInc[i]==1 || maxDec[i]==1)
                continue;
            maxLen=Math.max(maxLen, maxInc[i]+maxDec[i]-1);
        }
        return maxLen;
    }
}