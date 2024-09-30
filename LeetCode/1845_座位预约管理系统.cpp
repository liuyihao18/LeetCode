// 1845_座位预约管理系统.cpp
#include "custom.h"
ustd

class SeatManager {
    set<int> seats;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            seats.insert(i);
        }
    }

    int reserve() {
        int seatNumber = *seats.begin();
        seats.erase(seats.begin());
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
