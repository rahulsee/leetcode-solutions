// https://leetcode.com/problems/decode-ways-ii

class Solution {
    
    final int MOD=(int)1e9+7;
    
    public int numDecodings(String s) {
        if(s.length()==0)
            return 0;
        if(s.length()==1){
            if(s.charAt(0)=='*')
                return 9;
            else if(s.charAt(0)=='0')
                return 0;
            else 
                return 1;
        }
        
        
        if(s.charAt(0)=='0')
            return 0;
        
        int N=s.length();
        long dp[]=new long[N+1];
        dp[0]=1;
        
        if(s.charAt(0)=='*')
            dp[1]=9;
        else 
            dp[1]=1;
        
        if(s.charAt(0)==0)
            return 0;
        
        for(int i=2;i<=N;i++){
            if(s.charAt(i-1)=='*'){
                if(s.charAt(i-2)=='*'){
                    dp[i]=((dp[i-1]*9)+(dp[i-2]*15))%MOD;
                }
                else if(s.charAt(i-2)=='0'){
                    dp[i]=(dp[i-1]*9);
                }
                else if(s.charAt(i-2)=='1') {
                    dp[i]=((dp[i-2]*9)+(dp[i-1]*9));
                }
                else if(s.charAt(i-2)=='2'){
                    dp[i]=((dp[i-2]*6)+(dp[i-1]*9));
                }
                else{
                    dp[i]=(dp[i-1]*9);
                }
            }
            else if(s.charAt(i-1)=='0'){
                if(s.charAt(i-2)=='*'){
                    dp[i]=(dp[i-2]*2);
                }
                else if(s.charAt(i-2)=='0')
                    return 0;
                else if(s.charAt(i-2)>='3' && s.charAt(i-2)<='9')
                    return 0;
                else if(s.charAt(i-2)=='1' || s.charAt(i-2)=='2'){
                    dp[i]=dp[i-2];
                }
            }
            
            else if(s.charAt(i-1)=='1' || s.charAt(i-1)=='2'){
                if(s.charAt(i-2)=='*'){
                    dp[i]=(dp[i-1]+(dp[i-2]*2));
                }
                else if(s.charAt(i-2)=='0')
                    dp[i]=dp[i-2];
                else if(s.charAt(i-2)=='1' || s.charAt(i-2)=='2')
                    dp[i]=(dp[i-1]+dp[i-2]);
                else 
                    dp[i]=dp[i-1];
            }
            else if(s.charAt(i-1)>='3' && s.charAt(i-1)<='6'){
                if(s.charAt(i-2)=='*'){
                    dp[i]=(dp[i-1]+(2*dp[i-2]));
                }
                else if(s.charAt(i-2)=='0'){
                    dp[i]=dp[i-2];
                }
                else if(s.charAt(i-2)=='1' || s.charAt(i-2)=='2')
                    dp[i]=(dp[i-1]+dp[i-2]);
                else
                    dp[i]=dp[i-1];
            }
            
            
            else if(s.charAt(i-1)>='7' && s.charAt(i-1)<='9'){
                if(s.charAt(i-2)=='*'){
                    dp[i]=(dp[i-1]+dp[i-2]);
                }
                else if(s.charAt(i-2)=='0'){
                    dp[i]=dp[i-2];
                }
                else if(s.charAt(i-2)=='1')
                    dp[i]=(dp[i-1]+dp[i-2]);
                else
                    dp[i]=dp[i-1];
            }
            dp[i]=dp[i]%MOD;
            
        }
        return (int)dp[N];
        
    }
}