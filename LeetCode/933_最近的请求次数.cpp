// 933_最近的请求次数.cpp
#include "stdafx.h"
ustd

class RecentCounter {
    queue<int> request;
public:
    RecentCounter() {

    }

    int ping(int t) {
        request.push(t);
        while (request.front() < t - 3000) {
            request.pop();
        }
        return static_cast<int>(request.size());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
