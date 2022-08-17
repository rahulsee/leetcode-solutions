// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    
    int longestSubstring(string s, int k) {
        int map[26];
        memset(map, 0,sizeof(map));
        for(char c:s)
            map[c-'a']++;
        int len=s.length();
        if(len==0)
            return 0;
        else if(len==1 && k==1)
            return 1;
        else if(len==1)
            return 0;
        else {
            int pivot=-1;
            for(int i=0;i<len;i++)
            {
                if(map[s[i]-'a']<k)
                {
                    pivot=i;
                    break;
                }
            }
            if(pivot==-1)
                return len;
            int left=longestSubstring(s.substr(0,pivot), k);
            int right=longestSubstring(s.substr(pivot+1), k);
            return max(left, right);
        }
    }
};