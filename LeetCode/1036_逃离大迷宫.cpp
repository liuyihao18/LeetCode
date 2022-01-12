// 1036_逃离大迷宫.cpp
#include "custom.h"
ustd

class Solution {
    struct Node {
        int x{ 0 };
        int y{ 0 };
        bool operator<(const Node& n) const {
            return x < n.x || x == n.x && y < n.y;
        }
        bool operator==(const Node& n) const {
            return x == n.x && y == n.y;
        }
    };
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        const int n = 1000000;
        set<Node> visited;
        for (const auto& point : blocked) {
            visited.insert({ point[0], point[1] });
        }
        Node n_target = { target[0], target[1] };
        stack<Node> s;
        s.push({ source[0], source[1] });
        while (!s.empty()) {
            Node curr = s.top();
            s.pop();
            if (curr == n_target) {
                return true;
            }
            if (curr.x < 0 || curr.x >= n || curr.y < 0 || curr.y >= n) {
                continue;
            }
            if (visited.find(curr) != visited.end()) {
                continue;
            }
            visited.insert(curr);
            s.push({ curr.x - 1, curr.y});
            s.push({ curr.x, curr.y - 1 });
            s.push({ curr.x + 1, curr.y});
            s.push({ curr.x, curr.y + 1});
        }
        return false;
    }
};
/*
class Solution {
private:
    // 在包围圈中
    static constexpr int BLOCKED = -1;
    // 不在包围圈中
    static constexpr int VALID = 0;
    // 无论在不在包围圈中，但在 n(n-1)/2 步搜索的过程中经过了 target
    static constexpr int FOUND = 1;

    static constexpr int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    static constexpr int BOUNDARY = 1000000;

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() < 2) {
            return true;
        }

        auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o)->size_t {
            auto& [x, y] = o;
            return fn((long long)x << 20 | y);
        };
        unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
        for (const auto& pos : blocked) {
            hash_blocked.emplace(pos[0], pos[1]);
        }

        auto check = [&](vector<int>& start, vector<int>& finish) -> int {
            int sx = start[0], sy = start[1];
            int fx = finish[0], fy = finish[1];
            int countdown = blocked.size() * (blocked.size() - 1) / 2;
            queue<pair<int, int>> q;
            q.emplace(sx, sy);
            unordered_set<pair<int, int>, decltype(hash_fn)> visited(0, hash_fn);
            visited.emplace(sx, sy);
            while (!q.empty() && countdown > 0) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if (nx >= 0 && nx < BOUNDARY && ny >= 0 && ny < BOUNDARY && !hash_blocked.count({ nx, ny }) && !visited.count({ nx, ny })) {
                        if (nx == fx && ny == fy) {
                            return FOUND;
                        }
                        --countdown;
                        q.emplace(nx, ny);
                        visited.emplace(nx, ny);
                    }
                }
            }
            if (countdown > 0) {
                return BLOCKED;
            }
            return VALID;
        };

        if (int result = check(source, target); result == FOUND) {
            return true;
        }
        else if (result == BLOCKED) {
            return false;
        }
        else {
            result = check(target, source);
            if (result == BLOCKED) {
                return false;
            }
            return true;
        }
    }
};
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/escape-a-large-maze/solution/tao-chi-da-mi-gong-by-leetcode-solution-qxhz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
