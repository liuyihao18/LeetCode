// 1450_�ڼȶ�ʱ������ҵ��ѧ������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int result = 0;
        for (size_t i = 0; i < startTime.size(); i++) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                result++;
            }
        }
        return result;
    }
};
