// 591_标签验证器.cpp
#include "custom.h"
#include <regex>
ustd

#define IS(code, i, c)      i < code.size() && code[i] == c
#define ISNOT(code, i, c)   i < code.size() && code[i] != c
// TODO: 使用LL(1)递归下降
class Solution {
    enum class STATE {
        START,
        IN_TAG_NAME,
        BETWEEN_TAG,
        OUT_TAG_NAME,
        CDATA,
        BETWEEN_CDATA,
        OVER,
    };
public:
    bool isValid(string code) {
        STATE state = STATE::START;
        string inTagName, outTagName;
        stack<string> tags;
        for (size_t i = 0; i < code.size();) {
            switch (state)
            {
            case STATE::START:
                if (code[i] == '<') {
                    if (IS(code, i + 1, '/') || IS(code, i + 1, '!')) {
                        return false;
                    }
                    else {
                        state = STATE::IN_TAG_NAME;
                    }
                }
                else {
                    return false;
                }
                i++;
                break;
            case STATE::IN_TAG_NAME:
                if (code[i] == '>') {
                    if (inTagName.size() < 1 || inTagName.size() > 9) {
                        return false;
                    }
                    state = STATE::BETWEEN_TAG;
                }
                else if (code[i] >= 'A' && code[i] <= 'Z') {
                    inTagName += code[i];
                }
                else {
                    return false;
                }
                i++;
                break;
            case STATE::BETWEEN_TAG:
                if (code[i] == '<') {
                    if (IS(code, i + 1, '/')) {
                        outTagName.clear();
                        state = STATE::OUT_TAG_NAME;
                        i += 2;
                    }
                    else if (IS(code, i + 1, '!')) {
                        state = STATE::CDATA;
                        i += 2;
                    }
                    else {
                        state = STATE::IN_TAG_NAME;
                        tags.push(inTagName);
                        inTagName.clear();
                        i++;
                    }
                }
                else {
                    i++;
                }
                break;
            case STATE::OUT_TAG_NAME:
                if (code[i] == '>') {
                    if (outTagName == inTagName) {
                        if (tags.empty()) {
                            state = STATE::OVER;
                        }
                        else {
                            inTagName = tags.top();
                            tags.pop();
                            state = STATE::BETWEEN_TAG;
                        }
                    }
                    else {
                        return false;
                    }
                }
                else {
                    outTagName += code[i];
                }
                i++;
                break;
            case STATE::CDATA:
                if (IS(code, i, '[') &&
                    IS(code, i + 1, 'C') &&
                    IS(code, i + 2, 'D') &&
                    IS(code, i + 3, 'A') &&
                    IS(code, i + 4, 'T') &&
                    IS(code, i + 5, 'A') &&
                    IS(code, i + 6, '[')) {
                    state = STATE::BETWEEN_CDATA;
                    i += 7;
                }
                else {
                    return false;
                }
                break;
            case STATE::BETWEEN_CDATA:
                if (IS(code, i, ']') &&
                    IS(code, i + 1, ']') &&
                    IS(code, i + 2, '>')) {
                    state = STATE::BETWEEN_TAG;
                    i += 3;
                }
                else {
                    i++;
                }
                break; 
            case STATE::OVER:
                return false;
                break;
            default:
                break;
            }
        }
        if (state == STATE::OVER) {
            return true;
        }
        else {
            return false;
        }
    }
};

/*
class Solution {
public:
    bool isValid(string code) {
        regex r1 = regex("<!\\[CDATA\\[.*?\\]\\]>|t");
        regex r2 = regex("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, r1, "-");
        string prev = "";
        while (code != prev) {
            prev = code;
            code = regex_replace(code, r2, "t");
        }
        return code == "t";
    }
};
*/
