// https://leetcode.com/problems/design-circular-deque

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
    Node(){
        next=NULL;
        prev=NULL;
    }
};

class MyCircularDeque {
public:
    
    
    int tot;
    int count=0;
    Node *front=NULL;
    Node *rear=NULL;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        tot=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(count == tot)
            return false;
        Node *n=new Node(value);
        if(front==NULL && rear==NULL)
        {
            front=rear=n;
        }
        else{
            n->next=front;
            front->prev=n;
            front=n;
        }
        count++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(count == tot)
            return false;
        Node *n=new Node(value);
        if(front==NULL && rear==NULL)
        {
            front=rear=n;
        }
        else {
            rear->next=n;
            n->prev=rear;
            rear=n;
        }
        count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(count==0)
            return false;
        if(front==NULL)
            return false;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        if(front!=NULL)
            front->prev=NULL;
        count--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(count==0)
            return false;
        if(rear==NULL)
            return false;
        rear=rear->prev;
        if(rear!=NULL)
        rear->next=NULL;
        if(rear==NULL)
            front=NULL;
        count--;
        // delete tmp;
        // tmp=NULL;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(front==NULL){
            rear=NULL;
            return -1;
        }
        return front->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(rear==NULL){
            front=NULL;
            return -1;
        }
        return rear->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count==tot;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */