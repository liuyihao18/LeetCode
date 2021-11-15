// 319_灯泡开关.cpp
#include "custom.h"
ustd

class Solution {
public:
    int bulbSwitch(int n) {
        /**
        * 其实是寻找完全平方数
        * 第n个灯泡开关次数即n的因数个数
        * 如果n不是完全平方数，则n总是有偶数个因数，即灯泡状态为熄灭
        * 所以若灯泡最终状态为亮起，则n有奇数个因数，即n为完全平方数
        */
        return static_cast<int>(floor(sqrt(n)));
    }
};