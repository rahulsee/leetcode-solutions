// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:
    
    struct node {
        int val;
        int freq;
        node *next;
        node *prev;
        node(){
            next=prev=NULL;
            freq=0;
        }
    };
    
    unordered_map<int,int>freq;
    priority_queue<int>pq;
    node *head, *tail;
    
    FreqStack() {
        freq.clear();
        head=tail=NULL;
    }
    
    void push(int x) {
        node *nn=new node;
        nn->val=x;
        freq[nn->val]++;
        pq.push(freq[nn->val]);
        nn->freq=freq[nn->val];
        if(head==NULL){
            head=tail=nn;
        }
        else {
            tail->next=nn;
            nn->prev=tail;
            tail=nn;
        }
    }
    
    int pop() {
        node *t=tail;
        node *k=NULL;
        while(t!=NULL){
            if(t->freq==pq.top()){
                k=t;
                pq.pop();
                break;
            }
            t=t->prev;
        }
        if(k==tail){
            tail=tail->prev;
        }
        else if(k==head){
            head=head->next;
            head->prev=NULL;
        }
        else {
            node *next=k->next;
            node *prev=k->prev;
            prev->next=next;
            next->prev=prev;
        }
        freq[k->val]--;
        return k->val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */