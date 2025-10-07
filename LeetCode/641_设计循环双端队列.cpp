// 641_设计循环双端队列.cpp
#include "stdafx.h"
ustd

class MyCircularDeque {
    int size;
    int capacity;
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int val) :val(val), prev(this), next(this) {}
        Node(int val, Node* prev, Node* next) :val(val), prev(prev), next(next) {}
    } *head;
public:
    MyCircularDeque(int k) : size(0), capacity(k), head(nullptr) {}

    ~MyCircularDeque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
    
    ostream& print() {
        if (!isEmpty()) {
            Node* curr = head;
            // do {
            //     cout << curr->val << " ";
            // } while ((curr = curr->next) != head);
            for (int i = 0; i < size; i++, curr = curr->next) {
                cout << curr->val << " ";
            }
        }
        return cout;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        Node* temp = new Node(value);
        if (isEmpty()) {
            head = temp;
        }
        else {
            temp->next = head;
            head->prev->next = temp;
            temp->prev = head->prev;
            head->prev = temp;
            head = temp;
        }
        ++size;
        // print() << endl;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        Node* temp = new Node(value);        
        if (isEmpty()) {
            head = temp;
        }
        else {
            Node* last = head->prev;
            temp->prev = last;
            last->next->prev = temp;
            temp->next = last->next;
            last->next = temp;
        }
        ++size;
        // print() << endl;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head->prev;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        --size;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return head->prev->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
