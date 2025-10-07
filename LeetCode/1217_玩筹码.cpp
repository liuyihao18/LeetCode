// 1217_Íæ³ïÂë.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        for (auto pos : position) pos & 1 ? odd++ : even++;
        return min(odd, even);
        /*
        return min<int>(
            count_if(begin(position), end(position), bind(modulus<int>(), placeholders::_1, 2)),
            count_if(begin(position), end(position), not_fn(bind(modulus<int>(), placeholders::_1, 2)))
            );
         */
    }
};
