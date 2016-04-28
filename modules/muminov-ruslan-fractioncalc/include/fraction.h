// Copyright 2016 Muminov_Ruslan

#ifndef MODULES_FRACTIONCALC_INCLUDE_FRACTION_H_
#define MODULES_FRACTIONCALC_INCLUDE_FRACTION_H_

class fraction {
 public:
    fraction();
    fraction(const int numerator, const int denominator);
    fraction(const fraction& z);

    fraction& operator=(const fraction& z);

    int getNum() const;
    int getDenom() const;
    void setNum(const int numerator);
    void setDenom(const int denominator);

    fraction operator + (const fraction& z) const;
    fraction operator - (const fraction& z) const;
    fraction operator * (const fraction& z) const;
    fraction operator / (const fraction& z) const;

    bool operator == (const fraction& z) const;
    bool operator != (const fraction& z) const;

 private:
    bool equalsZero(const fraction& z) const;
    int NOD() const;
    void reduction();
    int numerator_;
    int denominator_;
};

#endif  // MODULES_FRACTIONCALC_INCLUDE_FRACTION_H_