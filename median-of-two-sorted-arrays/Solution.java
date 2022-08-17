// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
    
    public double median(int nums[]){
        int len=nums.length;
        if(len%2==0){
            return nums[len/2]+nums[len/2-1];
        }
        return nums[len/2];
    }
    
    public int elemAt(int []A, int index){
        if(index<=-1){
            return Integer.MIN_VALUE;
        }
        else if(index>=A.length){
            return Integer.MAX_VALUE;
        }
        else 
            return A[index];
    }
    
    public double findMedianSortedArrays(int[] A, int[] B) {
        int []tmp;
        if(A.length > B.length){
            tmp=A;
            A=B;
            B=tmp;
        }
        int lo=-1;
        int hi=A.length;
        int p=-1,q=-1,r=-1,s=-1;
        int len1=A.length;
        int len2=B.length;
        int midA=-1,midB=-1;
        // System.out.println(len1+","+len2);
        while(lo<=hi){
            midA=lo+(hi-lo)/2;
            midB=(len1+len2)/2-(midA+1)-1;
            // System.out.println(midA+","+midB);
            p=elemAt(A,midA);
            q=elemAt(B,midB);
            r=elemAt(A,midA+1);
            s=elemAt(B,midB+1);
            if(p<=r && p<=s && q<=r && q<=s){
                break;
            }
            else if(p>s){
                hi=midA-1;
            }
            else{
                lo=midA+1;
            }
        }
        if((len1+len2)%2==1){
            return Math.min(r,s);
        }
        else {
            double x=Math.max(p,q);
            double y=Math.min(r,s);
            return (x+y)/2;
        }
    }
}