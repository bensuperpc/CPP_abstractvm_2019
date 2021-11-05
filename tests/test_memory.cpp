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
#include "Memory.hh"

Test(test_memory, test_1)
{
    Memory sdcard;

    IOperand *t1 = Factory::createOperand(IOperand::INT32, "5");
    IOperand *t2 = Factory::createOperand(IOperand::INT8, "6");

    IOperand *t31;
    cr_assert_eq(sdcard.getSizeStack(), 0, "Result: %s, expected: %s", sdcard.getSizeStack(), 0);
    sdcard.pushTopStack(t1);
    cr_assert_eq(sdcard.getSizeStack(), 1, "Result: %s, expected: %s", sdcard.getSizeStack(), 1);
    sdcard.pushTopStack(t2);
    cr_assert_eq(sdcard.getSizeStack(), 2, "Result: %s, expected: %s", sdcard.getSizeStack(), 2);

    sdcard.deleteTopStack();
    cr_assert_eq(sdcard.getSizeStack(), 1, "Result: %s, expected: %s", sdcard.getSizeStack(), 1);

    t31 = sdcard.getTopStack();
    cr_assert_eq(sdcard.getSizeStack(), 0, "Result: %s, expected: %s", sdcard.getSizeStack(), 0);
    cr_assert_str_eq(t31->toString().c_str(), "5", "Result: %s, expected: %s", t31->toString().c_str(), "5");

    delete t31;
    cr_assert_eq(sdcard.getSizeStack(), 0, "Result: %s, expected: %s", sdcard.getSizeStack(), 0);
}