// 2434_使用机器人打印字典序最小的字符串.cpp
#include "custom.h"
ustd

template<typename T>
class Table {
    const size_t N = 26;
    vector<deque<T>> table;
    T front;
public:
    Table() : table(N), front(-1) {}
    void pushBackByIndex(size_t index, T value) {
        table[index].push_back(value);
    }
    void popFrontByIndex(size_t index) {
        T temp = table[index].front();
        table[index].pop_front();
        if (temp == front) {
            updateFront();
        }
    }
    T getFront() {
        return front;
    }
    void updateFront() {
        for (const deque<T>& row : table) {
            if (!row.empty()) {
                front = row.front();
                return;
            }
        }
    }
};

class Solution {
    size_t alphaToIndex(char c) {
        return static_cast<size_t>(c -  'a');
    }
    char indexToAlpha(size_t index) {
        return static_cast<char>(index + 'a');
    }
public:
    string robotWithString(string s) {
        Table<size_t> table;
        size_t n = s.size();
        for (size_t i = 0; i < n; i++) {
            table.pushBackByIndex(alphaToIndex(s[i]), i);
        }
        table.updateFront();
        string result;
        stack<size_t> st;
        for (size_t i = 0; i < s.size(); i++) {
            st.push(i);
            table.popFrontByIndex(alphaToIndex(s[i]));
            while (!st.empty() && s[st.top()] <= s[table.getFront()]) {
                result += s[st.top()];
                st.pop();
            }
        }
        while (!st.empty()) {
            result += s[st.top()];
            st.pop();
        }
        return result;
    }
};
