// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:  
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>um;
        int start=0;
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            um[s[i]]++;
            while(start<i && um.size()>2){
                um[s[start]]--;
                if(um[s[start]]==0)
                    um.erase(s[start]);
                start++;
            }
            ans=max(ans, i-start+1);
        }
        return ans;
    }
};