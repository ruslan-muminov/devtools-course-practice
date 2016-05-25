// Copyright 2016 Sharadze Georgy

#include "include/specific_number.h"
#include <string>

SpecificNumber::SpecificNumber(const TNumbers _mode, const int _value) {
    setMode(_mode);
    setIntValue(_value);
}

SpecificNumber::SpecificNumber(const SpecificNumber & _sNum) {
    setMode(_sNum.getMode());
    setIntValue(_sNum.getIntValue());
}

SpecificNumber SpecificNumber::operator+(const SpecificNumber & _sNum) const {
    SpecificNumber result;
    if (getMode() != _sNum.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    } else {
        result.setIntValue(getIntValue() + _sNum.getIntValue());
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator-(const SpecificNumber & _sNum) const {
    SpecificNumber result;
    if (getMode() != _sNum.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    } else {
        result.setIntValue(getIntValue() - _sNum.getIntValue());
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator*(const SpecificNumber & _sNum) const {
    SpecificNumber result;
    if (getMode() != _sNum.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    } else {
        result.setIntValue(getIntValue() * _sNum.getIntValue());
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator/(const SpecificNumber & _sNum) const {
    SpecificNumber result;
    if (getMode() != _sNum.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    } else if (_sNum.equalsZero()) {
        throw std::string("Can\'t divide with zero \n ");
    } else {
        result.setIntValue(static_cast<int>(getIntValue() / _sNum.getIntValue()));
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator=(const SpecificNumber & _sNum) {
    setIntValue(_sNum.getIntValue());
    setMode(_sNum.getMode());
    return *this;
}

bool SpecificNumber::operator == (const SpecificNumber & _sNum) const {
    return (getMode() == _sNum.getMode() &&
        getIntValue() == _sNum.getIntValue());
}

bool SpecificNumber::operator != (const SpecificNumber & _sNum) const {
    return !(*this == _sNum);
}

int SpecificNumber::getIntValue() const {
    return value;
}

TNumbers SpecificNumber::getMode() const {
    return mode;
}

void SpecificNumber::setIntValue(const int _value) {
    value = _value;
}

void SpecificNumber::setMode(const TNumbers _mode) {
    mode = _mode;
}

std::string SpecificNumber::showNum() const {
    unsigned int basis = 0;
    std::string str = "";

    if (equalsZero()) {
        str = "0";
    }

    switch (mode) {
    case TNumbers::HEX:
        basis = 16;
        break;
    case TNumbers::BIN:
        basis = 2;
        break;
    case TNumbers::OCT:
        basis = 8;
        break;
    }

    int tmp = value;
    bool lessZero = false;

    if (value < 0) {
        tmp = -tmp;
        lessZero = true;
    }

    while (tmp > 0) {
        if (tmp % basis == 10) {
            str = "A" + str;
        } else if (tmp % basis == 11) {
            str = "B" + str;
        } else if (tmp % basis == 12) {
            str = "C" + str;
        } else if (tmp % basis == 13) {
            str = "D" + str;
        } else if (tmp % basis == 14) {
            str = "E" + str;
        } else if (tmp % basis == 15) {
            str = "F" + str;
        } else {
            str = std::to_string(tmp % basis) + str;
        }
        tmp = static_cast<int>(tmp / basis);
    }

    if (lessZero) {
        str = "-" + str;
    }

    return str;
}

bool SpecificNumber::equalsZero() const {
    return value == 0;
}

SpecificNumber calc(const SpecificNumber & _SpecificNumber1,
                    const SpecificNumber & _SpecificNumber2,
                    const char operation) {
    SpecificNumber result;
    switch (operation) {
    case '+':
        result = _SpecificNumber1 + _SpecificNumber2;
        break;
    case '-':
        result = _SpecificNumber1 - _SpecificNumber2;
        break;
    case '*':
        result = _SpecificNumber1 * _SpecificNumber2;
        break;
    case '/':
        result = _SpecificNumber1 / _SpecificNumber2;
        break;
    default:
        throw std::string("Wrong operation format \n ");
    }
    return result;
}

void SpecificNumber::setValue(std::string _number, TNumbers _mode) {
    int result = 0;
    unsigned int basis;

    switch (_mode)
    {
    case TNumbers::HEX:
        for each(char n in _number) {
            if ((n < '0' || n > '9') && (n < 'A' || n > 'E')) {
                throw std::string("Wrong HEX-number format \n ");
                return;
            }
        }
        basis = 16;
        break;
    case TNumbers::OCT:
        for each(char n in _number) {
            if (n < '0' || n > '8') {
                throw std::string("Wrong OCT-number format \n ");
                return;
            }
        }
        basis = 8;
        break;
    case TNumbers::BIN:
        for each(char n in _number) {
            if (n < '0' || n > '1') {
                throw std::string("Wrong BIN-number format \n ");
                return;
            }
        }
        basis = 2;
        break;
    }

    switch (_mode) {
    case TNumbers::HEX:
        break;
    case TNumbers::BIN:
        unsigned int size = sizeof(_number);
        for (unsigned int i = 0; i < sizeof(_number); i++) {
            result += (int)_number[i];
            result *= basis;
        }
        break;
    case TNumbers::OCT:
        break;
    }

    setIntValue(result);
}
