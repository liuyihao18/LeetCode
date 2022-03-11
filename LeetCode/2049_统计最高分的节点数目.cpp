// 2049_统计最高分的节点数目.cpp
#include "custom.h"
ustd

class Solution {
    void dfs(int root, const vector<pair<int, int>>& children, vector<int>& counts) {
        if (root != -1) {
            dfs(children[root].first, children, counts);
            dfs(children[root].second, children, counts);
            int firstChildCounts = 0;
            if (children[root].first != -1) {
                firstChildCounts = counts[children[root].first];
            }
            int secondChildCounts = 0;
            if (children[root].second != -1) {
                secondChildCounts = counts[children[root].second];
            }
            counts[root] = firstChildCounts + secondChildCounts + 1;
        }
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        vector<pair<int, int>> children(parents.size(), { -1,-1 });
        int n = static_cast<int>(parents.size());
        for (int i = 0; i < n; i++) {
            int parent = parents[i];
            if (parent != -1) {
                if (children[parents[i]].first == -1) {
                    children[parents[i]].first = i;
                }
                else {
                    children[parents[i]].second = i;
                }
            }
        }
        vector<int> counts(parents.size(), 0);
        dfs(0, children, counts);
        long long maxScore = 0;
        int maxNums = 0;
        for (int i = 0; i < n; i++) {
            long long score = 1;
            int parent = parents[i];
            if (parent != -1) {
                score *= static_cast<long long>(counts[0]) - counts[i];
            }
            int firstChild = children[i].first;
            if (firstChild != -1) {
                score *= counts[firstChild];
            }
            int secondChild = children[i].second;
            if (secondChild != -1) {
                score *= counts[secondChild];
            }
            if (score > maxScore) {
                maxScore = score;
                maxNums = 1;
            }
            else if (score == maxScore) {
                maxNums++;
            }
        }
        return maxNums;
    }
};
