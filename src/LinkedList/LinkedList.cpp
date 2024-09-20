#include "LinkedList.hpp"
#include <iostream>
#include <string>

void PrintREPLUsage() {
    std::cout << "----- Commands List -----" << std::endl;
    std::cout << "(1) Append to list" << std::endl;
    std::cout << "(2) Remove first occurrence of value from list" << std::endl;
    std::cout << "(3) Remove [i]th element from list" << std::endl;
    std::cout << "(4) Pop from list" << std::endl;
    std::cout << "(5) Print list" << std::endl;
    std::cout << "(6) Clear list" << std::endl;
    std::cout << "(7) Exit" << std::endl;
    std::cout << "\nYour choice: ";
}

int GetUserInput(const std::string& message) {
    int value;
    std::cout << message;
    std::cin >> value;
    std::cout << std::endl;
    return value;
}

void LinkedListInit() {
    LinkedList list;

    bool isRunning = true;
    while (isRunning) {
        int input;
        PrintREPLUsage();
        std::cin >> input;
        std::cout << std::endl;
        std::string message;
        int userInputVal;
        switch (input) {
            case 1:
                message = "Enter a value to append to list: ";
                userInputVal = GetUserInput(message);
                list.append(userInputVal);
                break;
            case 2:
                message = "Enter a value to remove from the list: ";
                userInputVal = GetUserInput(message);
                list.remove(userInputVal);
                break;
            case 3:
                message = "Enter an index to remove from the list: ";
                userInputVal = GetUserInput(message);
                list.removeAt(userInputVal);
                break;
            case 4:
                list.pop();
                break;
            case 5:
                list.printList();
                break;
            case 6:
                list.clearList();
                break;
            case 7:
                isRunning = false;
                list.clearList();
                break;
            default:
                std::cout << "Invalid input, review usage." << std::endl;
                break;
        }
    }
}