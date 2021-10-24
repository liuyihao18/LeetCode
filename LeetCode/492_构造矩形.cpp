// 492_¹¹Ôì¾ØÐÎ.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int width = sqrt(area); width > 1; width--) {
            int length = area / width;
            if (width * length == area) {
                return  { length, width };
            }
        }
        return { area, 1 };
    }
};