// https://leetcode.com/problems/open-the-lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int>steps;
        queue<string>q;
        q.push("0000");
        unordered_set<string>dead(deadends.begin(), deadends.end());
        if(dead.find("0000")!=dead.end())
            return -1;
        while(!q.empty()){
            string num=q.front();
            q.pop();
            string front=num;
            if(front==target){
                return steps[front];
            }
            for(int i=0;i<4;i++){
                int digit=front[i]-'0';
                front[i]=(digit+1)%10+'0';
                if(dead.find(front)==dead.end() && steps.find(front)==steps.end()){
                    q.push(front);
                    steps[front]=steps[num]+1;
                }
                front[i]=(digit-1+10)%10+'0';
                if(dead.find(front)==dead.end() && steps.find(front)==steps.end()){
                    q.push(front);
                    steps[front]=steps[num]+1;
                }
                front[i]=digit+'0';
            }
        }
        return -1;
    }
};