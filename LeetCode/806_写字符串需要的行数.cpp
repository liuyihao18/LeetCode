// 806_写字符串需要的行数.cpp
#include "custom.h"
ustd

#define rows result[0]
#define cursor result[1]

constexpr size_t INDEX(char c) {
    return static_cast<size_t>(c - 'a');
}

constexpr int MAX_WIDTH = 100;

class Solution {
public:
    vector<int> numberOfLines(const vector<int>& widths, string s) {
        vector<int> result = {1, 0};
        for (auto c : s) {
            if (cursor + widths[INDEX(c)] <= MAX_WIDTH) {
                cursor += widths[INDEX(c)];
            }
            else {
                rows++;
                cursor = widths[INDEX(c)];
            }
        }
        return result;
    }
};
