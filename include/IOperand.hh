/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** IOperand
*/

#ifndef _IOPERAND_H_
#define _IOPERAND_H_

#include <string>

class IOperand {
  public:
    enum
    {
        INT8,
        INT16,
        INT32,
        FLOAT,
        DOUBLE,
        BIGDECIMAL,
        UNKNOWN,
    } typedef eOperandType;

    virtual std::string toString() const = 0;                   //  string  that  represents  theinstance
    virtual eOperandType getType() const = 0;                   //  returns  the  type of  instance
    virtual IOperand *operator+(const IOperand &rhs) const = 0; //  sum
    virtual IOperand *operator-(const IOperand &rhs) const = 0; //  difference
    virtual IOperand *operator*(const IOperand &rhs) const = 0; //  product
    virtual IOperand *operator/(const IOperand &rhs) const = 0; //  quotient
    virtual IOperand *operator%(const IOperand &rhs) const = 0; //  modulo

    virtual bool operator==(const IOperand &rhs) const = 0; //  compare
    virtual bool operator!=(const IOperand &rhs) const = 0; //  compare
    virtual bool operator>=(const IOperand &rhs) const = 0; //  compare
    virtual bool operator<=(const IOperand &rhs) const = 0; //  compare
    virtual bool operator>(const IOperand &rhs) const = 0;  //  compare
    virtual bool operator<(const IOperand &rhs) const = 0;  //  compare

    virtual ~IOperand()
    {
    }
};

#endif
