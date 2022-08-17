// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    
    long long hash(vector<string>word){
        long long hash_value=0;
        const int p = 31;
        const int m = 1e9 + 9;
        long long p_pow = 1;
        for(string w: word){
            for(char c: w){
                hash_value=(hash_value+(c-'a')*p_pow)%m;
                p_pow=(p_pow*p)%m;
            }
        }
        return hash_value;
    }
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        long long x=hash(word1);
        long long y=hash(word2);
        return x==y;
    }
};