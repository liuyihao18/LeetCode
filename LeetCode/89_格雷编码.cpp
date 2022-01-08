// 89_¸ñÀ×±àÂë.cpp
#include "custom.h"
ustd

class Solution {
#ifdef STRING
    vector<string> _grayCode(int n) {
        if (n == 0) {
            return { "" };
        }
        vector<string> result = _grayCode(n - 1);
        vector<string> temp = result;
        for (auto& code : result) {
            code += '0';
        }
        for (auto& code : temp) {
            code += '1';
        }
        copy(temp.rbegin(), temp.rend(), back_inserter(result));
        return result;
    }
    int _2int(const string& code) {
        int result = 0;
        for (size_t i = 0; i < code.size(); i++) {
            result |= (1 << (static_cast<size_t>(code[i] - '0') * (code.size() - i - 1)));
        }
        return result;
    }
#endif // STRING
public:
#ifdef STRING
    vector<int> grayCode(int n) {
        vector<string> temp = _grayCode(n);
        vector<int> result;
        for (const auto& code : temp) {
            result.push_back(stoi(code, nullptr, 2));
        }
        return result;
    }
#else
    vector<int> grayCode(int n) {
        if (n == 0) {
            return { 0 };
        }
        vector<int> result = grayCode(n - 1);
        vector<int> temp = result;
        for (auto& code : result) {
            code = (code << 1) | 0;
        }
        for (auto& code : temp) {
            code = (code << 1) | 1;
        }
        copy(temp.rbegin(), temp.rend(), back_inserter(result));
        return result;
    }
#endif // STRING
};
