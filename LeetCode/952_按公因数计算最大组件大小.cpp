// 952_按公因数计算最大组件大小.cpp
#include "stdafx.h"
ustd

// ? TLE
class Solution {
    int gcd(int m, int n) {
        while (n > 0) {
            int r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
    int bfs(size_t i, const vector<vector<size_t>>& graph, vector<bool> visited) {
        queue<size_t> q;
        q.push(i);
        int size = 0;
        while (!q.empty()) {
            size_t curr = q.front();
            q.pop();
            if (visited[curr]) {
                continue;
            }
            size++;
            visited[curr] = true;
            for (auto j : graph[curr]) {
                q.push(j);
            }
        }
        return size;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        size_t n = nums.size();
        vector<vector<size_t>> graph(n);
        for (size_t i = 0; i + 1 < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                if (gcd(nums[i], nums[j]) > 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int maxSize = 0;
        vector<bool> visited(n, false);
        for (size_t i = 0; i < n; i++) {
            if (!visited[i]) {
                maxSize = max(maxSize, bfs(i, graph, visited));
            }
        }
        return maxSize;
    }
};

/*
class UnionFind {
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            }
            else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            }
            else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
private:
    vector<int> parent;
    vector<int> rank;
};

/*
class UnionFind {
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind uf(m + 1);
        for (int num : nums) {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    uf.uni(num, i);
                    uf.uni(num, num / i);
                }
            }
        }
        vector<int> counts(m + 1);
        int ans = 0;
        for (int num : nums) {
            int root = uf.find(num);
            counts[root]++;
            ans = max(ans, counts[root]);
        }
        return ans;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/largest-component-size-by-common-factor/solution/an-gong-yin-shu-ji-suan-zui-da-zu-jian-d-amdx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
