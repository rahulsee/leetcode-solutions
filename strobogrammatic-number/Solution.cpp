// https://leetcode.com/problems/strobogrammatic-number

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char>mp;
        mp['6']='9';
        mp['9']='6';
        mp['8']='8';
        mp['0']='0';
        mp['1']='1';
        string rot;
        for(int i=num.size()-1;i>=0;i--){
            if(mp.find(num[i])==mp.end())
                return false;
            rot.push_back(mp[num[i]]);
        }
        return rot==num;   
    }
};