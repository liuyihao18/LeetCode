// 3532_针对图的路径存在性查询_I.cpp
#include "stdafx.h"
ustd

struct Dsu
{
	vector<int> pa, size;

	explicit Dsu(const int size) : pa(size), size(size, 1) {
		iota(pa.begin(), pa.end(), 0);
	}

	int find(const int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (size[x] < size[y]) swap(x, y);
		pa[y] = x;
		size[x] += size[y];
	}
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
		Dsu dsu(n);
		for (int i = 0; i + 1 < n; i++) {
			if (abs(nums[i] - nums[i + 1ull]) <= maxDiff) {
				dsu.unite(i, i + 1);
			}
		}
		vector<bool> results;
		for (const vector<int>& query : queries) {
			const int u = query[0], v = query[1];
			if (dsu.find(u) == dsu.find(v)) {
				results.push_back(true);
			}
			else {
				results.push_back(false);
			}
		}
		return results;
    }
};
