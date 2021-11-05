/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** Factory
*/

#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <vector>
#include "IOperand.hh"
#include "IOperandType.hpp"

class Factory {
  public:
    static IOperand *createOperand(IOperand::eOperandType type, const std::string &value);
    static IOperand *createOperand(const std::string &, const std::string &);

  private:
    static IOperand *createInt8(const std::string &value);
    static IOperand *createInt16(const std::string &value);
    static IOperand *createInt32(const std::string &value);
    static IOperand *createFloat(const std::string &value);
    static IOperand *createDouble(const std::string &value);
    static IOperand *createBigDecimal(const std::string &value);
    static IOperand *unknownElement(const std::string &value);

    typedef std::map<std::string_view, IOperand::eOperandType> map_op;
    static std::map<std::string_view, IOperand::eOperandType> map_op_;
    typedef std::map<IOperand::eOperandType, IOperand *(*)(const std::string &)> function_map;
    static std::map<IOperand::eOperandType, IOperand *(*)(const std::string &)> function_map_;
};

#endif
