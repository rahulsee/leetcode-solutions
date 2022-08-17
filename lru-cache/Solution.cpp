// https://leetcode.com/problems/lru-cache

struct Node {
    int val;
    int key;
    Node *next;
    Node *prev;
};

class LRUCache {
public:
    
    int cap;
    unordered_map<int, Node*>umap;
    Node *head;
    Node *tail;
    
    LRUCache(int capacity) {
        cap=capacity;  
        head=NULL;
        tail=NULL;
    }
    
    
    void addNewNode(int key, int val){
        Node *newNode=new Node;
        newNode->val=val;
        newNode->key=key;
        newNode->prev=newNode->next=NULL;
        umap[key]=newNode;
        if(head==NULL){
            head=tail=newNode;
        }
        else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    
    void removeNode(int key){
        if(umap.find(key)==umap.end())
            return;
        Node *ptr=umap[key];
        umap.erase(key);
        if(ptr==head){
            head=head->next;                
        }
        else if(ptr==tail){
            tail=tail->prev;
        }
        else {
            Node *next=ptr->next;
            Node *prev=ptr->prev;
            prev->next=next;
            next->prev=prev;
        }
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()){
            return -1;
        }
        int val=umap[key]->val;
        removeNode(key);
        addNewNode(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(umap.find(key)==umap.end()){
            addNewNode(key,value);
            if(umap.size()>cap){
                umap.erase(head->key);
                head=head->next;
            }
        }
        else {
            removeNode(key);
            addNewNode(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */