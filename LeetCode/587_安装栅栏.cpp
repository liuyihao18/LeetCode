// 587_��װդ��.cpp
#include "custom.h"
ustd

// ͹����⣺Andrew�㷨
// ���������������ֶ���
class Solution {
public:
    int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = static_cast<int>(trees.size());
        if (n < 4) {
            return trees;
        }
        /* ���� x ��С����������� x ��ͬ������ y �Ĵ�С�������� */
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
            });
        vector<int> hull;
        vector<bool> used(n, false);
        /* hull[0] ��Ҫ��ջ���Σ������б�� */
        hull.emplace_back(0);
        /* ���͹�����°벿�� */
        for (int i = 1; i < n; i++) {
            while (hull.size() > 1 && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                used[hull.back()] = false;
                hull.pop_back();
            }
            used[i] = true;
            hull.emplace_back(i);
        }
        int m = static_cast<int>(hull.size());
        /* ���͹�����ϰ벿�� */
        for (int i = n - 2; i >= 0; i--) {
            if (!used[i]) {
                while (hull.size() > m && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                    used[hull.back()] = false;
                    hull.pop_back();
                }
                used[i] = true;
                hull.emplace_back(i);
            }
        }
        /* hull[0] ͬʱ����͹�����ϰ벿�ּ�⣬�����ȥ���ظ��� hull[0] */
        hull.pop_back();
        vector<vector<int>> res;
        for (auto& v : hull) {
            res.emplace_back(trees[v]);
        }
        return res;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode-cn.com/problems/erect-the-fence/solution/an-zhuang-zha-lan-by-leetcode-solution-75s3/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
