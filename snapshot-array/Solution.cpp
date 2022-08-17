// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:

    
    unordered_map<int, unordered_map<int,int> >history;
    unordered_map<int, set<int> >snap_history;
    int snap_id=0;
    
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        history[index][snap_id]=val;
        snap_history[index].insert(-snap_id);
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto it=snap_history[index].lower_bound(-snap_id);
        int x=*it;
        x=-x;
        return history[index][x];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */