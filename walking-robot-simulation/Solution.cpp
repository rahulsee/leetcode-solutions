// https://leetcode.com/problems/walking-robot-simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        int maxdist=0;
        int xdirn[]={0, -1, 0, 1};
        int ydirn[]={1, 0, -1, 0};
        int curx=0;
        int cury=0;
        unordered_map<int, unordered_set<int> >obs;
        for(int i=0;i<obstacles.size();i++){
            obs[obstacles[i][0]].insert(obstacles[i][1]);
        }
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                cury=(cury-1+4)%4;
                curx=(curx-1+4)%4;
            }
            else if(commands[i]==-2){
                cury=(cury+1)%4;
                curx=(curx+1)%4;
            }
            else {
                int tmpx;
                int tmpy;
                int xx=x;
                int yy=y;
                for(int j=1;j<=commands[i];j++){
                    tmpx=xx+j*xdirn[curx];
                    tmpy=yy+j*ydirn[cury];
                    if(obs.find(tmpx)!=obs.end() && obs[tmpx].find(tmpy)!=obs[tmpx].end()){
                        break;
                    }
                    x=tmpx;
                    y=tmpy;
                }
                maxdist=max(maxdist, x*x+y*y);
            }
        }
        return maxdist;
    }
};