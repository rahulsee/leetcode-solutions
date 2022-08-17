// https://leetcode.com/problems/word-abbreviation

struct TrieNode {
    bool isEnd;
    bool isPivot;
    unordered_map<char, TrieNode*>children;
    TrieNode(){
        isEnd=false;
        isPivot=true;
    }
};


class Solution {
public:
    
    TrieNode *root;
    
    void insert(string word){
        TrieNode *n=root;
        for(char ch: word){
            if(n->children.find(ch)==n->children.end()) {
                n->children[ch]=new TrieNode();
                n=n->children[ch];
            }
            else {
                n=n->children[ch];
                n->isPivot=false;
            }
        }
        n->isEnd=true;
    }
    
    string getAns(string word) {
        TrieNode *n=root;
        int pivotPos=0;
        for(char ch: word){
            n=n->children[ch];
            if(n->isPivot){
                break;
            }
            pivotPos++;
        }
        string ans;
        if(word.length()-pivotPos-2>0){
            for(int i=0;i<=pivotPos;i++){
                ans.push_back(word[i]);
            }
            ans+=to_string(word.length()-pivotPos-2);
            ans.push_back(word[word.length()-1]);
            if(ans.length()<word.length())
                return ans;
        }
        return word;
    }
    
    vector<string> wordsAbbreviation(vector<string>& words) {
       map<pair<char, int>, vector<string> >groups;
       for(string w: words){
           groups[make_pair(w[w.length()-1], w.length())].push_back(w);
       }
       unordered_map<string, string>answers;
       for(auto &[len, vec] : groups) {
           root=new TrieNode();
           for(string word: vec)
               insert(word);
           for(string word: vec)
               answers[word]=getAns(word);
       }
       vector<string>finalAns;
        for(string w: words){
            finalAns.push_back(answers[w]);
        }
        return finalAns;
    }
};