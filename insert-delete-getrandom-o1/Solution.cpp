// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int>values;
    int size;
    RandomizedSet() {
        size=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(values.find(val)!=values.end())
            return false;
        values.insert(val);
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(values.find(val)!=values.end())
        {
            values.erase(val);
            size--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randindex=rand()%size;
        auto it=values.begin();
        for(int i=0;i<randindex;i++)
            it++;
        return *it;
            
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */