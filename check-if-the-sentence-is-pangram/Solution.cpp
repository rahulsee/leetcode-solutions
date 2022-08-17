// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
       unordered_set<char>us;
       for(char ch: sentence){
           us.insert(ch);
       }
       return us.size()==26;
    }
};