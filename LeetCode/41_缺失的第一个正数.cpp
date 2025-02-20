// 41_ȱʧ�ĵ�һ������.cpp
#include "custom.h"
ustd

// ԭ�ع�ϣ����
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n = nums.size();
        for (size_t i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[static_cast<size_t>(nums[i] - 1)]) {
                    break;
                }
                swap(nums[i], nums[static_cast<size_t>(nums[i] - 1)]);
            }
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return static_cast<int>(i + 1);
            }
        }
        return static_cast<int>(n + 1);
    }
};

/*
* ��������޷���������д����ظ�Ԫ�ص����
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n = nums.size();
        size_t slow = 0;
        for (size_t fast = 0; fast < n; fast++) {
            if (nums[fast] > 0) {
                nums[slow++] = nums[fast];
            }
        }
        nums.erase(nums.begin() + slow, nums.end());
        size_t l = 0, r = nums.size();
        while (l < r) { // [l, r)
            size_t m = (l + r + 1) / 2;  // ѡȡ�м����
            size_t i = l, j = r - 1;
            // �������Ϊê�㣬�ѱ���С�ķ���������ߣ�������ķ��������ұ�
            while (i < j + 1) {
                while (i < j + 1 && nums[i] <= m) {
                    i++;
                }
                while (i < j + 1 && nums[j] > m) {
                    j--;
                }
                if (i < j + 1) {
                    swap(nums[i], nums[j]);
                }
            }
            // ���nums[i]������m������nums[i-1]��С�ڵ���m��
            // ���i����m��˵��1..m-1������ǰm-1�����У�������
            // ���ҵ���Ӧ���������䣻������������
            if (i == m) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return static_cast<int>(l + 1);
    }
};
*/
