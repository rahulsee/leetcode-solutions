// https://leetcode.com/problems/decode-ways

class Solution {
    public int numDecodings(String s) {
        int dp[]=new int[s.length()+1];
        
        if(s.length()==0)
            return 0;
        if(s.length()==1){
            if(s.charAt(0)!='0')
                return 1;
            return 0;
        }
        
        dp[0]=1;
        if(s.charAt(0)=='0')
            return 0;
        dp[1]=1;
        for(int i=2;i<=s.length();i++){
            if(s.charAt(i-1)!='0')
                dp[i]=dp[i-1];
            Integer val=Integer.valueOf(s.charAt(i-2)+""+s.charAt(i-1));
            if( val >= 10 && val <=26 ){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.length()];
    }
}