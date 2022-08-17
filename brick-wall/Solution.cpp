// https://leetcode.com/problems/brick-wall

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int maxi=0;
        int fc=wall[0].size();
        for(int i=0;i<fc;i++){
            maxi+=wall[0][i];
        }
        unordered_map<int,int>count;
        unordered_set<int>notallow;
        for(int i=0;i<wall.size();i++){
            for(int j=1;j<wall[i].size();j++){
                wall[i][j]+=wall[i][j-1];
            }
            notallow.insert(wall[i][wall[i].size()-1]);
        }
        for(int i=0;i<wall.size();i++){
            for(int j=0;j<wall[i].size();j++){
                count[wall[i][j]]++;
            }
        }
        int mini=wall.size();
        for(auto it=count.begin();it!=count.end();it++){
            if(notallow.find(it->first)==notallow.end()){
                mini=min(mini, (int)wall.size()-it->second);
            }
        }
        return mini;
    }
};