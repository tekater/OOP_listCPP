#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

struct Node {
    int val;
    Node *next;
};

class List {
    Node* head;
    Node* tail;
public:
    List() {

        head = tail = nullptr;
    }

    void Push(int x) {
        Node* temp = new Node;

        temp->val = x;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
        }
        else {
            tail->next = temp;
        }
        tail = temp;
    }

    void Pop() {
        if (head != nullptr) {
            Node* copyhead = head;
            head = head->next;
            delete copyhead;
        }
    }

    void Clear() {
        while (head != nullptr) {
            Pop();
        }
        tail = nullptr;
    }

    void print() {
        Node* copyhead = head;
        while (copyhead != nullptr) {
            cout << copyhead->val << " ";
            copyhead = copyhead->next;
        }
        cout << endl;
    }

    int getElem(int n) {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    void setElem(int n,int x) {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                copyhead->val = x;
            }
        }
    }

    ~List() {
        Clear();
    }

    int operator[](int n) const{
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    int& operator[](int n) {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        int a = -1;
        return a;
    }

};



int main() {

    setlocale(0, "");
    srand(time(NULL));

    List l1;

    for (int i = 0; i < 5; i++) {
        l1.Push(rand() % 20);
    }
    l1.print();

    l1.Pop(); l1.print();
    l1.Pop(); l1.print();

    l1.Clear(); l1.print();

    for (int i = 0; i < 20; i++) {
        l1.Push(rand() % 20);
    }
    l1.print();
    cout << "(10) - " << l1.getElem(10) << endl;
    l1[2] = 5;
    l1.print();
}
