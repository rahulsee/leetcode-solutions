// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    
    unordered_map<char,char>index;
    
    string hash(string str){
        for(int i=0;i<str.length();i++)
            str[i]=index[str[i]];
        return str;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string>hashvals;
        index.clear();
        for(int i=0;i<order.size();i++)
            index[order[i]]=i+'a';
        for(string w: words){
            hashvals.push_back(hash(w));
        }
        for(int i=1;i<hashvals.size();i++){
            if(hashvals[i]<hashvals[i-1])
                return false;
        }
        return true;
    }
};