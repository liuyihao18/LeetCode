// 636_函数的独占时间.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Function {
        int id;
        int start;
        int duration;
        Function(int id, int start) : id(id), start(start), duration(0) {}
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<Function> s;
        for (const string& log : logs) {
            size_t i1 = log.find_first_of(':');
            size_t i2 = log.find_last_of(':');
            int id = stoi(log.substr(0, i1));
            string type = log.substr(i1 + 1, i2 - i1 - 1);
            int timestamp = stoi(log.substr(i2 + 1));
            if (type == "start") {
                if (!s.empty()) {
                    Function& last = s.top();
                    last.duration += timestamp - last.start;
                }
                s.emplace(id, timestamp);
            }
            else {
                Function curr = s.top();
                s.pop();
                result[curr.id] += curr.duration + timestamp - curr.start + 1;
                if (!s.empty()) {
                    Function& last = s.top();
                    last.start = timestamp + 1;
                }
            }
        }
        return result;
    }
};
