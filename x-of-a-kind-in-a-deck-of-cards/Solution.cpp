// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>count;
        for(int i=0;i<deck.size();i++)
            count[deck[i]]++;
        bool flag=true;
        int gcd=-1;
        for(auto it=count.begin();it!=count.end();it++){
            if(gcd==-1)
                gcd=it->second;
            else
                gcd=__gcd(it->second,gcd);
        }
        cout<<gcd<<endl;
        if(gcd>=2){
            return true;
        }
        else
            return false;
    }
};