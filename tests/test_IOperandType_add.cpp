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

Test(test_add, test_1)
{
    std::string str = "20";
    const std::string exp_str = "40";
    IOperand::eOperandType expectedtype = IOperand::INT8;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    IOperand *t2 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    cr_assert_eq(t2->getType(), expectedtype, "Result: %i, expected: %i", t2->getType(), expectedtype);
    cr_assert_str_eq(t2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t2->toString().c_str(), str.c_str());
    IOperand *t3 = *t1 + *t2;
    cr_assert_eq(std::stoll(t3->toString()), std::stoll(exp_str), "Result: %i, expected: %i", std::stoll(t3->toString()),
        std::stoll(exp_str));
    cr_assert_str_eq(
        t3->toString().c_str(), exp_str.c_str(), "Result: %s, expected: %s", t3->toString().c_str(), exp_str.c_str());
    delete t1;
    delete t2;
    delete t3;
}

Test(test_add, test_2)
{
    std::string str = "0";
    const std::string exp_str = "0";
    IOperand::eOperandType expectedtype = IOperand::INT8;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    IOperand *t2 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    cr_assert_eq(t2->getType(), expectedtype, "Result: %i, expected: %i", t2->getType(), expectedtype);
    cr_assert_str_eq(t2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t2->toString().c_str(), str.c_str());
    IOperand *t3 = *t1 + *t2;
    cr_assert_eq(std::stoll(t3->toString()), std::stoll(exp_str), "Result: %i, expected: %i", std::stoll(t3->toString()),
        std::stoll(exp_str));
    cr_assert_str_eq(
        t3->toString().c_str(), exp_str.c_str(), "Result: %s, expected: %s", t3->toString().c_str(), exp_str.c_str());
    delete t1;
    delete t2;
    delete t3;
}

Test(test_add, test_3)
{
    std::string str = "2000";
    const std::string exp_str = "4000";
    IOperand::eOperandType expectedtype = IOperand::INT32;
    IOperand *t1 = Factory::createOperand(expectedtype, str);
    IOperand *t2 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(t1->getType(), expectedtype, "Result: %i, expected: %i", t1->getType(), expectedtype);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    cr_assert_eq(t2->getType(), expectedtype, "Result: %i, expected: %i", t2->getType(), expectedtype);
    cr_assert_str_eq(t2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t2->toString().c_str(), str.c_str());
    IOperand *t3 = *t1 + *t2;
    cr_assert_eq(std::stoll(t3->toString()), std::stoll(exp_str), "Result: %i, expected: %i", std::stoll(t3->toString()),
        std::stoll(exp_str));
    cr_assert_str_eq(
        t3->toString().c_str(), exp_str.c_str(), "Result: %s, expected: %s", t3->toString().c_str(), exp_str.c_str());
    delete t1;
    delete t2;
    delete t3;
}

Test(test_add, test_1_diff)
{
    std::string str = "2000";
    const std::string exp_str = "4000";
    IOperand::eOperandType expectedtype1 = IOperand::INT32;
    IOperand::eOperandType expectedtype2 = IOperand::INT16;
    IOperand *t1 = Factory::createOperand(expectedtype1, str);
    IOperand *t2 = Factory::createOperand(expectedtype2, str);
    cr_assert_eq(t1->getType(), expectedtype1, "Result: %i, expected: %i", t1->getType(), expectedtype1);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    cr_assert_eq(t2->getType(), expectedtype2, "Result: %i, expected: %i", t2->getType(), expectedtype2);
    cr_assert_str_eq(t2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t2->toString().c_str(), str.c_str());
    IOperand *t3 = *t1 + *t2;
    cr_assert_eq(std::stoll(t3->toString()), std::stoll(exp_str), "Result: %i, expected: %i", std::stoll(t3->toString()),
        std::stoll(exp_str));
    cr_assert_str_eq(
        t3->toString().c_str(), exp_str.c_str(), "Result: %s, expected: %s", t3->toString().c_str(), exp_str.c_str());
    cr_assert_eq(t3->getType(), expectedtype1, "Result: %i, expected: %i", t3->getType(), expectedtype1);
    delete t1;
    delete t2;
    delete t3;
}

Test(test_add, test_2_diff)
{

    std::string str = "20";
    const std::string exp_str = "40";
    IOperand::eOperandType expectedtype1 = IOperand::INT32;
    IOperand::eOperandType expectedtype2 = IOperand::INT16;
    IOperand *t1 = Factory::createOperand(expectedtype1, str);
    IOperand *t2 = Factory::createOperand(expectedtype2, str);
    cr_assert_eq(t1->getType(), expectedtype1, "Result: %i, expected: %i", t1->getType(), expectedtype1);
    cr_assert_str_eq(t1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t1->toString().c_str(), str.c_str());
    cr_assert_eq(t2->getType(), expectedtype2, "Result: %i, expected: %i", t2->getType(), expectedtype2);
    cr_assert_str_eq(t2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", t2->toString().c_str(), str.c_str());
    IOperand *t3 = *t2 + *t1;

    cr_assert_eq(std::stoll(t3->toString()), std::stoll(exp_str), "Result: %i, expected: %i", std::stoll(t3->toString()),
        std::stoll(exp_str));
    cr_assert_str_eq(
        t3->toString().c_str(), exp_str.c_str(), "Result: %s, expected: %s", t3->toString().c_str(), exp_str.c_str());
    cr_assert_eq(t3->getType(), expectedtype1, "Result: %i, expected: %i", t3->getType(), expectedtype1);
    delete t1;
    delete t2;
    delete t3;
}