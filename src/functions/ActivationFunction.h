//
// Created by jwtrueb on 8/1/17.
//

#ifndef CPPNN_ACTIVATIONFUNCTION_H
#define CPPNN_ACTIVATIONFUNCTION_H

#include <string>

class ActivationFunction {
public:
  /**
   * Performs the derived class's function on arg
   *
   * @param arg - input to the activation function
   * @return result of the activation function
   */
  virtual double evaluate(double arg) = 0;

  /**
   * Get the human readable name of the activation function
   *
   * @return name - The string name of the function
   */
  virtual std::string getName() = 0;
};


#endif //CPPNN_ACTIVATIONFUNCTION_H
