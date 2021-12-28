// 472_连接词.cpp
#include "custom.h"
ustd

constexpr size_t INDEX(char c) {
    return static_cast<size_t>(c) - 'a';
}

class Solution {
    /* 字典树结点 */
    struct Node {
        bool isLeaf;
        vector<Node*> children;
        Node() : isLeaf(false), children(26, nullptr) {}
    };
private:
    Node* root = new Node;
    /* 如果是连接词可以不插入字典树
    void _insert(Node* root, const string& word, size_t i) {
        Node* p = root;
        for (; i < word.size(); i++) {
            char c = word[i];
            if (!p->children[INDEX(c)]) {
                p->children[INDEX(c)] = new Node;
            }
            p = p->children[INDEX(c)];
        }
        p->isLeaf = true;
    }
    */
    bool _findAnother(Node* root, const string& word, size_t i) {
        if (i >= word.size()) {
            return true;
        }
        Node* p = root;
        for (; i < word.size(); i++) {
            auto c = word[i];
            if (p->children[INDEX(c)]) {
                p = p->children[INDEX(c)];
            }
            else {
                return false;
            }
            if (p->isLeaf) {
                if (_findAnother(root, word, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool walk(Node* root, const string& word) {
        if (word.empty()) {
            return false;
        }
        Node* p = root;
        for (size_t i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!p->children[INDEX(c)]) {
                p->children[INDEX(c)] = new Node;
            }
            p = p->children[INDEX(c)];
            if (p->isLeaf) {
                if (_findAnother(root, word, i + 1)) {
                    return true;
                }
            }
        }
        p->isLeaf = true;
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& word1, const string& word2) {
            return word1.size() < word2.size();
            });
        vector<string> result;
        for (const auto& word : words) {
            if (walk(root, word)) {
                result.push_back(word);
            }
        }
        return result;
    }
};
