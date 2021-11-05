/*
 * EPITECH PROJECT, 2019std::vector<IOperand *>reg1;
 * epitech, 2019
 * File description:
 *  stack.cpp
 */

#include "Memory.hh"

Memory::Memory()
{
}

void Memory::pushTopStack(IOperand *value)
{
    this->stack.push(value);
}

IOperand *Memory::getTopStack()
{
    if (stack.empty()) {
        std::cout << std::string {} + "Stack error: stack is empty\n" + __FILE__ + ":" + std::to_string(__LINE__) << '\n';
        exit(EXIT_FAILURE);
    } else {
        IOperand *op = this->stack.top();
        this->stack.pop();
        return op;
    }
}

void Memory::deleteTopStack()
{
    if (stack.empty()) {
        std::cout << std::string {} + "Stack error: stack is empty\n" + __FILE__ + ":" + std::to_string(__LINE__) << '\n';
        exit(EXIT_FAILURE);
    } else {
        delete this->stack.top();
        this->stack.pop();
    }
}

size_t Memory::getSizeStack()
{
    if (stack.empty()) {
        return 0;
    } else {
        return stack.size();
    }
}

void Memory::clear()
{
    for (size_t i = 0; i < this->stack.size(); i++)
        deleteTopStack();
}

Memory::~Memory()
{
    // Free stack
    clear();
}
