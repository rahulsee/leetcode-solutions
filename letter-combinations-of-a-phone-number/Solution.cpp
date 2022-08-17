// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    
    void dfs(string& digits, int cur, string mapping[], string &str, vector<string>&ans)
    {
        if(cur==digits.length())
        {
            ans.push_back(str);
            return;
        }
        for(char ch: mapping[digits[cur]-'0'])
        {
            str.push_back(ch);
            dfs(digits, cur+1, mapping, str, ans);
            str.pop_back(); 
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string mapping[]={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string>ans;
        string str;
        if(digits.length()==0)
            return ans;
        dfs(digits, 0, mapping, str, ans);
        return ans;
    }
};