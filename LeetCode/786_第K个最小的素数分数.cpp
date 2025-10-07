// 786_第K个最小的素数分数.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Node {
        int arr_i;
        int arr_j;
        bool operator<(const Node& n) const {
            return arr_i * n.arr_j < n.arr_i * arr_j;
        }
    };
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        set<Node> nodes;
        for (size_t i = 0; i < arr.size() - 1; i++) {
            for (size_t j = i + 1; j < arr.size(); j++) {
                nodes.insert({ arr[i], arr[j] });
            }
        }
        auto iter = nodes.begin();
        for (size_t i = 1; i < static_cast<size_t>(k); i++, ++iter);
        return { iter->arr_i, iter->arr_j };
    }
};
