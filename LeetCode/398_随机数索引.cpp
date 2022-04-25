// 398_���������.cpp
#include "custom.h"
ustd

// ��ѧϰ��ˮ������
// ���� nums�������ǵ� i ������ֵΪ target ��Ԫ��ʱ�����ѡ������ [0,i) �ڵ�һ��������
// �������� 0���򽫷���ֵ��Ϊ��Ԫ�ص��±꣬���򷵻�ֵ����
class Solution {
    map<int, vector<int>> m;

public:
    Solution(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        const vector<int>& v = m[target];
        int n = static_cast<int>(v.size());
        return v[rand() % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
