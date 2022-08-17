// https://leetcode.com/problems/queue-reconstruction-by-height

class Solution {
public:
    
    struct person 
    {
        int index;
        int height;
        int demand;
        person(int i,int h, int d)
        {
            index=i;
            height=h;
            demand=d;
        }
    };
    
    struct cmp 
    {
        bool operator()(person a, person b)
        {
            return a.height > b.height;
        }
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       priority_queue<person, vector<person>, cmp>pq;
        vector<int>g[people.size()];
        vector<int>demand(people.size());
        for(int i=0;i<people.size();i++)
        {
            demand[i]=people[i][1];
            for(int j=0;j<people.size();j++)
            {
                if(people[i][0] >= people[j][0] && i!=j)
                {
                    g[i].push_back(j);
                }
            }
        }
        for(int i=0;i<people.size();i++)
        {
            if(people[i][1]==0)
            {
                pq.push(person(i, people[i][0], people[i][1]));
            }
        }
        vector<vector<int> >ans;
        while(!pq.empty())
        {
            person p=pq.top();
            pq.pop();
            int index=p.index;
            vector<int>pp;
            pp.push_back(p.height);
            pp.push_back(demand[p.index]);
            ans.push_back(pp);
            for(int child: g[index])
            {
                people[child][1]--;
                if(people[child][1] == 0)
                {
                    pq.push(person(child, people[child][0], people[child][1]));
                }
            }
            
        }
        return ans;
    }
};