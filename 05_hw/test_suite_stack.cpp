#include <gtest/gtest.h>
#include "stack.h"

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new Stack();
    }

    void TearDown() override {
        delete stack;
    }

    Stack* stack;
};

TEST_F(StackTest, IsEmptySuccess) {
    EXPECT_EQ(stack->isEmpty(),true);
}

TEST_F(StackTest, IsEmptyFail) {
    stack->push(100);
    EXPECT_EQ(stack->isEmpty(),false);
}

TEST_F(StackTest, GetTopEmpty) {
    Node *result = stack->getTop();
    EXPECT_EQ(result, nullptr);
}

TEST_F(StackTest, Push) {
    stack->push(1);
    Node *result = stack->getTop();
    EXPECT_EQ(result->data,1);
}

TEST_F(StackTest, Pop) {
    stack->push(2);
    stack->pop();
    EXPECT_EQ(stack->isEmpty(),true);
}

TEST_F(StackTest, PopFromEmptyStack) {
    stack->pop();
    EXPECT_EQ(stack->isEmpty(),true);
}

TEST_F(StackTest, GetTop) {
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    stack->pop();
    Node *result = stack->getTop();
    EXPECT_EQ(result->data,100);
}

TEST_F(StackTest, SearchByValueSuccess) {
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    Node *result = stack->searchByValue(25);
    EXPECT_EQ(result->data,25);
}

TEST_F(StackTest, SearchByValueFail) {
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    Node *result = stack->searchByValue(10);
    EXPECT_EQ(result,nullptr);
}

TEST_F(StackTest, SearchByIndexSuccess) {
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    Node * result = stack->searchByIndex(0);
    EXPECT_EQ(result->data,100);
}

TEST_F(StackTest, SearchByIndexFail1) {
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    Node *result = stack->searchByIndex(5);
    EXPECT_EQ(result,nullptr);
}

TEST_F(StackTest, SearchByIndexFail2) {
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    Node *result = stack->searchByIndex(-1);
    EXPECT_EQ(result,nullptr);
}

TEST_F(StackTest, TraverseStack) {
    testing::internal::CaptureStdout();
    stack->push(100);
    stack->push(75);
    stack->push(50);
    stack->push(25);
    stack->traverseStack();
    std::string captured_stdout = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Elements:  [100] [75] [50] [25] \n", captured_stdout);
}

TEST_F(StackTest, TraverseStackEmpty) {
    testing::internal::CaptureStdout();
    stack->traverseStack();
    std::string captured_stdout = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Stack is empty! Please, add value to stack :( \n", captured_stdout);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}