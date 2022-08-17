// https://leetcode.com/problems/flatten-nested-list-iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int>arr;
    int cur=0;
    
    
    void process(NestedInteger nint){
        if(nint.isInteger()){
            arr.push_back(nint.getInteger());
            return;
        }
        for(int i=0;i<nint.getList().size();i++){
            process(nint.getList()[i]);
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()){
                arr.push_back(nestedList[i].getInteger());
            }
            else {
                process(nestedList[i]);
            }
        }
    }
    
    int next() {
        if(cur==arr.size())
            return -1;
        int temp=arr[cur];
        cur++;
        return temp;
    }
    
    
    bool hasNext() {
        return cur<arr.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */