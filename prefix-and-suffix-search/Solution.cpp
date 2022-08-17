// https://leetcode.com/problems/prefix-and-suffix-search

struct TrieNode {
    int index;
    unordered_map<char, TrieNode*>children;
    TrieNode(){
        index=-1;
    }
};

struct Trie {
    TrieNode *root;
    Trie(){
        root=new TrieNode;
    }
    
    void insertWord(string word, int index){
        TrieNode *node=root;
        for(char ch: word){
            if(node->children.find(ch)==node->children.end()){
                node->children[ch]=new TrieNode;
            }
            node=node->children[ch];
            node->index=index;
        }
        node->index=index;
    }
    
    int search(string word){
        TrieNode *node=root;
        for(char ch: word){
            if(node->children.find(ch)==node->children.end())
                return -1;
            node=node->children[ch];
        }
        return node->index;
    }
    
};

class WordFilter {
public:
    
    Trie trie;
    
    WordFilter(vector<string>& words) {
        int cnt=0;
        for(string word: words){
            string suff="#";
            for(int i=word.length()-1;i>=0;i--){
                suff=string(1, word[i])+suff;
                trie.insertWord(suff+word, cnt);
            }
            cnt++;
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.search(suffix+"#"+prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */