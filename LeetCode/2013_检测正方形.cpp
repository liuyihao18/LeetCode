// 2013_检测正方形.cpp
#include "stdafx.h"
ustd

class DetectSquares {
    vector<vector<int>> points;
public:
    DetectSquares() : points(1001, vector<int>(1001, 0)) {
        
    }

    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int result = 0;
        int x = point[0], y = point[1];
        // 左上
        for (int i = 1; i <= 1000; i++) {
            int _x = x - i;
            if (_x < 0) {
                break;
            }
            int _y = y + i;
            if (_y > 1000) {
                break;
            }
            result += points[_x][y] * points[_x][_y] * points[x][_y];
        }
        // 左下
        for (int i = 1; i <= 1000; i++) {
            int _x = x - i;
            if (_x < 0) {
                break;
            }
            int _y = y - i;
            if (_y < 0) {
                break;
            }
            result += points[_x][y] * points[_x][_y] * points[x][_y];
        }
        // 右上
        for (int i = 1; i <= 1000; i++) {
            int _x = x + i;
            if (_x > 1000) {
                break;
            }
            int _y = y + i;
            if (_y > 1000) {
                break;
            }
            result += points[_x][y] * points[_x][_y] * points[x][_y];
        }
        // 右下
        for (int i = 1; i <= 1000; i++) {
            int _x = x + i;
            if (_x > 1000) {
                break;
            }
            int _y = y - i;
            if (_y < 0) {
                break;
            }
            result += points[_x][y] * points[_x][_y] * points[x][_y];
        }
        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
