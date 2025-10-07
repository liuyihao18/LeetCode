// 432_全O(1)的数据结构.cpp
#include "stdafx.h"
ustd

class AllOne {
    unordered_map<string, size_t> s;
    size_t maxCount{ 0 };
    size_t minCount{ SIZE_MAX };
    unordered_set<string> maxKey;
    unordered_set<string> minKey;
    void print() {
        cout << "------ s -----" << endl;
        for (const auto& key : s) {
            cout << key.first << ": " << key.second << endl;
        }
        cout << "------ k -----" << endl;
        cout << "maxCount: " << maxCount << endl;
        for (const auto& k : maxKey) {
            cout << k << " ";
        }
        cout << endl;
        cout << "minCount: " << minCount << endl;
        for (const auto& k : minKey) {
            cout << k << " ";
        }
        cout << endl;
    }
    void makeMinKey() {
        minCount = SIZE_MAX;
        for (pair<string, size_t> p : s) {
            if (p.second < minCount) {
                minKey.clear();
                minCount = p.second;
                minKey.insert(p.first);
            }
            else if (p.second == minCount) {
                minKey.insert(p.first);
            }
        }
    }
    void makeMaxKey() {
        maxCount = 0;
        for (pair<string, size_t> p : s) {
            if (p.second > maxCount) {
                maxKey.clear();
                maxCount = p.second;
                maxKey.insert(p.first);
            }
            else if (p.second == maxCount) {
                maxKey.insert(p.first);
            }
        }
    }
public:
    AllOne() {

    }

    void inc(string key) {
        size_t count = ++s[key];
        // 如果数量大于最大数量，则清空原有
        if (count > maxCount) {
            maxCount = count;
            maxKey.clear();
            maxKey.insert(key);
        }
        // 相等则加入
        else if (count == maxCount) {
            maxKey.insert(key);
        }
        // 如果数量小于最小数量，则清空原有
        if (count < minCount) {
            minCount = count;
            minKey.clear();
            minKey.insert(key);
        }
        // 相等则加入
        else if (count == minCount) {
            minKey.insert(key);
        }
        // 大于则删除自己
        else {
            minKey.erase(key);
            // 如果空了则遍历计算一次
            if (minKey.empty()) {
                makeMinKey();
            }
        }
    }

    void dec(string key) {
        size_t count = --s[key];
        // 如果这个字符串被移除
        if (count == 0) {
            // 所有位置移除
            s.erase(key);
            minKey.erase(key);
            if (minKey.empty()) {
                makeMinKey();
            }
            maxKey.erase(key);
            if (maxKey.empty()) {
                makeMaxKey();
            }
            return;
        }
        // 与inc对称
        if (count < minCount) {
            minCount = count;
            minKey.clear();
            minKey.insert(key);
        }
        else if (count == minCount) {
            minKey.insert(key);
        }
        if (count > maxCount) {
            maxCount = count;
            maxKey.clear();
            maxKey.insert(key);
        }
        else if (count == maxCount) {
            maxKey.insert(key);
        }
        else {
            maxKey.erase(key);
            if (maxKey.empty()) {
                makeMaxKey();
            }
        }
    }

    string getMaxKey() {
        return maxKey.begin() == maxKey.end() ? "" : *maxKey.begin();
    }

    string getMinKey() {
        return minKey.begin() == minKey.end() ? "" : *minKey.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
