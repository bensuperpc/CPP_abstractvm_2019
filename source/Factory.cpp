/*
** EPITECH PROJECT, 2019
** CPP
** File description:
** Factory.cpp
*/

#include "Factory.hh"

IOperand *Factory::createOperand(IOperand::eOperandType type, const std::string &value)
{
    return (Factory::function_map_.at(type))(value);
}

IOperand *Factory::createOperand(const std::string &type, const std::string &value)
{
    const auto &&iter = Factory::map_op_.find(type);
    if (iter == Factory::map_op_.end()) {
        return nullptr;
    }
    return Factory::createOperand(iter->second, value);
}

IOperand *Factory::createInt8(const std::string &value)
{
    if (std::stold(value) > 127.0)
        throw std::overflow_error("overflow_error\n");
    if (std::stold(value) < -127.0)
        throw std::underflow_error("underflow_error\n");
    return new IOperandType<IOperand::INT8>(value);
}

IOperand *Factory::createInt16(const std::string &value)
{
    if (std::stold(value) > 32767.0)
        throw std::overflow_error("overflow_error\n");
    if (std::stold(value) < -32767.0)
        throw std::underflow_error("underflow_error\n");
    return new IOperandType<IOperand::INT16>(value);
}

IOperand *Factory::createInt32(const std::string &value)
{
    if (std::stold(value) > 2147483647.0)
        throw std::overflow_error("overflow_error\n");
    if (std::stold(value) < -2147483647.0)
        throw std::underflow_error("underflow_error\n");
    return new IOperandType<IOperand::INT32>(value);
}

IOperand *Factory::createFloat(const std::string &value)
{
    if (std::stold(value) > 2147483647.0)
        throw std::overflow_error("overflow_error\n");
    if (std::stold(value) < -2147483647.0)
        throw std::underflow_error("underflow_error\n");
    return new IOperandType<IOperand::FLOAT>(value);
}

IOperand *Factory::createDouble(const std::string &value)
{
    if (std::stold(value) > 9223372036854775806.0)
        throw std::overflow_error("overflow_error\n");
    if (std::stold(value) < -9223372036854775806.0)
        throw std::underflow_error("underflow_error\n");
    return new IOperandType<IOperand::DOUBLE>(value);
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
    return new IOperandType<IOperand::BIGDECIMAL>(value);
}

IOperand *Factory::unknownElement(const std::string &value)
{
    return nullptr;
}

Factory::function_map Factory::function_map_ = {{IOperand::INT8, &Factory::createInt8},
    {IOperand::INT16, &Factory::createInt16}, {IOperand::INT32, &Factory::createInt32},
    {IOperand::FLOAT, &Factory::createFloat}, {IOperand::DOUBLE, &Factory::createDouble},
    {IOperand::BIGDECIMAL, &Factory::createBigDecimal}, {IOperand::UNKNOWN, &Factory::unknownElement}};

Factory::map_op Factory::map_op_ = {{"int8", IOperand::INT8}, {"int16", IOperand::INT16}, {"int32", IOperand::INT32},
    {"float", IOperand::FLOAT}, {"double", IOperand::DOUBLE}};