// 488_祖玛游戏.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    void squeeze(string& board) {
        if (board.size() < 3) {
            return;
        }
        bool canSqueeze = true;
        while (canSqueeze) {
            canSqueeze = false;
            for (size_t i = 1; i < board.size() - 1; i++) {
                if (board[i - 1] == board[i] && board[i] == board[i + 1]) {
                    size_t count = 3;
                    for (size_t j = i + 2; j < board.size(); j++) {
                        if (board[j] == board[i]) {
                            count++;
                        }
                        else {
                            break;
                        }
                    }
                    board.erase(i - 1, count);
                    if (board.size() >= 3) {
                        canSqueeze = true;
                    }
                    break;
                }
            }
        }
    }
    int findMinStep(string board, string hand) {
        struct Node {
            string board;
            string hand;
            size_t op_count;
            bool operator<(const Node& n) const {
                return board < n.board
                    || board == n.board && hand < n.hand
                    || board == n.board && hand == n.hand && op_count < n.op_count;
            }
        };
        struct NodeCmp {
            bool operator()(const Node& n1, const Node& n2) {
                return (n2.op_count + (3 - n2.board.size() % 3)) - (n1.op_count + (3 - n1.board.size() % 3));
            }
        };
        priority_queue<Node, vector<Node>, NodeCmp> q;
        q.push({ board, hand, 0 });
        set<Node> visited;
        size_t min_count = -1;
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            if (visited.find(node) != visited.end()) {
                continue;
            }
            visited.insert(node);
            string board = node.board;
            string hand = node.hand;
            size_t op_count = node.op_count;
            if (board.empty()) {
                min_count = min(min_count, op_count);
                continue;
            }
            if (op_count >= min_count) {
                continue;
            }
            if (board.size() + hand.size() < 3) {
                continue;
            }
            for (size_t i = 0; i < board.size(); i++) {
                for (size_t j = 0; j < hand.size(); j++) {
                    string board_copy = board.substr(0, i) + hand[j] + board.substr(i);
                    squeeze(board_copy);
                    string hand_copy = hand.substr(0, j) + hand.substr(j + 1);
                    q.push({ board_copy, hand_copy, op_count + 1 });
                }
            }
        }
        return static_cast<int>(min_count);
    }
};

/*
class Solution {
    int ans, used;
    unordered_map<char, int> rem;
    stack<pair<char, int>> st;

    void dfs(int pos, string& board) {
        if (used >= ans)
            return;

        if (pos == board.size()) {
            if (st.empty())
                ans = used;
            return;
        }

        if (!st.empty() && st.top().first == board[pos]) {
            st.top().second++;
        }
        else {
            st.emplace(board[pos], 1);
        }

        if (st.top().second >= 3) {
            if (pos + 1 == board.size() || board[pos + 1] != board[pos]) {
                // 后面没有相同颜色的球，可以直接消去
                auto tmp = st.top();
                st.pop();
                dfs(pos + 1, board);
                st.push(tmp);
            }
            else {
                // 后面有相同颜色的球，必须插入与当前位置不同色的小球进行分隔
                for (auto [ch, num] : rem) {
                    if (ch == board[pos])
                        continue;
                    for (int j = 1; j <= min(3, num); ++j) {
                        rem[ch] -= j;
                        used += j;
                        auto tmp = st.top();
                        st.pop();
                        if (!st.empty() && st.top().first == ch) {
                            st.top().second += j;
                        }
                        else {
                            st.emplace(ch, j);
                        }
                        if (st.top().second >= 3) {
                            auto tmp2 = st.top();
                            st.pop();
                            dfs(pos + 1, board);
                            st.push(tmp2);
                        }
                        else {
                            dfs(pos + 1, board);
                        }
                        if (st.top().second > j) {
                            st.top().second -= j;
                        }
                        else {
                            st.pop();
                        }
                        st.push(tmp);
                        used -= j;
                        rem[ch] += j;
                    }
                }
            }
        }

        // 插入与当前位置同色的小球
        if (rem[board[pos]] >= 1 && (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
            int lim = rem[board[pos]];
            for (int i = 1; i <= min(2, lim); ++i) {
                rem[board[pos]] -= i;
                used += i;
                st.top().second += i;
                if (st.top().second >= 3) {
                    auto tmp = st.top();
                    st.pop();
                    dfs(pos + 1, board);
                    st.push(tmp);
                }
                else {
                    dfs(pos + 1, board);
                }
                st.top().second -= i;
                used -= i;
                rem[board[pos]] += i;
            }
        }

        if (st.top().second < 3 || (st.top().second == 3 && pos + 1 < board.size() && board[pos] == board[pos + 1]))
            dfs(pos + 1, board);

        if (st.top().second == 1) {
            st.pop();
        }
        else {
            st.top().second--;
        }
    }
public:
    int findMinStep(string board, string hand) {
        for (char ch : hand)
            rem[ch]++;

        ans = 1e9;
        used = 0;
        dfs(0, board);
        return ans == 1e9 ? -1 : ans;
    }
};
*/
