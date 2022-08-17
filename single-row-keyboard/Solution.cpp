// https://leetcode.com/problems/single-row-keyboard

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int>index;
        for(int i=0;i<keyboard.size();i++){
            index[keyboard[i]]=i;
        }
        int sum=index[word[0]];
        for(int i=1;i<word.length();i++){
            sum+=(abs(index[word[i]]-index[word[i-1]]));
        }
        return sum;
    }
};