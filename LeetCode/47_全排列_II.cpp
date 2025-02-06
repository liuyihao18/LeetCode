// 47_È«ÅÅÁÐ_II.cpp
#include "custom.h"
ustd

class Solution {
    void dfs(const vector<int>& nums, size_t n, vector<int>& path, vector<bool>& visited, vector<vector<int>>& results) {
        if (n == nums.size()) {
            results.push_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, n + 1, path, visited, results);
            path.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        vector<vector<int>> results;
        dfs(nums, 0, path, visited, results);
        return results;
    }
};
