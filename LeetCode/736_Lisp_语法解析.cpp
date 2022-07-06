// 736_Lisp_语法解析.cpp
#include "custom.h"
ustd

class Solution {
    struct Scope {
        map<string, int> m;
        Scope* outer;
        Scope(Scope* outer) :outer(outer) {}
    };
private:
    Scope global;
    Scope* currScope;
    string expression;
    size_t i = 0;
private:
    int findVariableValue(string name) {
        Scope* scope = currScope;
        while (scope) {
            if (scope->m.count(name)) {
                return scope->m.at(name);
            }
            scope = scope->outer;
        }
        throw runtime_error("Can't find variable " + name + ".");
    }
    void match(char c) {
        if (i >= expression.size()) {
            string errMsg = "Unexpected 'EOF' at pos ";
            errMsg += to_string(i);
            errMsg += " - expected ";
            errMsg += c;
            errMsg += ".";
            throw runtime_error(errMsg);
        }
        if (expression[i] != c) {
            string errMsg = "Can't match character '";
            errMsg += expression[i];
            errMsg += "' at pos ";
            errMsg += to_string(i);
            errMsg += " - expected ";
            errMsg += c;
            errMsg += ".";
            throw runtime_error(errMsg);
        }
        i++;
    }
    void match(string str) {
        for (auto c : str) {
            match(c);
        }
    }
    // const: -?[0-9]+
    int visitConstant() {
        string result;
        if (expression[i] == '-') {
            result += expression[i];
            match(expression[i]);
        }
        while (isdigit(expression[i])) {
            result += expression[i];
            match(expression[i]);
        }
        return stoi(result);
    }
    // var: [a-z][a-z0-9]*
    string visitVariableName() {
        string variableName;
        while (isalnum(expression[i])) {
            variableName += expression[i];
            match(expression[i]);
        }
        return variableName;
    }
    int visitVariableValue() {
        return findVariableValue(visitVariableName());
    }
    // exp: '(' let | add | mul ')'
    //      | var 
    //      | const
    int visitExpression() {
        if (expression[i] == '(') {
            match('(');
            int result = 0;
            switch (expression[i]) {
            case 'l':
                result = visitLetExpression();
                break;
            case 'a':
                result = visitAddExpression();
                break;
            case 'm':
                result = visitMultExpression();
                break;
            default:
                throw runtime_error("Unexpected expression structure.");
            }
            match(')');
            return result;
        }
        else if (expression[i] == '-' || isdigit(expression[i])) {
            return visitConstant();
        }
        else if (isalpha(expression[i])) {
            return visitVariableValue();
        }
        else {
            throw runtime_error("Unexpected expression structure.");
        }
    }
    // let: 'let' var_1 exp_1 var_2 exp_2 ... var_n exp_n exp
    int visitLetExpression() {
        currScope = new Scope(currScope);
        match("let");
        match(' ');
        // 这玩意不是LL1文法，必须两次扫描
        int spaceCount = 0;
        int paramCount = 0;
        for (size_t j = i; j < expression.size(); j++) {
            if (paramCount == 0 && expression[j] == ')') {
                break;
            }
            if (expression[j] == ')') {
                paramCount--;
            }
            if (expression[j] == '(') {
                paramCount++;
            }
            if (paramCount == 0 && expression[j] == ' ') {
                spaceCount++;
            }
        }
        if (spaceCount & 1) {
            throw runtime_error("Unexpected let expression structure.");
        }
        for (int j = 0; j < spaceCount / 2; j++) {
            string variableName = visitVariableName();
            match(' ');
            int variableValue = visitExpression();
            match(' ');
            currScope->m[variableName] = variableValue;
        }
        int result = visitExpression();
        Scope* outerScope = currScope->outer;
        delete currScope;
        currScope = outerScope;
        return result;
    }
    // add: 'add' exp_1 exp_2
    int visitAddExpression() {
        match("add");
        match(' ');
        int op1 = visitExpression();
        match(' ');
        int op2 = visitExpression();
        return op1 + op2;
    }
    // mult: 'mult' exp_1 exp_2
    int visitMultExpression() {
        match("mult");
        match(' ');
        int op1 = visitExpression();
        match(' ');
        int op2 = visitExpression();
        return op1 * op2;
    }
public:
    Solution() : global(nullptr), currScope(&global) {}
    int evaluate(string expression) {
        this->expression = expression;
        this->i = 0;
        return visitExpression();
    }
};
