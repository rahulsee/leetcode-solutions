// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    
    bool equal(int x[], int y[]){
        for(int i=0;i<26;i++){
            if(x[i]>y[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int x[26];
        int y[26];
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for(char ch: s1){
            x[ch-'a']++;
        }
        int k=s1.length();
        int n=s2.length();
        if(k>n)
            return false;
        int temp[26];
        memset(temp, 0, sizeof(temp));
        for(int i=0;i<k;i++){
            temp[s2[i]-'a']++;
        }
        if(equal(x, temp))
            return true;
        for(int i=k;i<n;i++){
            temp[s2[i-k]-'a']--;
            temp[s2[i]-'a']++;
            if(equal(temp,x)){
                return true;
            }
        }
        return false;
    }
};