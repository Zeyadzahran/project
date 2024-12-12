#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <class  T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
            : data(data), prev(prev), next(next) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}


    ~DoublyLinkedList() {
        clear();
    }

    void append(const T& value) {
        Node* newNode = new Node(value, tail, nullptr);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    void prepend(const T& value) {
        Node* newNode = new Node(value, nullptr, head);
        if (head) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        size++;
    }
    int  search(const  T& value)const {
        Node* current = head;
        int ctr = 0 ;
        while (current) {
            if (current->data == value) {
                return ctr;
            }
            current =current->next;
        }
        return -1;
    }
    void remove( const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                size--;
                std::cout<<"Node deleted"<<std::endl;
                return;
            }
            current = current->next;
        }
        throw std::runtime_error("Element not found in the list ");
    }

    T& get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range !!!!!");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = tail = nullptr;
        size = 0;
    }
};

#endif
