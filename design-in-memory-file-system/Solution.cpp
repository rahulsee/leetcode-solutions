// https://leetcode.com/problems/design-in-memory-file-system

class FileSystem {
public:
    struct Node {
        string content;
        bool isDir;
        unordered_map<string, Node*>children;
        Node(){
            isDir=false;
        }
    };
    Node *root;
    FileSystem() {
        root=new Node;
        root->isDir=true;
    }
    
    vector<string>split(string s){
        stringstream check1(s);
        string p;
        Node *r=root;
        vector<string>vec;
        while(getline(check1, p, '/')){
            vec.push_back(p);
        }
        return vec;
    }
    
    vector<string> ls(string path) {
        vector<string>vec=split(path);
         vector<string>ans;
        Node *r=root;
        for(int i=1;i<vec.size();i++){
            if(r->children.find(vec[i])==r->children.end()){
                return ans;
            }
            r=r->children[vec[i]];
        }
       
        if(!r->isDir){
            ans.push_back(vec[vec.size()-1]);
            return ans;
        }
        for(auto it=r->children.begin();it!=r->children.end();it++){
            ans.push_back(it->first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    
    
    void mkdir(string path) {
        vector<string>vec=split(path);
        Node *r=root;
        for(int i=1;i<vec.size();i++){
            if(r->children.find(vec[i])==r->children.end()){
                r->children[vec[i]]=new Node;
            }
            r->isDir=true;
            r=r->children[vec[i]];
        }
        r->isDir=true;
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string>vec=split(filePath);
        Node *r=root;
        for(int i=1;i<vec.size();i++){
            if(r->children.find(vec[i])==r->children.end()){
                r->children[vec[i]]=new Node;
            }
            r->isDir=true;
            r=r->children[vec[i]];
        }
        r->isDir=false;
        r->content+=content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string>vec=split(filePath);
        string empty="";
        Node *r=root;
        for(int i=1;i<vec.size();i++){
            if(r->children.find(vec[i])==r->children.end()){
                return "";
            }
            r=r->children[vec[i]];
        }
        if(r->isDir)
            return empty;
        return r->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */