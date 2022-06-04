// 929_独特的电子邮件地址.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (const string& email : emails) {
            bool domain = false;
            bool pass = false;
            string realEmail;
            for (auto c : email) {
                if (domain) {
                    realEmail.push_back(c);
                }
                else {
                    if (c == '@') {
                        domain = true;
                        realEmail.push_back(c);
                    }
                    else if (c == '+') {
                        pass = true;
                    }
                    else if (c == '.') {

                    }
                    else if (pass) {

                    }
                    else {
                        realEmail.push_back(c);
                    }
                }
            }
            s.insert(realEmail);
        }
        return static_cast<int>(s.size());
    }
};
