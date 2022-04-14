// 380_O(1) 时间插入、删除和获取随机元素.cpp
#include "custom.h"
ustd

class RandomizedSet {
    unordered_map<int, size_t> um;
    vector<int> v;
public:
    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (!um.count(val)) {
            um[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (um.count(val)) {
            um[v.back()] = um[val];
            swap(v.back(), v[um[val]]);
            um.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
