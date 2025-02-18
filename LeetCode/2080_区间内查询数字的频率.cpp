// 2080_区间内查询数字的频率.cpp
#include "custom.h"
ustd

constexpr size_t MAX_NUM = 10005;

class RangeFreqQuery {
    vector<vector<int>> positions;
public:
    RangeFreqQuery(vector<int>& arr) : positions(MAX_NUM, vector<int>()) {
        for (size_t i = 0; i < arr.size(); i++) {
            positions[arr[i]].push_back(static_cast<int>(i));
        }
    }

    int query(int left, int right, int value) {
        const vector<int>& position = positions[value];
        auto leftPos = lower_bound(position.begin(), position.end(), left);
        auto rightPos = upper_bound(position.begin(), position.end(), right);
        return static_cast<int>(distance(leftPos, rightPos));
    }
};
