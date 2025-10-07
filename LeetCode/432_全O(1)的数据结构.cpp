// 432_ȫO(1)�����ݽṹ.cpp
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
        // �������������������������ԭ��
        if (count > maxCount) {
            maxCount = count;
            maxKey.clear();
            maxKey.insert(key);
        }
        // ��������
        else if (count == maxCount) {
            maxKey.insert(key);
        }
        // �������С����С�����������ԭ��
        if (count < minCount) {
            minCount = count;
            minKey.clear();
            minKey.insert(key);
        }
        // ��������
        else if (count == minCount) {
            minKey.insert(key);
        }
        // ������ɾ���Լ�
        else {
            minKey.erase(key);
            // ����������������һ��
            if (minKey.empty()) {
                makeMinKey();
            }
        }
    }

    void dec(string key) {
        size_t count = --s[key];
        // �������ַ������Ƴ�
        if (count == 0) {
            // ����λ���Ƴ�
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
        // ��inc�Գ�
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
