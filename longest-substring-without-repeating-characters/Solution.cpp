// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        unordered_set<char>seen;
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(seen.find(s[i])==seen.end()){
                seen.insert(s[i]);
            }
            else {
                while(start<i){
                    seen.erase(s[start]);
                    start++;
                    if(seen.find(s[i])==seen.end())
                        break;
                }
                seen.insert(s[i]);
            }
            int len=i-start+1;
            maxlen=max(maxlen, len);
        }
        return maxlen;
    }
};