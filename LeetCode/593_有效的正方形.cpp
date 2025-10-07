// 593_有效的正方形.cpp
#include "stdafx.h"
ustd

class Solution {
    int len(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2) return false;
        vector<int> l;
        l.push_back(len(p1, p2));
        l.push_back(len(p1, p3));
        l.push_back(len(p1, p4));
        l.push_back(len(p2, p3));
        l.push_back(len(p2, p4));
        l.push_back(len(p3, p4));
        sort(l.begin(), l.end());
        return l[0] == l[1] && l[1] == l[2] && l[2] == l[3] && l[4] == l[5];
    }
};
