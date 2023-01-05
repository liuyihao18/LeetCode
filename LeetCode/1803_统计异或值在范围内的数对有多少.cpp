// 1803_统计异或值在范围内的数对有多少.cpp
#include "custom.h"
ustd

struct Trie {
    // son[0] 表示左子树，son[1] 表示右子树
    array<Trie*, 2> son{ nullptr, nullptr };
    int sum;
    Trie() :sum(0) {}
};

class Solution {
private:
    // 字典树的根节点
    Trie* root = nullptr;
    // 最高位的二进制位编号为 14
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
作者：力扣官方题解
链接：https ://leetcode.cn/problems/count-pairs-with-xor-in-a-range/solutions/2044651/tong-ji-yi-huo-zhi-zai-fan-wei-nei-de-sh-cu18/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
