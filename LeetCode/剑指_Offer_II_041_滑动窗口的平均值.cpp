// 剑指_Offer_II_041_滑动窗口的平均值.cpp
#include "custom.h"
ustd

class MovingAverage {
    size_t size = 0;
    list<int> window;
    int last_sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size(size) {

    }

    double next(int val) {
        window.push_back(val);
        last_sum += val;
        if (window.size() > size) {
            last_sum -= window.front();
            window.pop_front();
        }        
        return last_sum * 1.0 / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
