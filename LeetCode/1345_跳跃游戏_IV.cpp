// 1345_Ã¯‘æ”Œœ∑_IV.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Node {
        size_t idx;
        size_t ops;
    };
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<size_t>> num_list;
        map<int, bool> num_visited;
        for (size_t i = 0; i < arr.size(); i++) {
            num_list[arr[i]].push_back(i);
            num_visited[arr[i]] = false;
        }
        vector<bool> visited(arr.size(), false);
        queue<Node> q;
        q.push({ 0, 0 });
        while (!q.empty()) {
            Node curr = q.front();
            q.pop();
            if (visited[curr.idx]) {
                continue;
            }
            visited[curr.idx] = true;
            if (curr.idx + 1 == arr.size()) {
                return static_cast<int>(curr.ops);
            }
            q.push({ curr.idx + 1, curr.ops + 1 });
            if (curr.idx > 0) {
                q.push({ curr.idx - 1,curr.ops + 1 });
            }
            if (!num_visited[arr[curr.idx]]) {
                for (auto idx : num_list[arr[curr.idx]]) {
                    q.push({ idx, curr.ops + 1 });
                }
                num_visited[arr[curr.idx]] = true;
            }
        }
        return -1;
    }
};

