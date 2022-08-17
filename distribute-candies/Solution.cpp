// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>us;
        for(int num: candyType){
            us.insert(num);
        }
        return min(us.size(), candyType.size()/2);
    }
};