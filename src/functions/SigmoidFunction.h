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
  double evaluate(double arg) override;

  /**
   * Computes the derivative of the Sigmoid function for
   * an already computed Sigmoid function, arg
   *
   * @param arg - The value of a Sigmoid function for a value
   * @return derivative - The value of the derivative of the Sigmoid
   * value at arg's evaluation point
   */
  double evaluateDerivative(double arg) override;

  /**
   * Get the string "Sigmoid" as the name of this activation function
   *
   * @return name - The name of this activation function
   */
  std::string getName() override;
};


#endif //CPPNN_SIGMOIDFUNCTION_H
