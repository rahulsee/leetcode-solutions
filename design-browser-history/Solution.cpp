// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:
    stack<string>s1;
    stack<string>s2;
    
    BrowserHistory(string homepage) {
        s1.push(homepage);
    }
    
    void visit(string url) {
        s1.push(url);
        while(!s2.empty())
            s2.pop();
    }
    
    string back(int steps) {
        int i=0;
        int n=s1.size()-1;
        steps=min(steps,n);
        while(i<steps)
        {
            s2.push(s1.top());
            s1.pop();
            i++;
        }
        return s1.top();
    }
    
    string forward(int steps) {
        int i=0;
        int n=s2.size();
        steps=min(steps,n);
        while(i<steps){
            s1.push(s2.top());
            s2.pop();
            i++;
        }
        return s1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */