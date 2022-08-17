// https://leetcode.com/problems/ipo

struct node{
    int index;
    int profit;
    int capital;
    node(int i,int p,int c){
        index=i;
        profit=p;
        capital=c;
    }
    node(){
        
    }
};


struct comp{
    bool operator()(node a,node b)
    {
        if(a.capital==b.capital)
            return a.profit < b.profit;
        return a.capital > b.capital;
    }
};
struct comp2{
    bool operator()(node a,node b)
    {
        return a.profit < b.profit;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<node,vector<node>,comp>pcq;
        priority_queue<node,vector<node>,comp2>pq;
        int numproj=0;
        for(int i=0;i<Profits.size();i++){
            pcq.push(node(i,Profits[i],Capital[i]));
        }
        while(k--){
            while(!pcq.empty() && pcq.top().capital <= W){
                pq.push(pcq.top());
                pcq.pop();
            }
            if(!pq.empty())
            {
                W+=pq.top().profit;
                numproj++;
                pq.pop();
            }
            else
                break;
        }
        return W;
    }
};