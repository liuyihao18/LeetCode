// 458_可怜的小猪.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // 一只小猪最多喝T次水，则其携带信息量为(T+1)
        // x只小猪最多携带(T+1)^x的信息量
        // 或者认为是x维空间最多有(T+1)^x个点，其中每个点由x维坐标确定
        int T = minutesToTest / minutesToDie;
        int x = static_cast<int>(ceil(log(buckets) / log(T + 1)));
        return x;
    }
};