/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
**  Cpu.hpp
*/

#ifndef _CPU_H_
#define _CPU_H_

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "Factory.hh"
#include "IOperand.hh"
#include "IOperandType.hpp"
#include "Memory.hh"

class Cpu {
  public:
    // Variables
    Memory memory;

    // Methodes

    // Memory
    int dup(const std::string &);
    int push(const std::string &);
    int pop(const std::string &);
    int clear(const std::string &);
    int swap(const std::string &);
    int load(const std::string &);
    int store(const std::string &);

    int assert(const std::string &);

    // Operators
    int sub(const std::string &);
    int mul(const std::string &);
    int div(const std::string &);
    int add(const std::string &);
    int mod(const std::string &);
    // Display
    int print(const std::string &);
    int dump(const std::string &);
    int mExit(const std::string &);
    // Constructeurs
    std::string getNum(const std::string &str);
    std::string getType(const std::string &str);

    // Errors
    void errorEqualZero(IOperand *);
    void errorLowNumOnStack();
    void errorNullptr(IOperand *, IOperand *);

    Cpu(std::string &);
    Cpu(Memory &mem);
    Cpu();
    // Destructeurs
    ~Cpu();

  private:
    std::array<IOperand *, 16> MyIntArray;
};

#endif
