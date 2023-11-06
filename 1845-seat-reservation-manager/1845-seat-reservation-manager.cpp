class SeatManager {
public:
    set<int> r;
    set<int> ur;
    SeatManager(int n) {
        for(int i=1 ; i<=n ; i++){
            ur.insert(i);
        }
    }
    
    int reserve() {
        int mini=*ur.begin();
        ur.erase(ur.begin());
        r.insert(mini);
        return mini;
    }
    
    void unreserve(int seatNumber) {
        r.erase(seatNumber);
        ur.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */