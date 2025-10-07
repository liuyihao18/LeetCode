// 492_¹¹Ôì¾ØÐÎ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int width = static_cast<int>(sqrt(area)); width > 1; width--) {
            int length = area / width;
            if (width * length == area) {
                return  { length, width };
            }
        }
        return { area, 1 };
    }
};