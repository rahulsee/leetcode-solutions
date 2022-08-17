// https://leetcode.com/problems/employee-free-time

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

struct compare {
    bool operator()(Interval a, Interval b){
        return a.start < b.start;
    }
};

class Solution {
public:
    
    bool overlap(Interval a, Interval b){
        if(a.end >= b.start){
            return true;
        }
        return false;
    }
    
    Interval merge(Interval a, Interval b){
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval>worktime;
        for(vector<Interval>vec: schedule){
            for(Interval i: vec){
                worktime.push_back(i);
            }
        }
        sort(worktime.begin(), worktime.end(), compare());
        stack<Interval>st;
        st.push(worktime[0]);
        vector<Interval>freetime;
        for(int i=1;i<worktime.size();i++){
            if(overlap(st.top(), worktime[i])) {
                Interval top=st.top();
                st.pop();
                st.push(merge(top, worktime[i]));
            }
            else {
                freetime.push_back(Interval(st.top().end, worktime[i].start));
                st.push(worktime[i]);
            }
        }
               return freetime;
    }
};