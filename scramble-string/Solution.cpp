// https://leetcode.com/problems/scramble-string

class Solution {
public:
   
    bool checkIfAnagrams(string s1, string s2){
        int A[26];
        int B[26];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        for(int i=0;i<s1.length();i++){
            A[s1[i]-'a']++;
            B[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(A[i]!=B[i])
                return false;
        }
        return true;
    }
    
    bool isScramble(string s1, string s2) {
        if(!checkIfAnagrams(s1, s2))
            return false;
        if(s1==s2){
            return true;
        }
        int n=s1.length();
        if(n==0)
            return true;
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i))
              && isScramble(s1.substr(i), s2.substr(i)))
            {
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n-i))
               && isScramble(s1.substr(i),s2.substr(0, n-i))){
                return true;
            }
        }
        return false;
    }
};