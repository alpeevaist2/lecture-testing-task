#pragma once

#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

//The Stack class stores data about the stack, as well as methods for working with the stack.
class Stack{
    private:
        Node* top;
        Node* createNode(int data);
        void initStack();
        void destroyStack();
    public:
        void push(int data);
        void pop();
        Node *searchByValue(int value);
        Node *searchByIndex(int index);
        Node *getTop();
        void traverseStack();
        bool isEmpty();
        Stack();
        ~Stack();
};
#endif
