// 1656_设计有序流.cpp
#include "stdafx.h"
ustd

class OrderedStream {
    vector<string> v;
    int capacity;
    int ptr;
public:
    OrderedStream(int n) : v(n, ""), capacity(n), ptr(0) {

    }

    vector<string> insert(int idKey, string value) {
        v[static_cast<size_t>(idKey) - 1] = value;
        vector<string> result;
        while (ptr < capacity && v[ptr] != "") {
            result.push_back(v[ptr]);
            ++ptr;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
