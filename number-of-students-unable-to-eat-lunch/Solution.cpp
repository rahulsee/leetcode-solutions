// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int>d;
        for(int num:students)
            d.push_back(num);
        int cur=0;
        int i=0;
        while(!d.empty() && i<(students.size()*students.size())) {
            int prev=d.size();
            while(cur < sandwiches.size()){
                if(d.front()==sandwiches[cur]) {
                    cur++;
                    d.pop_front();
                }
                else
                    break;
            }
            int num=d.front();
            d.pop_front();
            d.push_back(num);
            i++;
        }
        return d.size();
    }
};