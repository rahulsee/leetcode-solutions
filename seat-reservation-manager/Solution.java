// https://leetcode.com/problems/seat-reservation-manager

class SeatManager {

    TreeSet<Integer> ts;
    
    public SeatManager(int n) {
        ts=new TreeSet<>();
        for(int i=1;i<=n;i++){
            ts.add(i);
        }
    }
    
    public int reserve() {
        int index=ts.first();
        ts.remove(index);
        return index;
    }
    
    public void unreserve(int seatNumber) {
        ts.add(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */