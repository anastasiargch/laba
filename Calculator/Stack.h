#pragma once
#include <iostream>

template<typename T>
class Stack {
private:
    T* stackBase = new T[0];
    int size = 0;

public:
    friend Stack<T>& operator<<(Stack<T>& stack, T el);
    friend void operator>>(Stack<T>& stack, T& el);
    friend bool operator<(Stack<T>& stack, Stack<T>& stack1);
    friend bool operator>(Stack<T>& stack, Stack<T>& stack1);
    friend bool operator==(Stack<T>& stack, Stack<T>& stack1);
    Stack<T>& operator=(Stack<T>& stack);
    T operator[](int i);

    int getSize();

    T top();
    T pop();

    void push(T value);
    void print(std::ostream& out);
    bool isEmpty();
    void resize();

    ~Stack();
};
