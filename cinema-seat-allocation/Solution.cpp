// https://leetcode.com/problems/cinema-seat-allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // (2,3,4,5) --> 0
        // (4,5,6,7) --> 1
        // (6,7,8,9) --> 2
        unordered_map<int, vector<int> >hall;
        for(int i=0;i<reservedSeats.size();i++){
            hall[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        int ans=0;
        for(auto it=hall.begin();it!=hall.end();it++){
            unordered_set<int>uns;
            uns.insert(0);
            uns.insert(1);
            uns.insert(2);
            vector<int>tmp=it->second;
            for(int num: tmp){
                if(num==1 || num==10)
                    continue;
                else if(num==2 || num==3){
                    uns.erase(0);
                }
                else if(num==4 || num==5){
                    uns.erase(0);
                    uns.erase(1);
                }
                else if(num==6 || num==7){
                    uns.erase(1);
                    uns.erase(2);
                }
                else {
                    uns.erase(2);
                }
            }
            int flag[3]={0,0,0};
            for(auto it=uns.begin();it!=uns.end();it++){
                flag[*it]=true;
            }
            if(flag[0] && flag[2])
                ans+=2;
            else if(flag[0] || flag[1] || flag[2]){
                ans+=1;
            }
            
        }
        ans+=((n-hall.size())*2);
        return ans;
    }
};