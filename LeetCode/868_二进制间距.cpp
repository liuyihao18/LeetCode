// 868_二进制间距.cpp
#include "custom.h"
ustd

class Solution {
public:
    int binaryGap(int n) {
        vector<size_t> pos;
        for (size_t i = 0; i < 32 && n; i++, n >>= 1) {
            if (n & 1) {
                pos.push_back(i);
            }
        }
        if (pos.size() < 2) {
            return 0;
        }
        int max_interval = 0;
        for (size_t i = 0; i + 1 < pos.size(); i++) {
            max_interval = max(max_interval, static_cast<int>(pos[i + 1] - pos[i]));
        }
        return max_interval;
    }
};
