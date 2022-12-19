// 1971_寻找图中是否存在路径.cpp
#include "custom.h"
ustd

class Solution {
private:
    bool dfs(int source, int destination, vector<vector<int>>& links, vector<bool>& visited) {
        if (source == destination) {
            return true;
        }
        if (visited[source]) {
            return false;
        }
        visited[source] = true;
        for (auto v : links[source]) {
            if (dfs(v, destination, links, visited)) {
                return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> links(n);
        for (const auto& edge : edges) {
            links[edge[0]].push_back(edge[1]);
            links[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, links, visited);
    }
};
