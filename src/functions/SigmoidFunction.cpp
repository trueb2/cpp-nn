//
// Created by jwtrueb on 8/1/17.
//

#include <cmath>
#include "SigmoidFunction.h"

double SigmoidFunction::evaluate(double arg) {
  return 1.0 / (1 + exp(-arg));
}

std::string SigmoidFunction::getName() {
  return "Sigmoid";
}