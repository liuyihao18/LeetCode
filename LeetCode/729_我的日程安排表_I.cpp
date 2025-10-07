// 729_我的日程安排表_I.cpp
#include "stdafx.h"
ustd

class MyCalendar {
    map<int, int> m;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto iter = m.upper_bound(start);
        if (iter != m.begin()) {
            auto pre = prev(iter);
            if (pre->second > start) {
                return false;
            }
        }
        if (iter != m.end()) {
            if (end > iter->first) {
                return false;
            }
        }
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
