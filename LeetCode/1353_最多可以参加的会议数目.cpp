// 1353_最多可以参加的会议数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        size_t n = events.size();
        sort(events.begin(), events.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
			}
        );
		priority_queue<int, vector<int>, greater<int>> pq;
        int result = 0;
        size_t index = 0;
        for (int i = 1; i <= 100000; i++) {
            while (index < n && events[index][0] <= i) {
                pq.push(events[index][1]);
                index++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty() && pq.top() >= i) {
                pq.pop();
                result++;
            }
        }
        return result;
    }
};
