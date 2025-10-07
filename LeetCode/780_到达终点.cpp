// 780_�����յ�.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            if (curr.first == tx && curr.second == ty) {
                return true;
            }
            if (curr.first > tx || curr.second > ty || visited.count(curr)) {
                continue;
            }
            visited.insert(curr);
            q.emplace(curr.first + curr.second, curr.second);
            q.emplace(curr.first, curr.first + curr.second);
        }
        return false;
    }
};

/*
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            }
            else {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy) {
            return true;
        }
        else if (tx == sx) {
            return ty > sy && (ty - sy) % tx == 0;
        }
        else if (ty == sy) {
            return tx > sx && (tx - sx) % ty == 0;
        }
        else {
            return false;
        }
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode-cn.com/problems/reaching-points/solution/dao-da-zhong-dian-by-leetcode-solution-77fo/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/