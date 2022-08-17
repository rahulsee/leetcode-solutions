// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>us;
        if(s.length()<k)
            return false;
        for(int i=0;i<=s.length()-k;i++){
            us.insert(s.substr(i, k));
        }
        return us.size()==(1<<k);
    }
};