#pragma once
#include <iostream>

void LinkedListInit();

class LinkedList {
public:
    LinkedList() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        std::cout << "Initialized empty linked list" << std::endl;
    };

    ~LinkedList() {
        clearList();
    };

    void append(const int data) {
        Node* newNode = createNode(data);
        if (m_head == nullptr && m_tail == nullptr) {
            m_head = newNode;
            m_tail = newNode;
        } else if (m_head != nullptr && m_tail != nullptr && m_head == m_tail) {
            newNode->prev = m_head;
            m_head->next = newNode;
            m_tail = newNode;
        } else if (m_head != nullptr && m_tail != nullptr) {
            Node* oldTail = m_tail;
            oldTail->next = newNode;
            m_tail = newNode;
            m_tail->prev = oldTail;
        }
        m_size++;
        printList();
    }

    void pop() {
        std::cout << "Popping..." << std::endl;

        if (m_size == 0) {
            std::cout << "Cannot pop from empty list" << std::endl;
            return;
        }

        int poppedVal;
        if (m_size == 1) {
            poppedVal = m_head->data;

            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        } else {
            poppedVal = m_tail->data;
            Node* oldTail = m_tail;
            Node* newTail = m_tail->prev;
            newTail->next = nullptr;
            m_tail = newTail;

            delete oldTail;
        }

        m_size--;
        std::cout << "Popped Value: " << poppedVal << "\n" << std::endl;
        printList();
    }

    void remove(const int value) {
        std::cout << "Removing " << value << "..." << std::endl;
    }

    void printList() {
        if (m_size >= 1) {
            std::cout << "Linked List: (size = " << m_size << ")" << std::endl;
            Node* currNode = m_head;
            while (currNode->next != nullptr) {
                std::cout << currNode->data << " -> ";
                currNode = currNode->next;
            }
            std::cout << currNode->data << "\n" << std::endl;
        } else {
            std::cout << "Linked List is empty!" << std::endl;
        }
    }

    void clearList() {
        Node* currNode = m_head;
        while (currNode != nullptr) {
            Node* next = currNode->next;
            delete currNode;
            currNode = next;
            m_size--;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* createNode(const int data) {
        auto* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        std::cout << "\n----- Creating new node ------\n" << newNode->data << "\n\n" << std::endl;
        return newNode;
    }

    Node* m_head;
    Node* m_tail;
    int m_size;
};