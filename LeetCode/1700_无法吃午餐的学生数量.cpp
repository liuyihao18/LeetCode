// 1700_无法吃午餐的学生数量.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (auto student : students) {
            q.push(student);
        }
        for (auto sandwich : sandwiches) {
            bool found = false;
            for (size_t i = 0; i < q.size(); i++) {
                if (q.front() == sandwich) {
                    found = true;
                }
                else {
                    q.push(q.front());
                    q.pop();
                }
            }
            if (found) {
                q.pop();
            }
            else {
                break;
            }
        }
        return static_cast<int>(q.size());
    }
};
