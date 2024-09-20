#pragma once
#include <iostream>

// LinkedList REPL
void LinkedListInit();

/*
 * LinkedList Class
 */
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    /*
     * Creating new node given a data parameter
     */
    Node* createNode(const int data) {
        auto* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        return newNode;
    }

    // Member vars for head, tail, and size (private)
    Node* m_head;
    Node* m_tail;
    int m_size;
public:
    // Constructor
    LinkedList() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        std::cout << "(Linked List Initialized)\n" << std::endl;
    };

    // Destructor
    ~LinkedList() {
        clearList();
    };

    /*
     * Appends a new node to the end of the list given a data parameter
     */
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
    }

    /*
     * Pops the last value of the Linked List if not empty
     */
    void pop() {
        std::cout << "Popping..." << std::endl;

        if (m_size == 0) {
            std::cout << "Cannot pop from empty list\n" << std::endl;
            return;
        }

        int poppedVal;
        if (m_size == 1) {
            poppedVal = m_head->data;
            clearList();
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
    }

    /*
     * Helper function to remove the head if the head if m_size > 1
     */
    void deleteHead() {
        Node* oldHead = m_head;
        Node* newHead = m_head->next;
        newHead->prev = nullptr;
        m_head = newHead;
        delete oldHead;
        m_size--;
    }

    /*
     * Helper function to remove a Node (as long as the node is not the head)
     */
    void removeNode(Node* nodeToBeRemoved) {
        Node* newPrev = nodeToBeRemoved->prev;
        Node* newNext = nodeToBeRemoved->next;
        if (newNext != nullptr) {
            newNext->prev = newPrev;
        }
        newPrev->next = newNext;

        delete nodeToBeRemoved;
        m_size--;
    }

    /*
     * Removes a node at certain index
     */
    void removeAt(const int index) {
        if (m_size == 0) {
            std::cout << "Cannot remove from empty list\n" << std::endl;
            return;
        }

        if (index > m_size || index < 0) {
            std::cout << "Index out of bounds\n" << std::endl;
            return;
        }

        if (m_size > 1 && index == 0) {
            deleteHead();
            return;
        }

        int counter = 0;
        Node* currNode = m_head;
        while (counter <= m_size) {
            if (counter == index) {
                removeNode(currNode);
                return;
            }
            currNode = currNode->next;
            counter++;
        }
    }

    /*
     * Removes the first instance of a target value in the Linked List
     */
    void remove(const int value) {
        std::cout << "----- Removing ----\n" << value << "\n" << std::endl;
        if (m_size == 0) {
            std::cout << "Cannot remove from empty list\n" << std::endl;
            return;
        }

        if (m_size == 1) {
            if (m_head->data == value) {
                clearList();
            } else {
                std::cout << "Value not found\n" << std::endl;
            }

            return;
        }

        // If the head is the value to be removed
        if (m_head->data == value) {
            Node* oldHead = m_head;
            Node* newHead = m_head->next;
            newHead->prev = nullptr;
            m_head = newHead;
            delete oldHead;
            m_size--;

            return;
        }

        Node* currNode = m_head;
        while (currNode != nullptr) {
            if (currNode->data == value) {
                removeNode(currNode);
                return;
            }
            currNode = currNode->next;
        }
        std::cout << "Value not found\n" << std::endl;
    }

    /*
     * Helper function to visualize the Linked List
     */
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
            std::cout << "Linked List is empty!\n" << std::endl;
        }
    }

    /*
     * Helper function to clear the Linked List and deallocate memory
     */
    void clearList() {
        if (m_size == 0) {
            return;
        }

        if (m_size == 1) {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;

            return;
        }

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
};