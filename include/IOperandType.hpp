/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** >define
*/

#ifndef _IOPERANDTYPE_H_
#define _IOPERANDTYPE_H_

/* Section declarations Methodes */

#include <stdexcept>
#include "Factory.hh"
#include "IOperand.hh"

class Factory;

template <IOperand::eOperandType T> class IOperandType : public IOperand {
  public:
    IOperandType();
    IOperandType(const std::string &);
    ~IOperandType();
    IOperand *operator+(const IOperand &rhs) const override;
    IOperand *operator-(const IOperand &rhs) const override;
    IOperand *operator*(const IOperand &rhs) const override;
    IOperand *operator/(const IOperand &rhs) const override;
    IOperand *operator%(const IOperand &rhs) const override;

    bool operator==(const IOperand &rhs) const override;
    bool operator!=(const IOperand &rhs) const override;
    bool operator>(const IOperand &rhs) const override;
    bool operator<(const IOperand &rhs) const override;
    bool operator>=(const IOperand &rhs) const override;
    bool operator<=(const IOperand &rhs) const override;

    IOperand::eOperandType getType() const override;
    std::string toString() const override;

  private:
    std::string value = "";
};

template class IOperandType<IOperand::INT8>;
template class IOperandType<IOperand::INT16>;
template class IOperandType<IOperand::INT32>;
template class IOperandType<IOperand::FLOAT>;
template class IOperandType<IOperand::DOUBLE>;
template class IOperandType<IOperand::BIGDECIMAL>;
template class IOperandType<IOperand::UNKNOWN>;

#endif
