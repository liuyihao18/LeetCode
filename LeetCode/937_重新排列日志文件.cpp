// 937_重新排列日志文件.cpp
#include "stdafx.h"
ustd

class Solution {
    enum class TYPE {
        type_alpha = 0,
        type_num = 1
    };
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& s1, const string& s2) {
            string identifier1, identifier2;
            string content1, content2;
            TYPE type1 = TYPE::type_alpha, type2 = TYPE::type_num;
            for (size_t i = 0; i < s1.size(); i++) {
                if (s1[i] == ' ') {
                    identifier1 = s1.substr(0, i);
                    content1 = s1.substr(i + 1);
                    type1 = isalpha(s1[i + 1]) ? TYPE::type_alpha : TYPE::type_num;
                    break;
                }
            }
            for (size_t i = 0; i < s2.size(); i++) {
                if (s2[i] == ' ') {
                    identifier2 = s2.substr(0, i);
                    content2 = s2.substr(i + 1);
                    type2 = isalpha(s2[i + 1]) ? TYPE::type_alpha : TYPE::type_num;
                    break;
                }
            }
            if (type1 != type2) {
                return type1 < type2;
            }
            else if (type1 == /*type2 ==*/ TYPE::type_alpha) {
                if (content1 == content2) {
                    return identifier1 < identifier2;
                }
                else {
                    return content1 < content2;
                }
            }
            else {
                return false;
            }
            });
        return logs;
    }
};
