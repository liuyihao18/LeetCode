// 458_������С��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // һֻС������T��ˮ������Я����Ϣ��Ϊ(T+1)
        // xֻС�����Я��(T+1)^x����Ϣ��
        // ������Ϊ��xά�ռ������(T+1)^x���㣬����ÿ������xά����ȷ��
        int T = minutesToTest / minutesToDie;
        int x = static_cast<int>(ceil(log(buckets) / log(T + 1)));
        return x;
    }
};