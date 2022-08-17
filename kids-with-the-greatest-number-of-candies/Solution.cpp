// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans(candies.size(),false);
        int maxi=numeric_limits<int>::min();
        for(int i=0;i<candies.size();i++){
            maxi=max(maxi,candies[i]);
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= maxi){
                ans[i]=true;
            }
        }
        return ans;
    }
};