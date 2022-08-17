// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>S;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i][0]>='0' && ops[i][0]<='9' || ops[i][0]=='-')
            {
                int score=stoi(ops[i]);
                S.push(score);
            }
            else if(ops[i]=="C")
            {
                if(!S.empty())
                    S.pop();
            }
            else if(ops[i]=="D")
            {
                if(!S.empty())
                {
                    S.push(S.top()*2);
                }
            }
            else if(ops[i]=="+")
            {
                if(S.size()>=2)
                {
                    int a=S.top();
                    S.pop();
                    int b=S.top();
                    S.pop();
                    S.push(b);
                    S.push(a);
                    S.push(a+b);
                }
            }
            
        }
        int total=0;
        while(!S.empty())
        {
            total+=S.top();
            S.pop();
        }
        return total;
    }
};