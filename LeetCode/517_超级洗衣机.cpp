// 517_超级洗衣机.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool move(vector<int>& machines, int avg_num) {
        auto origin_machines = machines;
        int left_sum = 0;
        vector<bool> moveds(machines.size(), false);
        for (size_t i = 0; i < origin_machines.size(); i++) {
            left_sum += origin_machines[i];
            if (left_sum < avg_num * static_cast<int>(i + 1)) {
                if (!moveds[i + 1] && origin_machines[i + 1] > 0) {
                    machines[i]++;
                    machines[i + 1]--;
                    moveds[i + 1] = true;
                }
            }
            else if (left_sum > avg_num * static_cast<int>(i + 1)) {
                if (!moveds[i] && origin_machines[i] > 0) {
                    machines[i]--;
                    machines[i + 1]++;
                    moveds[i] = true;
                }
            }
        }
        return accumulate(moveds.begin(), moveds.end(), false);
    }
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) {
            return -1;
        }
        int avg_num = sum / machines.size();
        /*
        int result = 0;
        while (move(machines, avg_num)) {
            result++;
        }
        */
        int result = 0;
        int left_sum = 0;
        for (size_t i = 0; i < machines.size(); i++) {
            left_sum += machines[i];
            result = max(abs(left_sum - avg_num * static_cast<int>(i + 1)), result); // 差额
            result = max(machines[i] - avg_num, result); // 一台洗衣机多的
        }
        return result;
    }
};