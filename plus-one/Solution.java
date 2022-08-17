// https://leetcode.com/problems/plus-one

class Solution {
    public int[] plusOne(int[] digits) {
        int ones[]=new int[digits.length];
        ones[ones.length-1]=1;
        ArrayList<Integer>answer=new ArrayList<>();
        int sum=0;
        int carry=0;
        for(int i=digits.length-1;i>=0;i--){
            sum=digits[i]+ones[i]+carry;
            carry=sum/10;
            answer.add(sum%10);
        }
        if(carry!=0)
            answer.add(carry);
        Collections.reverse(answer);
        int []ans=new int[answer.size()];
        for(int i=0;i<answer.size();i++)
        {
            ans[i]=answer.get(i);
        }
        return ans;
    }
}