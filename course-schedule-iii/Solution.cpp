// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    
    struct custom1 {
        bool operator()(vector<int>a, vector<int>b){
            if(a[1]==b[1])
                return a[0]<b[0];
            return a[1]<b[1];
        }
    };
    
    struct custom2{
        bool operator()(vector<int>a, vector<int>b){
            return a[0]<b[0];
        }
    };
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), custom1());
        priority_queue<vector<int>, vector<vector<int> >, custom2>pq;
        vector<int>dummy(2,0);
        pq.push(dummy);
        int count=0;
        int ans=0;
        int sum=0;
        for(int i=0;i<courses.size();i++){
            if(courses[i][0]>courses[i][1])
                continue;
            if((sum+courses[i][0])<=courses[i][1]){
                pq.push(courses[i]);
                sum+=courses[i][0];
                count++;
            }   
            else if(pq.top()[0]>courses[i][0]) {
                while(!pq.empty()){
                    if((sum+courses[i][0])<=courses[i][1])
                        break;
                    vector<int>c=pq.top();
                    pq.pop();
                    sum-=c[0];
                    count--;
                }
                pq.push(courses[i]);
                sum+=courses[i][0];
                count++;
            }
            ans=max(ans, count);
        }
        return ans;
    }
};