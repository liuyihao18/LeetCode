// 676_实现一个魔法字典.cpp
#include "custom.h"
ustd

class MagicDictionary {
    set<string> dictionary;
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        this->dictionary = set(dictionary.begin(), dictionary.end());
    }

    bool search(string searchWord) {
        for (size_t i = 0; i < searchWord.size(); i++) {
            char origin = searchWord[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != origin) {
                    searchWord[i] = c;
                    if (dictionary.count(searchWord)) {
                        return true;
                    }
                }
            }
            searchWord[i] = origin;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
