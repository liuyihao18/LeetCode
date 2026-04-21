// 1722_执行交换操作后的最小汉明距离.cpp
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
	int minimumHammingDistance(const vector<int>& source,
	                           const vector<int>& target,
	                           const vector<vector<int>>& allowedSwaps)
	{
		const int n = static_cast<int>(source.size());
		Dsu dsu(n);
		for (const vector<int>& allowedSwap : allowedSwaps)
		{
			dsu.unite(allowedSwap[0], allowedSwap[1]);
		}
		unordered_map<int, unordered_map<int, int>> um;
		for (int i = 0; i < n; i++)
		{
			um[dsu.find(i)][source[i]]++;
			um[dsu.find(i)][target[i]]--;
		}
		int hammingDistance = 0;
		for (const auto& _um : um | views::values)
		{
			for (const auto& v : _um | views::values)
			{
				if (v > 0)
				{
					hammingDistance += v;
				}
			}
		}
		return hammingDistance;
	}
};
