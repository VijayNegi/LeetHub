class SeatManager {
    set<int> available;
public:
    SeatManager(int n) {
        while(n>0)
            available.insert(n--);
    }
    
    int reserve() {
        int seat = *available.begin();
        available.erase(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        available.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */