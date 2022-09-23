// 707_Éè¼ÆÁ´±í.cpp
#include "custom.h"
ustd

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int val, Node* next) : val(val), next(next) {}
    } *head;
    size_t size;
public:
    MyLinkedList() : head(new Node(0, nullptr)), size(0) {

    }

    ~MyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* curr = head->next;
        while (index > 0) {
            curr = curr->next;
            index--;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val, head->next);
        head->next = node;
        size++;
    }

    void addAtTail(int val) {
        Node* prev = head;
        Node* curr = head->next;
        while (curr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = new Node(val, nullptr);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) {
            addAtHead(val);
        }
        else if (index > size) {
            return;
        }
        else {
            Node* prev = head;
            while (index > 0) {
                prev = prev->next;
                index--;
            }
            Node* node = new Node(val, prev->next);
            prev->next = node;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* prev = head;
        while (index > 0) {
            prev = prev->next;
            index--;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
