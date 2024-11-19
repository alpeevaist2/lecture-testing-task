#include <iostream>
#include "stack.h"

void Stack::initStack()
{
    this->top = nullptr;
}
void Stack::destroyStack()
{
    Node *current = this->top;
    while (current != nullptr)
    {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
}

Stack::Stack(){
    initStack();
}
Stack::~Stack(){
    destroyStack();
}

Node *Stack::createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

bool Stack::isEmpty()
{
    return this->top == nullptr;
}

void Stack::push(int data)
{
    Node *newNode = createNode(data);
    newNode->next = this->top;
    this->top = newNode;
}

void Stack::pop()
{
    if (isEmpty()) return;
    Node *temp = this->top;
    this->top = this->top->next;
    delete temp;
}

Node *Stack::searchByValue(int value)
{
    Node *current = this->top;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Node *Stack::searchByIndex(int index)
{
    Node *current = this->top;
    for (int i = 0; current != nullptr; i++)
    {
        if (i == index)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Node *Stack::getTop()
{
    return this->top;
}

void Stack::traverseStack()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty! Please, add value to stack :( " << std::endl;
        return;
    }
    Node *current = this->top;
    std::cout << "Elements: ";
    while (current != nullptr)
    {
        std::cout << " [" << current->data << "] ";
        current = current->next;
    }
}
