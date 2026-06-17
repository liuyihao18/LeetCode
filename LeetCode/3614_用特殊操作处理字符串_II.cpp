// 3614_用特殊操作处理字符串_II.cpp
#include "stdafx.h"
ustd

class Solution {
    long long getLength(string_view s) {
        long long length = 0;
        for (char c : s) {
            switch (c) {
            case '*':
                if (length > 0) {
                    length--;
                }
                break;
            case '#':
                length *= 2;
                break;
            case '%':
                break;
            default:
                length++;
            }
        }
        return length;
    }
    char backtrace(string_view s, long long length, long long k) {
        // s = "a#b%*", _s = "ba", length = 2， k = 1
        // s = "a#b%", _s = "baa", length = 3, k = 1
        // s = "a#b", _s = "aab", length = 3, k = 1
        // s = "a#", _s = "aa", length = 2, k = 1
        // s = "a", _s = "a", length  = 1, k = 0

        // s = "cd%#*#", _s = "dcddcd", length = 6, k = 3
        // s = "cd%#*", _s = "dcd", length = 3, k = 0
        // s = "cd%#", _s = "dcdc", length = 4, k = 0
        // s = "cd%", _s = "dc", length = 2, k = 0
        // s = "cd", _s = "cd", length = 2, k = 1
        for (char c : s | views::reverse) {
            if (isalpha(c) && k + 1 == length) {
                return c;
            }
            switch (c) {
            case '*':
                length++;
                break;
            case '#':
                length /= 2;
                k %= length;
                break;
            case '%':
                k = length - k - 1;
                break;
            default:
                length--;
            }
        }
        return '.';
    }
public:
    char processStr(string_view s, long long k) {
        long long length = getLength(s);
        if (k >= length) {
            return '.';
        }
        return backtrace(s, length, k);
    }
};
