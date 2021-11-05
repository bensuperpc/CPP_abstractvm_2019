/*
** EPITECH PROJECT, 2019
** IA_Cpu
** File description:
** Cpu.c
*/

#include <ctype.h>
#include "Cpu.hh"

Cpu::Cpu()
{
}

Cpu::Cpu(Memory &mem)
{
    this->memory = mem;
}

Cpu::~Cpu()
{
}

Cpu::Cpu(std::string &)
{
}

/*
 * ===============================
 * =========   MEMORY    =========
 * ===============================
 */
int Cpu::swap(const std::string &str)
{
    IOperand *op1 = memory.getTopStack();
    IOperand *op2 = memory.getTopStack();
    errorNullptr(op1, op2);
    memory.pushTopStack(op1);
    memory.pushTopStack(op2);
    return 0;
}

int Cpu::push(const std::string &value)
{
    std::string &&type = getType(value);
    std::string &&num = getNum(value);

    IOperand *op1 = Factory::createOperand(type, num);
    memory.pushTopStack(op1);
    return 0;
}
int Cpu::pop(const std::string &type)
{
    memory.deleteTopStack();
    return 0;
}
int Cpu::dup(const std::string &str)
{
    IOperand *op1 = memory.getTopStack();

    IOperand *op2 = Factory::createOperand(op1->getType(), op1->toString());
    memory.pushTopStack(op1);
    memory.pushTopStack(op2);
    return 0;
}
int Cpu::clear(const std::string &str)
{
    memory.clear();
    return 0;
}

int Cpu::assert(const std::string &value)
{
    std::string &&type = getType(value);
    std::string &&num = getNum(value);
    IOperand *op2 = Factory::createOperand(type, num);

    IOperand *op1 = memory.getTopStack();

    if (*op1 != *op2) {
        std::cout << std::string {} + "Error : assert() fail !\n" + __FILE__ + ":" + std::to_string(__LINE__) << std::endl;
        exit(EXIT_FAILURE);
    }
    memory.pushTopStack(op1);
    delete op2;
    return 0;
}

int Cpu::load(const std::string &reg)
{
    std::string &&num = getNum(reg);
    size_t &&pos = static_cast<size_t>(std::stoll(num));
    IOperand *op2 = &(*this->MyIntArray[pos]);
    if (op2 == nullptr)
        std::cout << "error, register is empty" << std::endl;
    memory.pushTopStack(op2);
    return 0;
}

int Cpu::store(const std::string &reg)
{
    std::string &&num = getNum(reg);
    IOperand *op1 = memory.getTopStack();
    size_t &&pos = static_cast<size_t>(std::stoll(num));
    this->MyIntArray[pos] = op1;
    return 0;
}

/*
 * ================================
 * ========   OPERATORS    ========
 * ================================
 */
int Cpu::add(const std::string &str)
{
    if (memory.getSizeStack() < 2)
        errorLowNumOnStack();
    IOperand *op1 = memory.getTopStack();
    IOperand *op2 = memory.getTopStack();
    errorNullptr(op1, op2);
    IOperand *op3 = *op1 + *op2;
    memory.pushTopStack(op3);
    delete op1;
    delete op2;
    return 0;
}
int Cpu::sub(const std::string &str)
{
    if (memory.getSizeStack() < 2)
        errorLowNumOnStack();
    IOperand *op1 = memory.getTopStack();
    IOperand *op2 = memory.getTopStack();

    errorNullptr(op1, op2);
    IOperand *op3 = *op1 - *op2;
    memory.pushTopStack(op3);

    delete op1;
    delete op2;
    return 0;
}
int Cpu::mul(const std::string &str)
{
    if (memory.getSizeStack() < 2)
        errorLowNumOnStack();
    IOperand *op1 = memory.getTopStack();
    IOperand *op2 = memory.getTopStack();
    errorNullptr(op1, op2);
    IOperand *op3 = *op1 * *op2;
    memory.pushTopStack(op3);
    delete op1;
    delete op2;
    return 0;
}

int Cpu::div(const std::string &str)
{
    if (memory.getSizeStack() < 2)
        errorLowNumOnStack();
    IOperand *op1 = memory.getTopStack();
    IOperand *op2 = memory.getTopStack();
    errorNullptr(op1, op2);

    errorEqualZero(op2);
    IOperand *op3 = *op2 / *op1;

    memory.pushTopStack(op3);
    delete op1;
    delete op2;
    return 0;
}

int Cpu::mod(const std::string &str)
{
    if (memory.getSizeStack() < 2)
        errorLowNumOnStack();
    IOperand *op1 = memory.getTopStack();
    IOperand *op2 = memory.getTopStack();

    errorNullptr(op1, op2);
    errorEqualZero(op2);
    IOperand *op3 = *op2 % *op1;
    memory.pushTopStack(op3);
    delete op1;
    delete op2;
    return 0;
}

void Cpu::errorEqualZero(IOperand *op)
{
    if (std::stold(op->toString()) == 0.0) {
        std::cout << std::string {} + "Error : divided by Zero\n" + __FILE__ + ":" + std::to_string(__LINE__) << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Cpu::errorLowNumOnStack()
{
    std::cout << std::string {} + "Error : low number on stack < 2\n" + __FILE__ + ":" + std::to_string(__LINE__)
              << std::endl;
    exit(EXIT_FAILURE);
}

void Cpu::errorNullptr(IOperand *op1, IOperand *op2)
{
    if (op1 == nullptr || op2 == nullptr) {
        std::cout << std::string {} + "Error : nullptr\n" + __FILE__ + ":" + std::to_string(__LINE__) << std::endl;
        exit(EXIT_FAILURE);
    }
}

/*
 * ================================
 * =========   DISPLAY    =========
 * ================================
 */
int Cpu::print(const std::string &str)
{
    IOperand *op1 = memory.getTopStack();
    std::string &&strs = op1->toString();
    std::cout << strs << std::endl;
    memory.pushTopStack(op1);
    return 0;
}

int Cpu::dump(const std::string &str)
{
    std::vector<IOperand *> vect;
    vect.reserve(memory.getSizeStack());
    for (size_t i = 0; i <= memory.getSizeStack(); i++)
        vect.emplace_back(memory.getTopStack());

    for (const auto &vectf : vect) {
        std::string &&strs = vectf->toString();
        std::cout << strs << std::endl;
    }
    std::reverse(vect.begin(), vect.end());
    for (const auto &vectf : vect)
        memory.pushTopStack(vectf);
    vect.clear();
    return 0;
}

std::string Cpu::getNum(const std::string &str)
{
    size_t &&pos = str.find('(');
    size_t &&len = str.find(')');
    if (pos == std::string::npos || len == std::string::npos)
        std::cout << "Parsing error, missing '(' or ')'" << std::endl;
    return str.substr(pos + 1, len - pos - 1);
}

std::string Cpu::getType(const std::string &str)
{
    size_t &&pos = str.find("(");
    if (pos == std::string::npos)
        std::cout << "Parsing error, missing '(' or ')'" << std::endl;
    // type.erase(remove_if(type.begin(), type.end(), isspace), type.end());
    return str.substr(0, pos);
}

int Cpu::mExit(const std::string &str)
{
    return 0;
}
