/*
** EPITECH PROJECT, 2019
** AbstractVM
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "Factory.hh"
#include "IOperand.hh"
#include "IOperandType.hpp"

Test(test_create_OP_and_get, test_1)
{
    std::string str = "55";
    IOperand::eOperandType expectedtype = IOperand::INT8;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    delete t1;
}

Test(test_create_OP_and_get, test_2)
{
    std::string str = "9";
    IOperand::eOperandType expectedtype = IOperand::INT16;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    delete t1;
}

Test(test_create_OP_and_get, test_3)
{
    std::string str = "65";
    IOperand::eOperandType expectedtype = IOperand::INT32;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    delete t1;
}

Test(test_create_OP_and_get, test_4)
{
    std::string str = "65.0";
    IOperand::eOperandType expectedtype = IOperand::FLOAT;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    delete t1;
}

Test(test_create_OP_and_get, test_5)
{
    std::string str = "69.6";
    IOperand::eOperandType expectedtype = IOperand::DOUBLE;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    delete t1;
}

Test(test_create_OP_and_get, test_6)
{
    std::string str = "69555545454555";
    IOperand::eOperandType expectedtype = IOperand::BIGDECIMAL;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    delete t1;
}