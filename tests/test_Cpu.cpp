/*
** EPITECH PROJECT, 2019
** AbstractVM
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Cpu.hh"
#include "Factory.hh"
#include "IOperand.hh"
#include "IOperandType.hpp"

void redirect_all_stdout(void);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_Cpu, test_1_add, .init = redirect_all_stdout)
{
    Memory memory;
    std::string str = "55";
    IOperand::eOperandType expectedtype = IOperand::INT8;
    IOperand *stack_val1 = Factory::createOperand(expectedtype, str);
    IOperand *stack_val2 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(stack_val1->getType(), expectedtype, "Result: %i, expected: %i", stack_val1->getType(), expectedtype);
    cr_assert_str_eq(stack_val1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val1->toString().c_str(),
        str.c_str());
    cr_assert_eq(stack_val2->getType(), expectedtype, "Result: %i, expected: %i", stack_val2->getType(), expectedtype);
    cr_assert_str_eq(stack_val2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val2->toString().c_str(),
        str.c_str());

    memory.pushTopStack(stack_val2);
    memory.pushTopStack(stack_val1);
    cr_assert_eq(memory.getSizeStack(), 2, "Result: %i, expected: %i", memory.getSizeStack(), 2);

    Cpu cpu(memory);

    IOperand *stack_val3 = memory.getTopStack();
    IOperand *stack_val4 = memory.getTopStack();

    cr_assert_eq(memory.getSizeStack(), 0, "Result: %i, expected: %i", memory.getSizeStack(), 0);

    IOperand *stack_val5 = *stack_val3 + *stack_val4;
    str = "110";
    cr_assert_eq(stack_val5->getType(), expectedtype, "Result: %i, expected: %i", stack_val5->getType(), expectedtype);
    cr_assert_str_eq(stack_val5->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val5->toString().c_str(),
        str.c_str());

    std::string useless = "";
    cpu.add(useless);
    // cpu.dump(useless);
    // cr_assert_stdout_eq_str("110.000000\n", "");

    cpu.clear(useless);
    delete stack_val5;
}

Test(test_Cpu, test_2_add, .init = redirect_all_stdout)
{
    Memory memory;
    std::string str = "2.6";
    IOperand::eOperandType expectedtype = IOperand::DOUBLE;
    IOperand *stack_val1 = Factory::createOperand(expectedtype, str);
    IOperand *stack_val2 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(stack_val1->getType(), expectedtype, "Result: %i, expected: %i", stack_val1->getType(), expectedtype);
    cr_assert_str_eq(stack_val1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val1->toString().c_str(),
        str.c_str());
    cr_assert_eq(stack_val2->getType(), expectedtype, "Result: %i, expected: %i", stack_val2->getType(), expectedtype);
    cr_assert_str_eq(stack_val2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val2->toString().c_str(),
        str.c_str());

    memory.pushTopStack(stack_val2);
    memory.pushTopStack(stack_val1);
    cr_assert_eq(memory.getSizeStack(), 2, "Result: %i, expected: %i", memory.getSizeStack(), 2);

    Cpu cpu(memory);

    IOperand *stack_val3 = memory.getTopStack();
    IOperand *stack_val4 = memory.getTopStack();

    cr_assert_eq(memory.getSizeStack(), 0, "Result: %i, expected: %i", memory.getSizeStack(), 0);

    IOperand *stack_val5 = *stack_val3 + *stack_val4;
    str = "5.200000";
    cr_assert_eq(stack_val5->getType(), expectedtype, "Result: %i, expected: %i", stack_val5->getType(), expectedtype);
    cr_assert_str_eq(stack_val5->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val5->toString().c_str(),
        str.c_str());

    std::string useless = "";

    // cpu.add(useless);
    // cpu.dump(useless);

    // cr_assert_stdout_eq_str("5.200000\n", "");

    cpu.clear(useless);
    delete stack_val5;
}

Test(test_Cpu, test_1_mult, .init = redirect_all_stdout)
{
    Memory memory;
    std::string str = "2.6";
    IOperand::eOperandType expectedtype = IOperand::DOUBLE;
    IOperand *stack_val1 = Factory::createOperand(expectedtype, str);
    IOperand *stack_val2 = Factory::createOperand(expectedtype, str);
    cr_assert_eq(stack_val1->getType(), expectedtype, "Result: %i, expected: %i", stack_val1->getType(), expectedtype);
    cr_assert_str_eq(stack_val1->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val1->toString().c_str(),
        str.c_str());
    cr_assert_eq(stack_val2->getType(), expectedtype, "Result: %i, expected: %i", stack_val2->getType(), expectedtype);
    cr_assert_str_eq(stack_val2->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val2->toString().c_str(),
        str.c_str());

    memory.pushTopStack(stack_val2);
    memory.pushTopStack(stack_val1);
    cr_assert_eq(memory.getSizeStack(), 2, "Result: %i, expected: %i", memory.getSizeStack(), 2);

    Cpu cpu(memory);

    IOperand *stack_val3 = memory.getTopStack();
    IOperand *stack_val4 = memory.getTopStack();

    cr_assert_eq(memory.getSizeStack(), 0, "Result: %i, expected: %i", memory.getSizeStack(), 0);

    IOperand *stack_val5 = *stack_val3 * *stack_val4;
    str = "6.760000";
    cr_assert_eq(stack_val5->getType(), expectedtype, "Result: %i, expected: %i", stack_val5->getType(), expectedtype);
    cr_assert_str_eq(stack_val5->toString().c_str(), str.c_str(), "Result: %s, expected: %s", stack_val5->toString().c_str(),
        str.c_str());

    std::string useless = "";
    cpu.mul(useless);
    // cpu.dump(useless);
    // cr_assert_stdout_eq_str("6.760000\n", "");

    cpu.clear(useless);
    delete stack_val5;
}

Test(test_Cpu, test_2_mult, .init = redirect_all_stdout)
{
    Memory memory;
    std::string str1 = "16.5";
    std::string str2 = "16.5";
    std::string res = "272.250000";
    IOperand::eOperandType expectedtype = IOperand::DOUBLE;
    IOperand *stack_val1 = Factory::createOperand(expectedtype, str1);
    IOperand *stack_val2 = Factory::createOperand(expectedtype, str2);
    cr_assert_eq(stack_val1->getType(), expectedtype, "Result: %i, expected: %i", stack_val1->getType(), expectedtype);
    cr_assert_str_eq(stack_val1->toString().c_str(), str1.c_str(), "Result: %s, expected: %s",
        stack_val1->toString().c_str(), str1.c_str());
    cr_assert_eq(stack_val2->getType(), expectedtype, "Result: %i, expected: %i", stack_val2->getType(), expectedtype);
    cr_assert_str_eq(stack_val2->toString().c_str(), str2.c_str(), "Result: %s, expected: %s",
        stack_val2->toString().c_str(), str2.c_str());

    memory.pushTopStack(stack_val2);
    memory.pushTopStack(stack_val1);
    cr_assert_eq(memory.getSizeStack(), 2, "Result: %i, expected: %i", memory.getSizeStack(), 2);

    Cpu cpu(memory);

    IOperand *stack_val3 = memory.getTopStack();
    IOperand *stack_val4 = memory.getTopStack();

    cr_assert_eq(memory.getSizeStack(), 0, "Result: %i, expected: %i", memory.getSizeStack(), 0);

    IOperand *stack_val5 = *stack_val3 * *stack_val4;
    cr_assert_eq(stack_val5->getType(), expectedtype, "Result: %i, expected: %i", stack_val5->getType(), expectedtype);
    cr_assert_str_eq(stack_val5->toString().c_str(), res.c_str(), "Result: %s, expected: %s", stack_val5->toString().c_str(),
        res.c_str());

    std::string useless = "";
    cpu.mul(useless);
    // cpu.dump(useless);
    // cr_assert_stdout_eq_str("272.250000\n", "");

    cpu.clear(useless);
    delete stack_val5;
}

Test(test_Cpu, test_3_mult, .init = redirect_all_stdout)
{
    Memory memory;
    std::string str1 = "16.5";
    std::string str2 = "2.0";
    std::string res = "33.000000";
    IOperand::eOperandType expectedtype = IOperand::DOUBLE;
    IOperand *stack_val1 = Factory::createOperand(expectedtype, str1);
    IOperand *stack_val2 = Factory::createOperand(expectedtype, str2);
    cr_assert_eq(stack_val1->getType(), expectedtype, "Result: %i, expected: %i", stack_val1->getType(), expectedtype);
    cr_assert_str_eq(stack_val1->toString().c_str(), str1.c_str(), "Result: %s, expected: %s",
        stack_val1->toString().c_str(), str1.c_str());
    cr_assert_eq(stack_val2->getType(), expectedtype, "Result: %i, expected: %i", stack_val2->getType(), expectedtype);
    cr_assert_str_eq(stack_val2->toString().c_str(), str2.c_str(), "Result: %s, expected: %s",
        stack_val2->toString().c_str(), str2.c_str());

    memory.pushTopStack(stack_val2);
    memory.pushTopStack(stack_val1);
    cr_assert_eq(memory.getSizeStack(), 2, "Result: %i, expected: %i", memory.getSizeStack(), 2);

    Cpu cpu(memory);

    IOperand *stack_val3 = memory.getTopStack();
    IOperand *stack_val4 = memory.getTopStack();

    cr_assert_eq(memory.getSizeStack(), 0, "Result: %i, expected: %i", memory.getSizeStack(), 0);

    IOperand *stack_val5 = *stack_val3 * *stack_val4;
    cr_assert_eq(stack_val5->getType(), expectedtype, "Result: %i, expected: %i", stack_val5->getType(), expectedtype);
    cr_assert_str_eq(stack_val5->toString().c_str(), res.c_str(), "Result: %s, expected: %s", stack_val5->toString().c_str(),
        res.c_str());

    std::string useless = "";

    cpu.mul(useless);

    // cpu.dump(useless);

    // cr_assert_stdout_eq_str((res + "\n").c_str(), "");

    cpu.clear(useless);
    delete stack_val5;
}