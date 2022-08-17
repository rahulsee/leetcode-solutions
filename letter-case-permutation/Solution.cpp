// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    
    void solve(int cur, string &str, vector<string>&vec){
        if(cur==str.length()){
            vec.push_back(str);
            return;
        }
        if(str[cur]>='0' && str[cur]<='9')
            solve(cur+1, str, vec);
        else {
            char ch=str[cur];
            char ch2;
            if(ch>=97 && ch<=122)
                ch2=ch-32;
            else
                ch2=ch+32;
            str[cur]=ch2;
            solve(cur+1, str, vec);
            str[cur]=ch;
            solve(cur+1, str, vec);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string>vec;
        solve(0, S,vec);
        return vec;
    }
};