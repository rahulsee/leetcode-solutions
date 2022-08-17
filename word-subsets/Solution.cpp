// https://leetcode.com/problems/word-subsets

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int maxreq[26];
        memset(maxreq, 0, sizeof(maxreq));
        for(string w: B){
            int req[26];
            memset(req,0, sizeof(req));
            for(char c: w)
                req[c-'a']++;
            for(int i=0;i<26;i++){
                maxreq[i]=max(maxreq[i], req[i]);
            }
        }
        vector<string>ans;
        for(string w: A){
            int req[26];
            memset(req,0, sizeof(req));
            for(char c: w)
                req[c-'a']++;
            bool flag=true;
            for(int i=0;i<26;i++){
                if(req[i] < maxreq[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(w);
        }
        return ans;
    }
};