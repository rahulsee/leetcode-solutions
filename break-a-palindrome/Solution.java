// https://leetcode.com/problems/break-a-palindrome

class Solution {
    public String breakPalindrome(String palindrome) {
        char pal[]=palindrome.toCharArray();
        int n=palindrome.length();
        if(n==1){
            return "";
        }
        boolean flag=false;
        for(int j=0;j<n/2;j++){
            if(pal[j]!='a'){
                pal[j]='a';
                flag=true;
                break;
            }
        }   
        if(flag==false){
            pal[n-1]='b';
        }
        return new String(pal);
    }
}