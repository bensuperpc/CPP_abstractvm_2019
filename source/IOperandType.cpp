
#include "IOperandType.hpp"
/* Section definitions Methodes */

template <IOperand::eOperandType T> IOperandType<T>::IOperandType()
{
}

template <IOperand::eOperandType T> IOperandType<T>::IOperandType(const std::string &str)
{
    this->value = str;
}

template <IOperand::eOperandType T> IOperand *IOperandType<T>::operator+(const IOperand &rhs) const
{
    long double data = std::stold(this->value) + std::stold(rhs.toString());
    if (this->getType() >= rhs.getType()) {
        return new IOperandType<T>(std::to_string(data));
    } else {
        return Factory::createOperand(rhs.getType(), std::to_string(data));
    }
}

template <IOperand::eOperandType T> IOperand *IOperandType<T>::operator-(const IOperand &rhs) const
{
    long double data = static_cast<long double>(std::stold(this->value) - std::stold(rhs.toString()));
    if (this->getType() >= rhs.getType()) {
        return new IOperandType<T>(std::to_string(data));
    } else {
        return Factory::createOperand(rhs.getType(), std::to_string(data));
    }
}

template <IOperand::eOperandType T> IOperand *IOperandType<T>::operator*(const IOperand &rhs) const
{
    long double data = static_cast<long double>(std::stold(this->value) * std::stold(rhs.toString()));
    if (this->getType() >= rhs.getType()) {
        return new IOperandType<T>(std::to_string(data));
    } else {
        return Factory::createOperand(rhs.getType(), std::to_string(data));
    }
}

template <IOperand::eOperandType T> IOperand *IOperandType<T>::operator/(const IOperand &rhs) const
{
    if (std::stold(rhs.toString()) == 0.0) {
        std::cout << "Math error: divide by Zero" << std::endl;
        exit(EXIT_FAILURE);
    }
    long double data = static_cast<long double>(std::stold(this->value) / std::stold(rhs.toString()));
    if (this->getType() >= rhs.getType()) {
        return new IOperandType<T>(std::to_string(data));
    } else {
        return Factory::createOperand(rhs.getType(), std::to_string(data));
    }
}

template <IOperand::eOperandType T> IOperand *IOperandType<T>::operator%(const IOperand &rhs) const
{
    if (std::stold(rhs.toString()) == 0.0) {
        std::cout << "Math error: divide by Zero" << std::endl;
        exit(EXIT_FAILURE);
    }
    long double data = static_cast<long double>(std::stoll(this->value) % std::stoll(rhs.toString()));
    if (this->getType() >= rhs.getType()) {
        return new IOperandType<T>(std::to_string(data));
    } else {
        return Factory::createOperand(rhs.getType(), std::to_string(data));
    }
}

template <IOperand::eOperandType T> bool IOperandType<T>::operator==(const IOperand &rhs) const
{
    long double &&data1 = static_cast<long double>(std::stold(rhs.toString()));
    long double &&data2 = static_cast<long double>(std::stold(this->value));
    if (data1 == data2) {
        if (this->getType() == rhs.getType()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template <IOperand::eOperandType T> bool IOperandType<T>::operator!=(const IOperand &rhs) const
{
    long double &&data1 = static_cast<long double>(std::stold(rhs.toString()));
    long double &&data2 = static_cast<long double>(std::stold(this->value));
    if (data1 != data2) {
        return true;
    } else {
        if (this->getType() != rhs.getType()) {
            return true;
        } else {
            return false;
        }
    }
}

template <IOperand::eOperandType T> bool IOperandType<T>::operator>=(const IOperand &rhs) const
{
    if (std::stold(this->value) >= std::stold(rhs.toString()))
        return true;
    else
        return false;
}

template <IOperand::eOperandType T> bool IOperandType<T>::operator<=(const IOperand &rhs) const
{
    if (std::stold(this->value) <= std::stold(rhs.toString()))
        return true;
    else
        return false;
}

template <IOperand::eOperandType T> bool IOperandType<T>::operator>(const IOperand &rhs) const
{
    if (std::stold(this->value) > std::stold(rhs.toString()))
        return true;
    else
        return false;
}

template <IOperand::eOperandType T> bool IOperandType<T>::operator<(const IOperand &rhs) const
{
    if (std::stold(this->value) < std::stold(rhs.toString()))
        return true;
    else
        return false;
}

template <IOperand::eOperandType T> IOperand::eOperandType IOperandType<T>::getType() const
{
    return T;
}

template <IOperand::eOperandType T> std::string IOperandType<T>::toString() const
{
    if (T <= IOperand::INT32) {
        return this->value.substr(0, this->value.find("."));
    }
    return this->value;
}

template <IOperand::eOperandType T> IOperandType<T>::~IOperandType()
{
}
