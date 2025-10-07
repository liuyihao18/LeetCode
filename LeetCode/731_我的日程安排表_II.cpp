// 731_�ҵ��ճ̰��ű�_II.cpp
#include "stdafx.h"
ustd

class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        // ����������ص������ص���������Ԥ��
        for (auto& [l, r] : overlaps) {
            if (l < end && start < r) {
                return false;
            }
        }
        // ���������Ԥ�����ص�����
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
