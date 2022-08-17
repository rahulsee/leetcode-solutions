// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    
    bool subseq(string a, string b){
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(cnt<b.length() && a[i]==b[cnt]){
                cnt++;
            }
        }
        return cnt==b.length();
    }    
    
    struct custom{
        bool operator()(string a, string b){
            if(a.length()==b.length()){
                return a<b;
            }
            return a.length()>b.length();
        }
    };
    
    string findLongestWord(string s, vector<string>& d) {
        string longest="";
        sort(d.begin(), d.end(), custom());
        int ll=0;
        for(int i=0;i<d.size();i++){
            if(subseq(s,d[i])){
                return d[i];
            }
        }
        return "";
    }
};