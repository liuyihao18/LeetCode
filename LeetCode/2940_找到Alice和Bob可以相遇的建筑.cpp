// 2940_找到Alice和Bob可以相遇的建筑.cpp
#include "custom.h"
ustd

// 错的，找到的不是最近的楼，而是最矮的楼
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        map<int, vector<int>> m;
        for (int i = 0; i < heights.size(); i++) {
            m[heights[i]].push_back(i);
        }
        vector<int> ans;
        for (const auto& query : queries) {
            int i = query[0];
            int j = query[1];
            int a = heights[i];
            int b = heights[j];
            auto iter = m.lower_bound(max(a, b));
            bool found = false;
            while (!found && iter != m.end()) {
                for (int k : iter->second) {
                    if (k >= i && k >= j) {
                        found = true;
                        ans.push_back(k);
                    }
                }
                ++iter;
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> zd;

    void build(int l, int r, int rt, vector<int>& heights) {
        if (l == r) {
            zd[rt] = heights[l - 1];
            return;
        }

        int mid = (l + r) >> 1;
        build(l, mid, rt << 1, heights);
        build(mid + 1, r, rt << 1 | 1, heights);
        zd[rt] = max(zd[rt << 1], zd[rt << 1 | 1]);
    }

    int query(int pos, int val, int l, int r, int rt) {
        if (val >= zd[rt]) {
            return 0;
        }

        if (l == r) {
            return l;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) {
            int res = query(pos, val, l, mid, rt << 1);
            if (res != 0) {
                return res;
            }
        }
        return query(pos, val, mid + 1, r, rt << 1 | 1);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        zd.resize(n * 4);
        build(1, n, 1, heights);

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }

            if (a == b || heights[a] < heights[b]) {
                ans[i] = b;
                continue;
            }

            ans[i] = query(b + 1, heights[a], 1, n, 1) - 1;
        }
        return ans;
    }
};
*/
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet/solutions/2872957/zhao-dao-alice-he-bob-ke-yi-xiang-yu-de-x5i0t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
