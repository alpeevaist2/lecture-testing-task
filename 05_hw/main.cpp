#include <iostream>

#include "stack.h"

int main() {
    Stack *stack = new Stack();
    int index = 0;

    stack->push(10);
    stack->push(20);
    stack->push(30);
    std::cout << "After pushing elements:" << std::endl;
    stack->traverseStack();

    stack->pop();
    std::cout << "After popping element:" << std::endl;
    stack->traverseStack();

    Node* searchResult = stack->searchByValue(20);
    if (searchResult != nullptr) {
        std::cout << "Element with value 20 found." << std::endl;
    } else {
        std::cout << "Element with value 20 not found." << std::endl;
    }

    Node* searchResult2 = stack->searchByValue(50);
    if (searchResult2 != nullptr) {
        std::cout << "Element with value 50 found." << std::endl;
    } else {
        std::cout << "Element with value 50 not found." << std::endl;
    }

    std::cin >> "Enter the index to search for ..." >> index >> std::endl;
    Node* searchIndex = stack->searchByIndex(index);
    if (searchIndex != nullptr) {
        std::cout << "Element with index " << index << " found. The value is: " << searchIndex->data << std::endl;
    } else {
        std::cout <<  "Element with index " << index << " not found." << std::endl;
    }

    Node* topElement = stack->getTop();
    if (topElement != nullptr) {
        std::cout << "Top element: " << topElement->data << std::endl;
    }



    delete stack;
    return 0;
}