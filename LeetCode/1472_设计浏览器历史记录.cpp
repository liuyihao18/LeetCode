// 1472_设计浏览器历史记录.cpp
#include "stdafx.h"
ustd

class BrowserHistory {
    vector<string> history;
    vector<string>::iterator curr;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = history.begin();
    }

    void visit(string url) {
        history.erase(next(curr), history.end());
        curr = history.insert(next(curr), url);
    }

    string back(int steps) {
        while (curr != history.begin() && steps > 0) {
            curr = prev(curr);
            steps--;
        }
        return *curr;
    }

    string forward(int steps) {
        while (next(curr) != history.end() && steps > 0) {
            curr = next(curr);
            steps--;
        }
        return *curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

#ifndef LEETCODE
int main() {
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    cout << obj->back(1) << endl;
    cout << obj->back(1) << endl;
    cout << obj->forward(1) << endl;
    obj->visit("linkedin.com");
    cout << obj->forward(2) << endl;
    cout << obj->back(2) << endl;
    cout << obj->back(7) << endl;
    return 0;
}
#endif
