// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int>us;
        vector<int>a,b;
        int p=1;
        while(p<bound){
            a.push_back(p);
            p=p*x;
            if(x==1)
                break;
        }
        p=1;
        while(p<bound){
            b.push_back(p);
            if(y==1)
                break;
            p=p*y;
        }
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if(a[i]+b[j]<=bound){
                    us.insert(a[i]+b[j]);
                }
            }
        }
        vector<int>ans(us.begin(), us.end());
        return ans;
    }
};