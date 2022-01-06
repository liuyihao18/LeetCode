// 71_¼ò»¯Â·¾¶.cpp
#include "custom.h"
ustd

class Solution {
    struct Directory {
        Directory* parent{ nullptr };
        Directory* child{ nullptr };
        string name;
        Directory() = default;
        Directory(Directory* parent, string&& name) : parent(parent), name(name) {}
    } *root, *curr;
public:
    Solution() :root(new Directory), curr(root) {}
    ~Solution() { 
        while (curr) {
            Directory* temp = curr->parent;
            delete curr;
            curr = temp;
        }
    }
    string simplifyPath(string path) {
        path += "/";
        string name;
        for (auto c : path) {
            if (c == '/') {
                if (name.empty() || name == ".") {
                    // pass
                }
                else if (name == "..") {
                    if (curr != root) {
                        Directory* temp = curr;
                        curr = curr->parent;
                        curr->child = temp->child;
                        delete temp;
                    }
                }
                else {
                    Directory* temp = new Directory(curr, std::move(name));
                    curr->child = temp;
                    curr = temp;
                }
                name.clear();
            }
            else {
                name += c;
            }
        }
        string result = "/";
        Directory* p = root->child;
        while (p) {
            result += p->name;
            result += "/";
            p = p->child;
        }
        if (curr != root) { result.pop_back(); }
        return result;
    }
};
