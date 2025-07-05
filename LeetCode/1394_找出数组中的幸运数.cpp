// 1394_�ҳ������е�������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }
        for (auto iter = countMap.rbegin(); iter != countMap.rend(); ++iter) {
            if (iter->first == iter->second) {
                return iter->first;
            }
        }
        return -1;
    }
};
