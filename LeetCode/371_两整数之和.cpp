// 371_������֮��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            // ȡ�����λ
            int least_a = (a >> i) & 1; 
            int least_b = (b >> i) & 1;
            sum = (sum) | (least_a ^ least_b ^ carry) << i;
            // �����λ
            carry = (least_a & least_b) | (least_a & carry) | (least_b & carry);
        }
        return sum;
    }
};