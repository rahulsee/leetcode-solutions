// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string table[]={".-","-...","-.-.","-..",".","..-.","--.",
                        "....","..",".---","-.-",".-..","--","-.","---",
                        ".--.","--.-",".-.","...","-","..-","...-",".--",
                        "-..-","-.--","--.."};
        unordered_set<string>unique;
        for(string word: words){
            string tmp;
            for(char c: word){
                tmp+=table[c-'a'];
            }
            unique.insert(tmp);
        }
        return unique.size();
    }
};