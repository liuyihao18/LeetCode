// 825_适龄的朋友.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result_odd = 0, result_even = 0;
        sort(ages.begin(), ages.end());
        // 循环展开
        for (size_t i = 0; i < ages.size(); i += 2) {
            int age = ages[i];
            int low = age / 2 + 8;
            int up = age;
            if (low > up) {
                continue;
            }
            auto low_iter = lower_bound(ages.begin(), ages.end(), low);
            auto up_iter = upper_bound(ages.begin(), ages.end(), up);
            result_even += static_cast<int>(distance(low_iter, up_iter)) - 1;
        }
        for (size_t i = 1; i < ages.size(); i += 2) {
            int age = ages[i];
            int low = age / 2 + 8;
            int up = age;
            if (low > up) {
                continue;
            }
            auto low_iter = lower_bound(ages.begin(), ages.end(), low);
            auto up_iter = upper_bound(ages.begin(), ages.end(), up);
            result_odd += static_cast<int>(distance(low_iter, up_iter)) - 1;
        }
        /*
        for (auto age : ages) {
            int low = 0.5 * age + 8;
            int up = age;
            if (age < 100) {
                up = min(up, 100);
            }
            if (low > up) {
                continue;
            }
            auto low_iter = lower_bound(ages.begin(), ages.end(), low);
            auto up_iter = upper_bound(ages.begin(), ages.end(), up);
            result += distance(low_iter, up_iter) - 1;
        }
        */
        return result_odd + result_even;
    }
};
