// https://leetcode.com/problems/all-oone-data-structure

class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int>m;
    AllOne() {
        
    }
    
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.find(key)!=m.end())
            m[key]++;
        else
            m[key]=1;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.find(key)==m.end())
            return;
        if(m[key]==1)
            m.erase(key);
        else
            m[key]--;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        int maxval=numeric_limits<int>::min();
        string ans="";
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second > maxval)
            {
                maxval=it->second;
                ans=it->first;
            }
        }
        return ans;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        int minval=numeric_limits<int>::max();
        string ans="";
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second < minval)
            {
                minval=it->second;
                ans=it->first;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */