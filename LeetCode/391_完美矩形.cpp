// 391_完美矩形.cpp
#include "custom.h"
ustd
#define HASH

class Solution {
    const size_t x1 = 0;
    const size_t y1 = 1;
    const size_t x2 = 2;
    const size_t y2 = 3;
public:
#ifndef HASH
    bool cross(const vector<int>& rect1, const vector<int>& rect2) {
        long long both_x = static_cast<long long>(min(rect1[x2], rect2[x2])) - max(rect1[x1], rect2[x1]); // 重叠部分在x轴的投影
        long long both_y = static_cast<long long>(min(rect1[y2], rect2[y2])) - max(rect1[y1], rect2[y1]); // 重叠部分在y轴的投影
        long long both_area = max(both_x, 0LL) * max(both_y, 0LL);
        return both_area > 0;
    }
#else
    using Point = pair<int, int>;
    struct PointHash {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.first) << 10 | hash<int>()(p.second);
        }
    };
#endif // !HASH
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int min_x = INT_MAX;
        int max_x = INT_MIN;
        int min_y = INT_MAX;
        int max_y = INT_MIN;
        long long sum_area = 0;
#ifdef HASH
        unordered_map<Point, size_t, PointHash> cnt;
#endif // HASH
        for (size_t i = 0; i < rectangles.size(); i++) {
#ifndef HASH
            for (size_t j = 0; j < i; j++) {
                if (cross(rectangles[i], rectangles[j])) {
                    return false;
                }
            }
#else
            Point p1 = { rectangles[i][x1], rectangles[i][y1] };
            Point p2 = { rectangles[i][x1], rectangles[i][y2] };
            Point p3 = { rectangles[i][x2], rectangles[i][y1] };
            Point p4 = { rectangles[i][x2], rectangles[i][y2] };
            cnt[p1]++;
            cnt[p2]++;
            cnt[p3]++;
            cnt[p4]++;
#endif // !HASH
            min_x = min(min_x, rectangles[i][x1]);
            max_x = max(max_x, rectangles[i][x2]);
            min_y = min(min_y, rectangles[i][y1]);
            max_y = max(max_y, rectangles[i][y2]);
            sum_area += (static_cast<long long>(rectangles[i][x2]) - rectangles[i][x1]) * (static_cast<long long>(rectangles[i][y2]) - rectangles[i][y1]);
        }
#ifdef HASH
        Point p1 = { min_x, min_y };
        Point p2 = { min_x, max_y };
        Point p3 = { max_x, min_y };
        Point p4 = { max_x, max_y };
        cnt[p1]--;
        cnt[p2]--;
        cnt[p3]--;
        cnt[p4]--;
        for (const auto& entry : cnt) {
            if (entry.second != 0 && entry.second != 2 && entry.second != 4) {
                return false;
            }
        }
#endif // HASH
        return sum_area == (static_cast<long long>(max_x) - min_x) * (static_cast<long long>(max_y) - min_y);
    }
};
