// 630_¿Î³Ì±í_III.cpp
#include "custom.h"
ustd

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() < v2.back();
            });
        int sum = 0;
        priority_queue<int, vector<int>> pq;
        for (const auto& course : courses) {
            sum += course.front();
            pq.push(course.front());
            if (sum > course.back()) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return static_cast<int>(pq.size());
    }
};
