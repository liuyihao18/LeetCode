// 731_我的日程安排表_II.cpp
#include "stdafx.h"
ustd

class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        // 如果和已有重叠区间重叠，则三次预定
        for (auto& [l, r] : overlaps) {
            if (l < end && start < r) {
                return false;
            }
        }
        // 求出和其他预订的重叠区间
        for (auto& [l, r] : booked) {
            if (l < end && start < r) {
                overlaps.emplace_back(max(l, start), min(r, end));
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
