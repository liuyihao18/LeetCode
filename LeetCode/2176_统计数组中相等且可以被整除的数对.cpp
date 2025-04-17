// 2176_ͳ������������ҿ��Ա�����������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        int result = 0;
        for (const auto& [_, index] : m) {
            // �������¸��Ӷ���Ϊƽ��
            // �����п��ܿ���ͨ��һЩ��������
            for (size_t i = 0; i < index.size(); i++) {
                for (size_t j = i + 1; j < index.size(); j++) {
                    if (index[i] * index[j] % k == 0) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
