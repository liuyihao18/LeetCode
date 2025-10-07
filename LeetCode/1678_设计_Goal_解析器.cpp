// 1678_Éè¼Æ_Goal_½âÎöÆ÷.cpp
#include "stdafx.h"
#include <regex>
ustd

class Solution {
public:
    string interpret(string command) {
        command = regex_replace(command, regex("\\(\\)"), "o");
        command = regex_replace(command, regex("\\(al\\)"), "al");
        return command;
    }
};
