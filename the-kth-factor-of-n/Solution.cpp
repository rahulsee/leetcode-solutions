// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int, vector<int>, greater<int> >factors;
        int start=2;
        int inc=1;
        factors.push(1);
        if(n%2){
            start++;
            inc++;
        }
        for(int i=start;(i*i)<=n;i+=inc){
            if(n%i==0){
                factors.push(i);
                if(i*i < n)
                    factors.push(n/i);
            }
        }
        factors.push(n);
        for(int i=0;i<k-1;i++){
            if(factors.empty())
                break;
            factors.pop();
        }
        if(factors.empty())
            return -1;
        return factors.top();
    }
};