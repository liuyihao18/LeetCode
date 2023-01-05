// 1803_ͳ�����ֵ�ڷ�Χ�ڵ������ж���.cpp
#include "custom.h"
ustd

struct Trie {
    // son[0] ��ʾ��������son[1] ��ʾ������
    array<Trie*, 2> son{ nullptr, nullptr };
    int sum;
    Trie() :sum(0) {}
};

class Solution {
private:
    // �ֵ����ĸ��ڵ�
    Trie* root = nullptr;
    // ���λ�Ķ�����λ���Ϊ 14
    static constexpr int HIGH_BIT = 14;

public:
    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; k--) {
            int bit = (num >> k) & 1;
            if (cur->son[bit] == nullptr) {
                cur->son[bit] = new Trie();
            }
            cur = cur->son[bit];
            cur->sum++;
        }
    }

    int get(int num, int x) {
        Trie* cur = root;
        int sum = 0;
        for (int k = HIGH_BIT; k >= 0; k--) {
            int r = (num >> k) & 1;
            if ((x >> k) & 1) {
                if (cur->son[r] != nullptr) {
                    sum += cur->son[r]->sum;
                }
                if (cur->son[r ^ 1] == nullptr) {
                    return sum;
                }
                cur = cur->son[r ^ 1];
            }
            else {
                if (cur->son[r] == nullptr) {
                    return sum;
                }
                cur = cur->son[r];
            }
        }
        sum += cur->sum;
        return sum;
    }

    int f(vector<int>& nums, int x) {
        root = new Trie();
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            add(nums[i - 1]);
            res += get(nums[i], x);
        }
        return res;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        return f(nums, high) - f(nums, low - 1);
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/count-pairs-with-xor-in-a-range/solutions/2044651/tong-ji-yi-huo-zhi-zai-fan-wei-nei-de-sh-cu18/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
