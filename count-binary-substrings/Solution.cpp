// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int i=0;
        int n=s.length();
        int ans=0;
        int prev_zc=0;
        int prev_oc=0;
        while(i<n){
            int zc=0;
            while(i<n && s[i]=='0') {
                i++;
                zc++;
            }
            ans+=min(prev_oc, zc);
            prev_zc=zc;
            int oc=0;
            while(i<n && s[i]=='1'){
                i++;
                oc++;
            } 
            ans+=min(prev_zc,oc);
            prev_oc=oc;
        }
        return ans;
    }
};