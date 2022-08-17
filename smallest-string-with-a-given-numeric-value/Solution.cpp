// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value

class Solution {
public:
    
    string getSmallestString(int n, int k) {
        string ans;
        char ch='z';
        for(int i=n-1;i>=0;i--){
            while((ch-'a'+(n-1))>=k && ch>='a'){
                ch--;
            }
            ans.push_back(ch);
            k-=(ch-'a');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};