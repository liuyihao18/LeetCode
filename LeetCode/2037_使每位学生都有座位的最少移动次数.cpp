// 2037_使每位学生都有座位的最少移动次数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int result = 0;
        for (size_t i = 0; i < seats.size(); i++) {
            result += abs(students[i] - seats[i]);
        }
        return result;
    }
};
