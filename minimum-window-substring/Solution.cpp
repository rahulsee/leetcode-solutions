// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    
    bool checkEqual(unordered_map<char,int>cnt, unordered_map<char, int>cnt2){
        for(auto it=cnt.begin();it!=cnt.end();it++){
            if(it->second>cnt2[it->first]){
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char, int>cnt;
        unordered_map<char, int>cnt2;
        for(int i=0;i<t.length();i++){
            cnt[t[i]]++;
        }
        int req=cnt.size();
        int start=0;
        int mini=s.length()+1;
        int st=0;
        int av=0;
        for(int i=0;i<s.length();i++)
        {
            cnt2[s[i]]++;
            if(cnt.find(s[i])!=cnt.end() && cnt2[s[i]]==cnt[s[i]])
                av++;
            if(req==av){
                while(start<i && cnt2[s[start]]>cnt[s[start]]){
                    cnt2[s[start]]--;
                    if(cnt2[s[start]]==0){
                        cnt2.erase(s[start]);
                    }
                    start++;
                }
                if((i-start+1) < mini){
                    mini=i-start+1;
                    st=start;
                }
            }
        }
        if(mini==s.length()+1)
            return "";
        return s.substr(st, mini);
    }
};