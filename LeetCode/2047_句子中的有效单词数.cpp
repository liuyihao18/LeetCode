// 2047_�����е���Ч������.cpp
#include "stdafx.h"
ustd

class Solution {
    bool isPunctuation(int c) {
        return c == '!' || c == '.' || c == ',';
    }
public:
    int countValidWords(string sentence) {
        sentence.push_back(' ');
        int count = 0;
        int state = 0; // ��̬
        for (auto c : sentence) {
            switch (state) {
            case 0:
                if (c == ' ') {
                    state = 0;
                }
                else if (isalpha(c)) {
                    state = 1;
                }
                else if (isPunctuation(c)) {
                    state = 3;
                }
                else {
                    state = 5;
                }
                break;
            case 1:
                if (c == ' ') {
                    state = 0;
                    count++;
                }
                else if (isalpha(c)) {
                    state = 1;
                }
                else if (c == '-') {
                    state = 2;
                }
                else if (isPunctuation(c)) {
                    state = 3;
                }
                else {
                    state = 5;
                }
                break;
            case 2:
                if (c == ' ') {
                    state = 0;
                }
                else if (isalpha(c)) {
                    state = 4;
                }
                else {
                    state = 5;
                }
                break;
            case 3:
                if (c == ' ') {
                    state = 0;
                    count++;
                }
                else {
                    state = 5;
                }
                break;
            case 4:
                if (c == ' ') {
                    state = 0;
                    count++;
                }
                else if (isalpha(c)) {
                    state = 4;
                }
                else if (isPunctuation(c)) {
                    state = 3;
                }
                else {
                    state = 5;
                }
                break;
            case 5:
                if (c == ' ') {
                    state = 0;
                }
                else {
                    state = 5;
                }
                break;
            default:
                break;
            }
        }
        return count;
    }
};

/*
class Solution {
    bool isPunctuation(int c) {
        return c == '!' || c == '.' || c == ',';
    }
public:
    int countValidWords(string sentence) {
        sentence.push_back(' ');
        int count = 0;
        int state = 0; // ��̬
        for (auto c : sentence) {
            switch (state) {
            case 0: // ��̬
                     if (c == ' ')          state = 0;
                else if (isalpha(c))        state = 1;
                else if (isPunctuation(c))  state = 3;
                else                        state = 5;
                break;
            case 1: // ��ͷ����ĸ
                     if (c == ' ')        { state = 0; count++; }
                else if (isalpha(c))        state = 1;
                else if (c == '-')          state = 2;
                else if (isPunctuation(c))  state = 3;
                else                        state = 5;
                break;
            case 2: // �������ַ�
                     if (c == ' ')          state = 0;                
                else if (isalpha(c))        state = 4;                
                else                        state = 5;
                break;
            case 3: // ĩβ���
                     if (c == ' ')        { state = 0; count++; }
                else                        state = 5;
                break;
            case 4: // ���ַ��ұ�Ҳ����ĸ
                     if (c == ' ')        { state = 0; count++; }
                else if (isalpha(c))        state = 4;
                else if (isPunctuation(c))  state = 3;
                else                        state = 5;
                break;
            case 5: // �ڶ�
                if (c == ' ')               state = 0;
                else                        state = 5;
                break;
            default:
                break;
            }
        }
        return count;
    }
};
*/
