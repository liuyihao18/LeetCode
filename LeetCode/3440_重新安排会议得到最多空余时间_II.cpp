// 3440_���°��Ż���õ�������ʱ��_II.cpp
#include "stdafx.h"
#include <bitset>
ustd

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
		size_t n = startTime.size();

        bitset<100005> bs = { 0 };
        
        // ͳ�ƿ���ʱ�䣨�������ң�
        int left = 0;
        int right = 0;
        int maxInterval = 0;
        for (size_t i = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= maxInterval) {
                bs[i] = true;
            }
            right = startTime[i];
            maxInterval = max(maxInterval, right - left);
            left = endTime[i];
        }

        // ͳ�ƿ���ʱ�䣨��������
        left = eventTime;
        right = eventTime;
        maxInterval = 0;
        for (size_t i = n - 1; i != -1; i--) {
            if (endTime[i] - startTime[i] <= maxInterval) {
                bs[i] = true;
            }
            left = endTime[i];
            maxInterval = max(maxInterval, right - left);
            right = startTime[i];
        }

        // �ϲ����ڵĿ���ʱ���
        int freeTime = 0;
        for (size_t i = 0; i < n; i++) {
            left = i == 0 ? 0 : endTime[i - 1];
            right = i + 1 == n ? eventTime : startTime[i + 1];
            int time = endTime[i] - startTime[i];

            // 1. ƽ��
            freeTime = max(freeTime, right - left - time);
            
            // 2. ���
            if (bs[i]) {
                freeTime = max(freeTime, right - left);
            }
        }

        return freeTime;
    }
};
