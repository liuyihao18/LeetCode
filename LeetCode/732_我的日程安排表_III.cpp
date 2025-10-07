// 732_我的日程安排表_III.cpp
#include "stdafx.h"
ustd

class MyCalendarThree {
    map<int, int> m;
    int maxBookNum;
public:
    MyCalendarThree() : m(), maxBookNum(0) { m[0] = 0; }

    int book(int start, int end) {
        auto iter1 = m.lower_bound(start);
        auto iter2 = m.lower_bound(end);
        if (iter1 == m.end()) {
            m[start] = 1;
            m[end] = 0;
            maxBookNum = max(maxBookNum, 1);
        }
        else {
            for (map<int,int>::iterator iter = iter1; iter != iter2; ++iter) {
                iter->second++;
                maxBookNum = max(maxBookNum, iter->second);
            }
            if (iter1->first != start) {
                m[start] = (--iter1)->second + 1;
                maxBookNum = max(maxBookNum, m[start]);
            }
            if (iter2 == m.end() || iter2->first != end) {
                m[end] = (--iter2)->second - 1;
                maxBookNum = max(maxBookNum, m[end]);
            }
        }
        return maxBookNum;
    }
};
