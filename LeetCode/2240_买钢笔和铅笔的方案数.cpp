// 2240_��ֱʺ�Ǧ�ʵķ�����.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long result = 0;
        for (int i = 0; i * cost1 <= total; i++) {
            result += (total - i * cost1) / cost2 + 1;
        }
        return result;
    }
};
