// 1719_�ع�һ�����ķ�����.cpp
#include "stdafx.h"
ustd

/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode-cn.com/problems/number-of-ways-to-reconstruct-a-tree/solution/zhong-gou-yi-ke-shu-de-fang-an-shu-by-le-36e1/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

// TODO: Exspecially Hard.

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& p : pairs) {
            adj[p[0]].emplace(p[1]);
            adj[p[1]].emplace(p[0]);
        }
        /* ����Ƿ���ڸ��ڵ�*/
        int root = -1;
        for (auto& [node, neighbours] : adj) {
            if (neighbours.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        if (root == -1) {
            return 0;
        }

        int res = 1;
        for (auto& [node, neighbours] : adj) {
            if (node == root) {
                continue;
            }
            int currDegree = static_cast<int>(neighbours.size());
            int parent = -1;
            int parentDegree = INT_MAX;

            /* ���� degree �Ĵ�С�ҵ� node �ĸ��ڵ� parent */
            for (auto& neighbour : neighbours) {
                if (adj[neighbour].size() < parentDegree && adj[neighbour].size() >= currDegree) {
                    parent = neighbour;
                    parentDegree = static_cast<int>(adj[neighbour].size());
                }
            }
            if (parent == -1) {
                return 0;
            }

            /* ��� neighbours �Ƿ��� adj[parent] ���Ӽ� */
            for (auto& neighbour : neighbours) {
                if (neighbour == parent) {
                    continue;
                }
                if (!adj[parent].count(neighbour)) {
                    return 0;
                }
            }
            if (parentDegree == currDegree) {
                res = 2;
            }
        }
        return res;
    }
};
