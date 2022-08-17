// https://leetcode.com/problems/largest-number

class Solution {
public:
    
    
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int n:nums)
            arr.push_back(to_string(n));
        auto cmp=[](string a, string b){
            return a+b > b+a;
        };
        sort(arr.begin(), arr.end(), cmp);
        string ans="";
        for(string str: arr)
            ans+=str;
        int zc=0;
        for(char ch: ans)
            zc+=(ch=='0');
        if(zc==ans.length())
            return "0";
        return ans;
    }
};