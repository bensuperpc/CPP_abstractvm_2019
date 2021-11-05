/*
 * EPITECH PROJECT, 2019
 * epitech, 2019
 * File description:
 *  stack.hh
 */
#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <iostream>
#include <stack>
#include <vector>
#include "IOperand.hh"

class Memory {
  public:
    Memory();
    void pushTopStack(IOperand *value);
    IOperand *getTopStack();
    void deleteTopStack();
    size_t getSizeStack();
    void clear();
    ~Memory();

  private:
    std::stack<IOperand *> stack;
};

#endif