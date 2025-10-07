// 1710_卡车上的最大单元数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& boxType1, const vector<int>& boxType2) {
            return boxType1[1] > boxType2[1];
            });
        int result = 0;
        size_t index = 0;
        while (truckSize > 0) {
            while (index < boxTypes.size() && boxTypes[index][0] <= 0) {
                index++;
            }
            if (index >= boxTypes.size()) {
                break;
            }
            result += boxTypes[index][1];
            boxTypes[index][0]--;
            truckSize--;
        }
        return result;
    }
};
