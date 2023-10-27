#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>

template <class Type>
class Node {
public:
    Type data;
    Node* next;
    Node* prev;

    Node(Type newData) : data(newData), next(nullptr), prev(nullptr) {}
};

template <class Type>
class LinkedList {
private:
    Node<Type>* head;
    Node<Type>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void pushBack(Type newData) {
        Node<Type>* newNode = new Node<Type>(newData);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    Type getLast() {
        if (tail) {
            return tail->data;
        }
        throw std::runtime_error("List is empty");
    }

    void popBack() {
        if (tail) {
            Node<Type>* prev = tail->prev;
            delete tail;
            tail = prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            size--;
        } else {
            throw std::runtime_error("List is empty");
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    void clear() {
        while (!isEmpty()) {
            popBack();
        }
    }
};

#endif
