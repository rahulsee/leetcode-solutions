// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    
    int count=0;
    string arr="aeiou";
    
    void solve(int n, char ch){
        if(n==0){
            count++;
            return;
        }
        for(int i=0;i<5;i++){
            if(arr[i]>=ch)
                solve(n-1, arr[i]);
        }
    }
    
    int countVowelStrings(int n) {
        solve(n, 0);
        return count;
    }
};