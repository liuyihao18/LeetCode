// 564_寻找最近的回文数.cpp
#include "stdafx.h"
ustd

class Solution {
    static int cmp(string n1, string n2) {
        while (n1.size() > n2.size()) {
            n2 = "0" + n2;
        }
        while (n2.size() > n1.size()) {
            n1 = "0" + n1;
        }
        for (size_t i = 0; i < n1.size(); i++) {
            if (n1[i] > n2[i]) {
                return 1;
            }
            else if (n1[i] < n2[i]) {
                return -1;
            }
        }
        return 0;
    }
    static string diff(string n1, string n2) {
        while (n1.size() > n2.size()) {
            n2 = "0" + n2;
        }
        while (n2.size() > n1.size()) {
            n1 = "0" + n1;
        }
        int greater = cmp(n1, n2);
        string result;
        for (size_t i = 0; i < n1.size(); i++) {
            if (greater >= 0) {
                result.push_back(n1[i] - n2[i]);
            }
            else {
                result.push_back(n2[i] - n1[i]);
            }
        }
        for (size_t i = 0; i < result.size(); i++) {
            if (result[result.size() - i - 1] < 0) {
                result[result.size() - i - 1] += 10;
                result[result.size() - i - 2] -= 1;
            }
        }
        for (size_t i = 0; i < result.size(); i++) {
            result[i] += '0';
        }
        return result;
    }
    struct Node {
        string num;
        string diff;
        bool operator<(const Node& n) const {
            return cmp(diff, n.diff) < 0 || 
                (cmp(diff, n.diff) == 0 && cmp(num, n.num) < 0);
        }
    };
public:
    string nearestPalindromic(string n) {
        size_t mid = (n.size() - 1) / 2;
        set<Node> results;
        int carry = 0;
        string temp;
        // 直接对称
        if (n.size() & 1) {
            temp.insert(temp.end(), n[mid]);
        }
        else {
            temp.insert(temp.begin(), n[mid]);
            temp.insert(temp.end(), n[mid]);
        }
        for (size_t i = 1; i <= mid; i++) {
            temp.insert(temp.begin(), n[mid - i]);
            temp.insert(temp.end(), n[mid - i]);
        }
        results.insert({ temp, diff(temp, n) });
        // 减一对称
        carry = -1;
        temp.clear();
        if (n.size() & 1) {
            if (n[mid] + carry < '0') {
                temp.insert(temp.end(), '9');
            }
            else {
                temp.insert(temp.end(), n[mid] + carry);
                carry = 0;
            }
        }
        else {
            if (n[mid] + carry < '0') {
                temp.insert(temp.begin(), '9');
                temp.insert(temp.end(), '9');
            }
            else {
                temp.insert(temp.begin(), n[mid] + carry);
                temp.insert(temp.end(), n[mid] + carry);
                carry = 0;
            }
        }
        for (size_t i = 1; i <= mid; i++) {
            if (n[mid - i] + carry < '0') {
                temp.insert(temp.begin(), '9');
                temp.insert(temp.end(), '9');
            }
            else {
                temp.insert(temp.begin(), n[mid - i] + carry);
                temp.insert(temp.end(), n[mid - i] + carry);
                carry = 0;
            }
        }
        results.insert({ temp, diff(temp, n) });
        // 加一对称
        carry = 1;
        temp.clear();
        if (n.size() & 1) {
            if (n[mid] + carry > '9') {
                temp.insert(temp.end(), '0');
            }
            else {
                temp.insert(temp.end(), n[mid] + carry);
                carry = 0;
            }
        }
        else {
            if (n[mid] + carry > '9') {
                temp.insert(temp.begin(), '0');
                temp.insert(temp.end(), '0');
            }
            else {
                temp.insert(temp.begin(), n[mid] + carry);
                temp.insert(temp.end(), n[mid] + carry);
                carry = 0;
            }
        }
        for (size_t i = 1; i <= mid; i++) {
            if (n[mid - i] + carry > '9') {
                temp.insert(temp.begin(), '0');
                temp.insert(temp.end(), '0');
            }
            else {
                temp.insert(temp.begin(), n[mid - i] + carry);
                temp.insert(temp.end(), n[mid - i] + carry);
                carry = 0;
            }
        }
        results.insert({ temp, diff(temp, n) });
        // 9...9
        temp = string(n.size() - 1, '9');
        if (temp.size() == 0) {
            temp = "0";
        }
        results.insert({ temp, diff(temp, n) });
        // 10...01
        temp = string(n.size() + 1, '0');
        temp[0] = '1';
        temp[temp.size() - 1] = '1';
        results.insert({ temp, diff(temp, n) });
        // 答案
        auto iter = results.begin();
        if (iter->num != n) {
            return iter->num;
        }
        else {
            return (++iter)->num;
        }
    }
};
