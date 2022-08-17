// https://leetcode.com/problems/design-add-and-search-words-data-structure

struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<26;i++)
            children[i]=0;
        isEndOfWord=false;
    }
};

bool search(TrieNode *root,string word){
    int len=word.length();
    TrieNode *t=root;
    for(int i=0;i<len;i++)
    {
        int index=0;
        index=word[i]-'a';
        if(t!=NULL)
        t=t->children[index];
    }
    //cout<<t->isEndOfWord<<endl;
    return (t!=NULL && t->isEndOfWord==true);
}

bool searchRegex(TrieNode *root,string word,int cur){
    
    if(root==NULL)
        return false;
    
    if(cur==word.size())
    {
        return root->isEndOfWord;
    }
    
    if(word[cur]=='.')
    {
        bool result=false;
        for(int i=0;i<26;i++)
        {
            result=result || searchRegex(root->children[i],word,cur+1);
        }
        return result;
    }
    else
    {
        int index=word[cur]-'a';
        cout<<"CUR IS "<<cur<<" WORD[CUR] is "<<(int)word[cur]<<" ";
        cout<<"INDEX IS "<<index<<endl;
        return searchRegex(root->children[index],word,cur+1);
    }
    return false;
}

void insert(TrieNode *root, string word){
    int len=word.length();
    TrieNode *t=root;
    TrieNode *p=root;
    for(int i=0;i<len;i++)
    {
        int index;
        index=word[i]-'a';
        if(t->children[index]==NULL)
            t->children[index]=new TrieNode();
        t=t->children[index];
    }
    t->isEndOfWord=true;
}



class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode *trie;
    WordDictionary() {
        trie=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(trie,word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.find('.')==string::npos){
            cout<<"SEARCHING FOR "<<word<<endl;
        return ::search(trie,word);
        }
        else{
            cout<<"SEARCHING FOR "<<word<<endl;
            return ::searchRegex(trie,word,0);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */