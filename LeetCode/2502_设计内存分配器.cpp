// 2502_设计内存分配器.cpp
#include "custom.h"
ustd

class Allocator {
    map<int, int> allocateTable;
    map<int, vector<int>> findAddr;
    int n;
public:
    Allocator(int n) : n(n) {

    }

    int allocate(int size, int mID) {
        // printTable();
        if (size > n) {
            return -1;
        }
        auto iter = allocateTable.begin();
        if (iter == allocateTable.end() || size <= iter->first) {
            allocateTable[0] = size;
            findAddr[mID].push_back(0);
            return 0;
        }
        auto next_iter = next(iter);
        while (next_iter != allocateTable.end()) {
            if (iter->first + iter->second + size <= next_iter->first) {
                break;
            }
            iter = next_iter;
            next_iter = next(next_iter);
        }
        if (iter->first + iter->second + size <= n) {
            allocateTable[iter->first + iter->second] = size;
            findAddr[mID].push_back(iter->first + iter->second);
            return iter->first + iter->second;
        }
        return -1;
    }

    int freeMemory(int mID) {
        // printTable();
        if (!findAddr.count(mID)) {
            return 0;
        }
        int size = 0;
        for (auto addr : findAddr[mID]) {
            size += allocateTable[addr];
            allocateTable.erase(addr);
        }
        findAddr.erase(mID);
        return size;
    }

    void printTable() {
        cout << "-------------------------" << endl;
        cout << "allocateTable: " << endl;
        for (const auto& [key, val] : allocateTable) {
            cout << "* " << key << " - " << val << endl;
        }
        cout << "findAddr: " << endl;
        for (const auto& [key, val] : findAddr) {
            cout << "* " << key << " - " << "[";
            for (auto addr : val) {
                cout << addr << ", ";
            }
            cout << "]" << endl;
        }
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
