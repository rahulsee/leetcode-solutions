// https://leetcode.com/problems/design-search-autocomplete-system

struct TrieNode {
    char ch;
    bool end;
    unordered_map<char, TrieNode*>children;
    TrieNode(char ch){
        this->ch=ch;
        end=false;
    }
};

struct Trie {
    TrieNode *root;
    Trie(){
        root=new TrieNode('$');
    }
    void addWord(string word){
        TrieNode *r=root;
        for(char ch: word){
            if(r->children.find(ch)==r->children.end()){
                r->children.insert({ch, new TrieNode(ch)});
            }
            r=r->children[ch];
        }
        r->end=true;
    }
    
    bool findWord(string word){
        TrieNode *r=root;
        for(char ch: word){
            if(r->children.find(ch)==r->children.end()){
                return false;
            }
            r=r->children[ch];
        }
        return r->end;
    }
    
    TrieNode* get(string pref){
        TrieNode *r=root;
        for(char ch: pref){
            if(r->children.find(ch)==r->children.end()){
                return NULL;
            }
            r=r->children[ch];
        }
        return r;
    }
    
    void findAll(TrieNode *root, string pref, string &word, vector<string>&arr){
        if(root && root->end){
            arr.push_back(word);
        }
        if(root==NULL)
            return;
        for(auto it=root->children.begin();it!=root->children.end();it++){
            word.push_back(it->first);
            findAll(it->second,pref, word, arr);
            word.pop_back();
        }
    }
    
};

class AutocompleteSystem {
public:
    unordered_map<string, int>counts;
    Trie trie;
    string pref;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        counts.clear();
        pref="";
        Trie newTrie;
        trie=newTrie;
        for(int i=0;i<sentences.size();i++){
            counts[sentences[i]]=times[i];
            trie.addWord(sentences[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c=='#'){
            trie.addWord(pref);
            counts[pref]++;
            pref="";
            vector<string>v;
            return v;
        }
        pref.push_back(c);
        vector<string>arr;
        string str;
        trie.findAll(trie.get(pref), pref, str, arr);
        for(int i=0;i<arr.size();i++){
            arr[i]=pref+arr[i];
        }
        for(int i=0;i<min((int)arr.size(),3);i++){
            for(int j=i+1;j<arr.size();j++){
                if(counts[arr[i]] < counts[arr[j]]){
                    swap(arr[i],arr[j]);
                }
                else if(counts[arr[i]]==counts[arr[j]]){
                    if(arr[i] > arr[j]){
                        swap(arr[i], arr[j]);
                    }
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<min((int)arr.size(), 3);i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */