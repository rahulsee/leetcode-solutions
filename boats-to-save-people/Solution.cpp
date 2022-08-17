// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count=0;
        if(people.size()==1)
            return count;
        int left=0;
        int right=people.size()-1;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
                right--;
            }
            else {
                right--;
            }
            count++;
        }
        return count;
    }
};