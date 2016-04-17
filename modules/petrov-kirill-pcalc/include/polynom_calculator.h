// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_
#define MODULES_PETROV_KIRILL_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_

#include <string>

#include "include/tpolynom.h"
#include "include/parse.h"

using std::string;

class PolynomCalculator {
 public:
  PolynomCalculator();
  string operator()(int argc, const char** argv);

 private:
  void help(const char* appname);

  static const int MINPOLYNOMS = 1;
  static const int MAXPOLYNOMS = 10;
  static const int NUMBERVARIABLES = 3;

  string message_;

  typedef struct {
    int numberPoly;
    TPolynom poly[MAXPOLYNOMS];
    TOperation operation;
    int idPoly[2];
    tCoeff point[NUMBERVARIABLES];
  } Arguments;
};

#endif  // MODULES_PETROV_KIRILL_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_
