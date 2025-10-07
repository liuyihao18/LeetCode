// 1697_检查边长度限制的路径是否存在.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int find(vector<int>& uf, int x) {
        if (uf[x] == x) {
            return x;
        }
        return uf[x] = find(uf, uf[x]);
    }

    void merge(vector<int>& uf, int x, int y) {
        x = find(uf, x);
        y = find(uf, y);
        uf[y] = x;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& e1, vector<int>& e2) {
            return e1[2] < e2[2];
            });

        vector<int> index(queries.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int i1, int i2) {
            return queries[i1][2] < queries[i2][2];
            });

        vector<int> uf(n);
        iota(uf.begin(), uf.end(), 0);
        vector<bool> res(queries.size());
        int k = 0;
        for (auto i : index) {
            while (k < edgeList.size() && edgeList[k][2] < queries[i][2]) {
                merge(uf, edgeList[k][0], edgeList[k][1]);
                k++;
            }
            res[i] = find(uf, queries[i][0]) == find(uf, queries[i][1]);
        }
        return res;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/solutions/2018397/jian-cha-bian-chang-du-xian-zhi-de-lu-ji-cdr5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
