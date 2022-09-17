// 850_�������_II.cpp
#include "custom.h"
ustd

struct Segtree {
    int cover;
    int length;
    int max_length;
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = static_cast<int>(rectangles.size());
        for (const auto& rect : rectangles) {
            // �±߽�
            hbound.push_back(rect[1]);
            // �ϱ߽�
            hbound.push_back(rect[3]);
        }
        sort(hbound.begin(), hbound.end());
        hbound.erase(unique(hbound.begin(), hbound.end()), hbound.end());
        int m = static_cast<int>(hbound.size());
        // �߶����� m-1 ��Ҷ�ӽڵ㣬��Ӧ�� m-1 ���ᱻ�������ǵ��߶Σ���Ҫ���� ~4m ��С�Ŀռ�
        tree.resize(m * 4LL + 1);
        init(1, 1, m - 1);

        vector<tuple<int, int, int>> sweep;
        for (int i = 0; i < n; ++i) {
            // ��߽�
            sweep.emplace_back(rectangles[i][0], i, 1);
            // �ұ߽�
            sweep.emplace_back(rectangles[i][2], i, -1);
        }
        sort(sweep.begin(), sweep.end());

        long long ans = 0;
        for (int i = 0; i < sweep.size(); ++i) {
            int j = i;
            while (static_cast<size_t>(j + 1) < sweep.size() && get<0>(sweep[i]) == get<0>(sweep[j + 1LL])) {
                ++j;
            }
            if (j + 1LL == sweep.size()) {
                break;
            }
            // һ���Եش����һ����������ͬ�����ұ߽�
            for (int k = i; k <= j; ++k) {
                auto&& [_, idx, diff] = sweep[k];
                // ʹ�ö��ֲ��ҵõ��������ǵ��߶εı�ŷ�Χ
                int left = static_cast<int>(lower_bound(hbound.begin(), hbound.end(), rectangles[idx][1]) - hbound.begin() + 1);
                int right = static_cast<int>(lower_bound(hbound.begin(), hbound.end(), rectangles[idx][3]) - hbound.begin());
                update(1, 1, m - 1, left, right, diff);
            }
            ans += static_cast<long long>(tree[1].length) * (get<0>(sweep[j + 1]) * 1LL - get<0>(sweep[j]));
            i = j;
        }
        return static_cast<int>(ans % static_cast<long long>(1e9 + 7));
    }

    void init(int idx, int l, int r) {
        tree[idx].cover = tree[idx].length = 0;
        if (l == r) {
            tree[idx].max_length = hbound[l] - hbound[l - 1LL];
            return;
        }
        int mid = (l + r) / 2;
        init(idx * 2, l, mid);
        init(idx * 2 + 1, mid + 1, r);
        tree[idx].max_length = tree[idx * 2LL].max_length + tree[idx * 2LL + 1].max_length;
    }

    void update(int idx, int l, int r, int ul, int ur, int diff) {
        if (l > ur || r < ul) {
            return;
        }
        if (ul <= l && r <= ur) {
            tree[idx].cover += diff;
            pushup(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ul, ur, diff);
        update(idx * 2 + 1, mid + 1, r, ul, ur, diff);
        pushup(idx, l, r);
    }

    void pushup(int idx, int l, int r) {
        if (tree[idx].cover > 0) {
            tree[idx].length = tree[idx].max_length;
        }
        else if (l == r) {
            tree[idx].length = 0;
        }
        else {
            tree[idx].length = tree[idx * 2LL].length + tree[idx * 2LL + 1].length;
        }
    }

private:
    vector<Segtree> tree;
    vector<int> hbound;
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/rectangle-area-ii/solution/ju-xing-mian-ji-ii-by-leetcode-solution-ulqz/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
