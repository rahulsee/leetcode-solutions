// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    
    struct node {
        int val;
        node *next;
        node *prev;
        node(int v){
            val=v;
            next=prev=NULL;
        }
    };
    
    int size;
    node *head;
    node *tail;
    int cnt;
    
    MyCircularQueue(int k) {
          head=tail=NULL;
          size=k;
          cnt=0;
    }
    
    bool enQueue(int value) {
        if(cnt==size)
            return false;
        cnt++;
        node *nn=new node(value);
        if(head==NULL)
            head=tail=nn;
        else {
            tail->next=nn;
            nn->prev=tail;
            tail=nn;
        }
        return true;
    }
    
    bool deQueue() {
        if(cnt==0)
            return false;
        cnt--;
        head=head->next;
        return true;
    }
    
    int Front() {
        if(cnt==0)
            return -1;
        return head->val;
    }
    
    int Rear() {
        if(cnt==0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */