// 211_添加与搜索单词_-_数据结构设计.cpp
#include "stdafx.h"
ustd

// 更好的做法是用字典树

class WordDictionary {
public:
    WordDictionary() {

    }

    void addWord(string word) {
        dict.insert(word);
        search_result.clear();
    }

    bool equal(const string& s1, const string& s2) {
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] == '.') {
                continue;
            }
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }

    bool search(string word) {
        if (search_result.find(word) != search_result.end()) {
            return search_result[word];
        }
        if (dict.find(word) != dict.end()) {
            search_result[word] = true;
            return true;
        }
        for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
            if (word.size() != iter->size()) {
                continue;
            }
            if (equal(word, *iter)) {
                search_result[word] = true;
                return true;
            }
        }
        search_result[word] = false;
        return false;
    }

private:
    unordered_set<string> dict;
    unordered_map<string, bool> search_result;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */