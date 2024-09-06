// utils.cpp
#include "utils.h"

istream& getArray(istream& in, vector<int>& nums) {
    string input;
    getline(cin, input);

    if (input.front() == '[' && input.back() == ']') {
        input = input.substr(1, input.size() - 2);
    }

    stringstream ss(input);
    string temp;

    while (std::getline(ss, temp, ',')) {
        nums.push_back(std::stoi(temp));
    }

    return in;
}
