// 2038_如果相邻两个颜色均相同则删除当前颜色.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool winnerOfGame(string colors) {
        size_t A_can_do = 0;
        size_t B_can_do = 0;
        for (size_t i = 1; i + 1 < colors.size(); i++) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A') {
                A_can_do++;
            }
            else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B') {
                B_can_do++;
            }
        }
        return A_can_do > B_can_do;
    }
};
