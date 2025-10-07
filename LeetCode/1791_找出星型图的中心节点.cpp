// 1791_找出星型图的中心节点.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        const auto& edge1 = edges[0];
        const auto& edge2 = edges[1];
        int result = edge1[0];
        return find_if(edge2.begin(), edge2.end(), [=](int i) {
            return i == result;
            }) != edge2.end() ? result : edge1[1];
    }
};
