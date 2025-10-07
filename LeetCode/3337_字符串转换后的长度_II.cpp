// 3337_�ַ���ת����ĳ���_II.cpp
#include "stdafx.h"
ustd

// ��ʱ����Ҫʹ�þ��������
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int MOD = static_cast<int>(1e9 + 7);
        vector<int> counts(26, 0);
        for (auto c : s) {
            counts[static_cast<size_t>(c - 'a')]++;
        }
        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0);
            for (size_t j = 0; j < 26; j++) {
                for (size_t k = 1; k <= nums[j]; k++) {
                    temp[(j + k) % 26] = (temp[(j + k) % 26] + counts[j]) % MOD;
                }
            }
            counts = std::move(temp);
        }
        int result = 0;
        for (auto count : counts) {
            result = (result + count) % MOD;
        }
        return result;
    }
};
