// 1108_IP_地址无效化.cpp
#include "custom.h"
ustd

class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (auto c : address) {
            if (c == '.') {
                result += "[.]";
            }
            else {
                result += c;
            }
        }
        return result;
    }
};
