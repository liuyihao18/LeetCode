// 3147_��ħ��ʦ������ȡ���������.cpp

#include "stdafx.h"
ustd

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        size_t n = energy.size();
        for (size_t i = n - 1; i != -1; i--) {
            energy[i] = energy[i] + (i + k < n ? energy[i + k] : 0);
        }
        return *max_element(energy.begin(), energy.end());
    }
};
