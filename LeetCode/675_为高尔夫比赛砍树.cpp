// 675_为高尔夫比赛砍树.cpp
#include "custom.h"
ustd

class Solution {
    const int dir[4][2] = {
        {0,  1},
        {0, -1},
        {-1, 0},
        {1,  0} };
    struct Position {
        int x;
        int y;
        Position(int x, int y) : x(x), y(y) {}
        bool operator<(const Position& pos) const {
            return x < pos.x || (x == pos.x && y < pos.y);
        };
        bool operator==(const Position& pos) const {
            return x == pos.x && y == pos.y;
        }
        bool operator!=(const Position& pos) const {
            return !operator==(pos);
        }
    };
    struct Tree {
        Position pos;
        int height;
        Tree(int x, int y, int height) : pos(x, y), height(height) {}
        bool operator<(const Tree& t) const {
            return height > t.height;
        };
    };
    struct Node {
        Position pos;
        int pathLen;
        Node(const Position& pos, int pathLen) :pos(pos), pathLen(pathLen) {}
    };
    int bfs(const Position& src, const Position& dst, const vector<vector<int>>& forest) {
        int m = static_cast<int>(forest.size());
        int n = static_cast<int>(forest.front().size());
        queue<Node> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // O(1)的矩阵比O(log(n))的集合快得多
        q.emplace(src, 0);
        visited[src.x][src.y] = true;
        while (!q.empty()) {
            Node curr = q.front();
            q.pop();
            Position pos = curr.pos;
            if (pos == dst) {
                return curr.pathLen;
            }
            for (int i = 0; i < 4; i++) {
                Position newPos = pos;
                newPos.x += dir[i][0];
                newPos.y += dir[i][1];
                if (newPos.x >= 0 && newPos.x < m && newPos.y >= 0 && newPos.y < n
                    && forest[newPos.x][newPos.y] > 0) {
                    if (!visited[newPos.x][newPos.y]) {
                        visited[newPos.x][newPos.y] = true;
                        q.emplace(newPos, curr.pathLen + 1);
                    }
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<Tree> trees;
        int m = static_cast<int>(forest.size());
        int n = static_cast<int>(forest.front().size());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.emplace(i, j, forest[i][j]);
                }
            }
        }
        Position src(0, 0);
        int result = 0;
        while (!trees.empty()) {
            Tree tree = trees.top();
            trees.pop();
            Position dst = tree.pos;
            if (dst != src) {
                int pathLen = bfs(src, dst, forest);
                if (pathLen < 0) {
                    return -1;
                }
                result += pathLen;
            }
            forest[dst.x][dst.y] = 1;
            src = dst;
        }
        return result;
    }
};
