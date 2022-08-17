// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(char c: word1)
            m1[c]++;
        for(char c: word2)
            m2[c]++;
        vector<int>cnt1;
        vector<int>cnt2;
        unordered_set<char>us;
        for(auto it=m1.begin();it!=m1.end();it++){
            cnt1.push_back(it->second);
            us.insert(it->first);
        }
        for(auto it=m2.begin();it!=m2.end();it++){
            cnt2.push_back(it->second);
            if(us.find(it->first)==us.end()){
                return false;
            }
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        if(cnt1.size()!=cnt2.size())
            return false;
        for(int i=0;i<cnt1.size();i++){
            if(cnt1[i]!=cnt2[i])
                return false;
        }
        return true;
    }
};