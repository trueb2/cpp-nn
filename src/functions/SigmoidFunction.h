//
// Created by jwtrueb on 8/1/17.
//

#ifndef CPPNN_SIGMOIDFUNCTION_H
#define CPPNN_SIGMOIDFUNCTION_H


#include "ActivationFunction.h"

class SigmoidFunction : public ActivationFunction {
public:
  /**
   * Calculates the result of the sigmoid function on the input arg
   *
   * @param arg - argument for the sigmoid function
   * @return [0,1] - double between 0 and 1
   */
  double evaluate(double arg);

  /**
   * Get the string "Sigmoid" as the name of this activation function
   *
   * @return name - The name of this activation function
   */
  std::string getName();
};


#endif //CPPNN_SIGMOIDFUNCTION_H
