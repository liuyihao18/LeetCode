// 690_员工的重要性.cpp
#include "stdafx.h"
ustd

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
    int _getImportance(vector<Employee*> employees, int id) {
        auto employee = *lower_bound(employees.begin(), employees.end(), id,
            [](const Employee* e, int id) {
                return e->id < id;
            }
        );
        int importance = employee->importance;
        for (int sub : employee->subordinates) {
            importance += getImportance(employees, sub);
        }
        return importance;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        sort(employees.begin(), employees.end(),
            [](const Employee* e1, const Employee* e2) {
                return e1->id < e2->id;
            }
        );
        return _getImportance(employees, id);
    }
};
