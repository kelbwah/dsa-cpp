#include "LinkedList.hpp"

void LinkedListInit() {
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.pop();
    list.pop();
    list.pop();
    list.pop();
    list.pop();
}