// 2296_设计一个文本编辑器.cpp
#include "stdafx.h"
ustd

class TextEditor {
    list<char> _editor;
    list<char>::iterator _cursor;

    string getLeftText(int required) {
        string text;
        list<char>::iterator temp = _cursor;
        while (required > 0 && temp != _editor.begin()) {
            temp = prev(temp);
            text += *temp;
            required--;
        }
        reverse(text.begin(), text.end());
        return text;
    }
public:
    TextEditor() : _cursor(_editor.end()) {

    }

    void addText(string text) {
        for (char c : text) {
            _cursor = _editor.insert(_cursor, c);
            _cursor = next(_cursor);
        }
        // display();
    }

    int deleteText(int k) {
        int _k = 0;
        while (k > 0 && _cursor != _editor.begin()) {
            _cursor = _editor.erase(prev(_cursor));            
            k--;
            _k++;
        }
        // display();
        return _k;
    }

    string cursorLeft(int k) {
        while (k > 0 && _cursor != _editor.begin()) {
            _cursor = prev(_cursor);
            k--;
        }
        return getLeftText(10);
    }

    string cursorRight(int k) {
        while (k > 0 && _cursor != _editor.end()) {
            _cursor = next(_cursor);
            k--;
        }
        return getLeftText(10);
    }

    void display() {
        for (char c : _editor) {
            cout << c;
        }
        cout << endl;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

/*
int main() {
    TextEditor* obj = new TextEditor();
    obj->addText("leetcode");
    obj->deleteText(4);
    obj->addText("practice");
    obj->cursorRight(3);
    obj->cursorLeft(8);
    obj->deleteText(10);
    obj->cursorLeft(2);
    obj->cursorRight(6);
    return 0;
}
*/
