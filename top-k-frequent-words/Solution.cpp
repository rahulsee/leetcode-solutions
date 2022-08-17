// https://leetcode.com/problems/top-k-frequent-words

struct sorter{
    bool operator()(pair<string,int>a,pair<string,int>b)
    {
        if(a.second==b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>count;
        for(int i=0;i<words.size();i++)
        {
            count[words[i]]++;
        }
        vector<pair<string,int> >p;
        for(auto it=count.begin();it!=count.end();it++)
        {
            p.push_back(*it);
        }
        sort(p.begin(),p.end(),sorter());
        vector<string>w;
        for(int i=0;i<k;i++)
        {
            w.push_back(p[i].first);
        }
        return w;
    }
};