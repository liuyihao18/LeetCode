// 1401_圆和矩形是否有重叠.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = std::clamp(xCenter, x1, x2) - xCenter;
        int y = std::clamp(yCenter, y1, y2) - yCenter;
        return x * x + y * y <= radius * radius;
    }
};
