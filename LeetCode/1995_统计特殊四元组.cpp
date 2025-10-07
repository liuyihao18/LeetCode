// 1995_统计特殊四元组.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Quadruplet {
        size_t a;
        size_t b;
        size_t c;
        size_t d;
        void print() const {
            cout << "(" << a << ", " << b << ", " << c << ", " << d << ")" << endl;
        }
    };
    struct QHash {
        size_t operator()(const Quadruplet& q) const {
            return hash<size_t>()(q.a) << 24
                | hash<size_t>()(q.b) << 16
                | hash<size_t>()(q.c) << 8
                | hash<size_t>()(q.d);
        }
    };
    struct QEqual {
        size_t operator()(const Quadruplet& q1, const Quadruplet& q2) const {
            return q1.a == q2.a && q1.b == q2.b && q1.c == q2.c && q1.d == q2.d;
        }
    };
    unordered_set<Quadruplet, QHash, QEqual> us;
    void find(const vector<int>& nums, Quadruplet q) {
        if (us.find(q) != us.end()) {
            return;
        }
        int temp = nums[q.a] + nums[q.b] + nums[q.c];
        if (temp == nums[q.d]) {
            us.insert(q);
        }
        if (q.a + 1 < q.b) {
            Quadruplet temp_q = q;
            temp_q.a++;
            find(nums, temp_q);
        }
        if (q.b + 1 < q.c) {
            Quadruplet temp_q = q;
            temp_q.b++;
            find(nums, temp_q);
        }
        if (q.c + 1 < q.d) {
            Quadruplet temp_q = q;
            temp_q.c++;
            find(nums, temp_q);
        }
        if (q.d + 1 < nums.size()) {
            Quadruplet temp_q = q;
            temp_q.d++;
            find(nums, temp_q);
        }
    }
public:
    int countQuadruplets(vector<int>& nums) {
        if (nums.size() < 4) {
            return 0;
        }
        /*
        Quadruplet q = { 0,1,2,3 };
        find(nums, q);
        return static_cast<int>(us.size());
        */
        int result = 0;
        for (size_t d = 3; d < nums.size(); d++) {
            for (size_t c = 2; c < d; c++) {
                for (size_t b = 1; b < c; b++) {
                    for (size_t a = 0; a < b; a++) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};
