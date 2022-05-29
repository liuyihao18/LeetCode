// 468_—È÷§IPµÿ÷∑.cpp
#include "custom.h"
ustd

class Solution {
    const string IPv4 = "IPv4";
    const string IPv6 = "IPv6";
    const string Neither = "Neither";
    vector<string> split(const string& str, char delimeter) {
        vector<string> result;
        string temp;
        for (auto c : str) {
            if (c == delimeter) {
                result.push_back(temp);
                temp.clear();
            }
            else {
                temp += c;
            }
        }
        result.push_back(temp);
        return result;
    }
    bool validIPv4(const string& queryIP) {
        const vector<string>& splitIP = split(queryIP, '.');
        if (splitIP.size() != 4) {
            return false;
        }
        for (const string& ipCell : splitIP) {
            if (ipCell.size() == 0) {
                return false;
            }
            if (ipCell.size() > 3) {
                return false;
            }
            if (ipCell.size() > 1 && ipCell[0] == '0') {
                return false;
            }
            for (char c : ipCell) {
                if (isdigit(c));
                else return false;
            }
            int ipNum = stoi(ipCell);
            if (ipNum < 0 || ipNum >255) {
                return false;
            }
        }
        return true;
    }
    bool validIPv6(const string& queryIP) {
        const vector<string>& splitIP = split(queryIP, ':');
        if (splitIP.size() != 8) {
            return false;
        }
        for (const string& ipCell : splitIP) {
            if (ipCell.size() == 0) {
                return false;
            }
            if (ipCell.size() > 4) {
                return false;
            }
            for (char c : ipCell) {
                if (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
                else return false;
            }
        }
        return true;
    }
public:
    string validIPAddress(const string& queryIP) {
        if (queryIP.find('.') != string::npos) {
            if (validIPv4(queryIP)) {
                return IPv4;
            }
        }
        else if (queryIP.find(':')!=string::npos) {
            if (validIPv6(queryIP)) {
                return IPv6;
            }
        }
        return Neither;
    }
};
