// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>indices;
        unordered_map<int,string>um;
        unordered_map<string, int>wc;
        int tot=0;
        for(string w: words)
        {
            wc[w]++;
        }
        int len=words[0].length()*words.size();
        int word_len=words[0].length();
        int numwords=words.size();
        int n=s.length();
        vector<int>ans;
        for(int i=0;i<=n-len;i++)
        {
            unordered_map<string,int>twc;
            int cur=i;
            for(int j=0;j<numwords && cur<s.length();j++)
            {
                string sub=s.substr(cur,word_len);
                cur+=word_len;
                if(wc.find(sub) == wc.end())
                    break;
                twc[sub]++;
            }
            if(twc==wc)
                ans.push_back(i);
        }
        return ans;
    }
};