// 1106_解析布尔表达式.cpp
#include "stdafx.h"
ustd

/* LL1
class Solution {
private:
    bool matchT(const string& expression, size_t& i) {
        i++; // 't'
        return true;
    }
    bool matchF(const string& expression, size_t& i) {
        i++; // 'f'
        return false;
    }
    bool matchNot(const string& expression, size_t& i) {
        i++; // '!'
        i++; // '('
        bool result = matchExpression(expression, i);
        i++; // ')'
        return !result;
    }
    bool matchAnd(const string& expression, size_t& i) {
        i++; // '&'
        i++; // '('
        bool result = true;
        while (true) {
            result = result && matchExpression(expression, i);
            if (expression[i++] == ')') { // ',' or ')'
                break;
            }
        }
        return result;
    }
    bool matchOr(const string& expression, size_t& i) {
        i++; // '|'
        i++; // '('
        bool result = false;
        while (true) {
            result = result || matchExpression(expression, i);
            if (expression[i++] == ')') { // ',' or ')'
                break;
            }
        }
        return result;
    }
    bool matchExpression(const string& expression, size_t& i) {
        if (expression[i] == 't') {
            return matchT(expression, i);
        }
        else if (expression[i] == 'f') {
            return matchF(expression, i);
        }
        else if (expression[i] == '!') {
            return matchNot(expression, i);
        }
        else if (expression[i] == '&') {
            return matchAnd(expression, i);
        }
        else if (expression[i] == '|') {
            return matchOr(expression, i);
        }
        cerr << "Error parse." << endl;
        return false;
    }

public:
    bool parseBoolExpr(string expression) {
        size_t i = 0;
        return matchExpression(expression, i);
    }
};
*/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        int n = static_cast<int>(expression.size());
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == ',') {
                continue;
            }
            else if (c != ')') {
                stk.push(c);
            }
            else {
                int t = 0, f = 0;
                while (stk.top() != '(') {
                    char val = stk.top();
                    stk.pop();
                    if (val == 't') {
                        t++;
                    }
                    else {
                        f++;
                    }
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                switch (op) {
                case '!':
                    stk.push(f == 1 ? 't' : 'f');
                    break;
                case '&':
                    stk.push(f == 0 ? 't' : 'f');
                    break;
                case '|':
                    stk.push(t > 0 ? 't' : 'f');
                    break;
                default:
                    break;
                }
            }
        }
        return stk.top() == 't';
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/parsing-a-boolean-expression/solution/jie-xi-bu-er-biao-da-shi-by-leetcode-sol-vmvg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
