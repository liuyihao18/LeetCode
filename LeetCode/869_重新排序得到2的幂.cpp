// 869_重新排序得到2的幂.cpp
#include "custom.h"
ustd

class Solution {
#ifdef DFS
    bool isPowerOf2(int n) {
        return (n & (n - 1)) == 0;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nums;
        while (n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        vector<bool> visited(nums.size(), false);
        cout << nums.size() << endl;
        return _dfs(nums, visited, 0);
    }
    bool _dfs(const vector<int>& nums, vector<bool>& visited, int n) {
        if (count(visited.begin(), visited.end(), true) == visited.size()) {
            return isPowerOf2(n);
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            else {
                if (n == 0 && nums[i] == 0) {
                    continue;
                }
                int temp_n = 10 * n + nums[i];
                visited[i] = true;
                if (_dfs(nums, visited, temp_n)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
#else
    set<map<char, size_t>> result;
public:
    bool reorderedPowerOf2(int n) {
        for (size_t i = 1; i <= 0x40000000; i <<= 1) {
            string i2s = to_string(i);
            map<char, size_t> temp;
            for (auto c : i2s) {
                temp[c]++;
            }
            result.insert(temp);
        }
        string n2s = to_string(n);
        map<char, size_t> temp;
        for (auto c : n2s) {
            temp[c]++;
        }
        return result.find(temp) != result.end();
    }
#endif
};
