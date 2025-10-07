// 1993_Ê÷ÉÏµÄ²Ù×÷.cpp
#include "stdafx.h"
ustd

class LockingTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> status;

    bool canLock(int num, int user) {
        return this->status[num] == -1;
    }

    bool canUnlock(int num, int user) {
        return this->status[num] == user;
    }

public:
    LockingTree(vector<int>& parent) {
        size_t n = parent.size();
        this->parent = vector<int>(n, -1);
        this->children = vector<vector<int>>(n);
        this->status = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            this->parent[i] = parent[i];
            if (parent[i] != -1) {
                this->children[parent[i]].push_back(i);
            }
            this->status[i] = -1;
        }
    }

    bool lock(int num, int user) {
        if (canLock(num, user)) {
            this->status[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (canUnlock(num, user)) {
            this->status[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (!canLock(num, user)) {
            return false;
        }
        int p = parent[num];
        while (p != -1) {
            if (!canLock(p, user)) {
                return false;
            }
            p = parent[p];
        }
        queue<int> q;
        for (auto child : children[num]) {
            q.emplace(child);
        }
        bool flag = false;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            if (!canLock(c, user)) {
                flag = true;
            }
            for (auto child : children[c]) {
                q.emplace(child);
            }
        }
        if (!flag) {
            return false;
        }
        this->status[num] = user;
        for (auto child : children[num]) {
            q.emplace(child);
        }
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            this->status[c] = -1;
            for (auto child : children[c]) {
                q.emplace(child);
            }
            cout << c << endl;
        }
        return true;
    }
};
