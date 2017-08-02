//
// Created by jwtrueb on 8/1/17.
//

#include "InputNeuron.h"

InputNeuron::InputNeuron(double * inputValues, int length): Neuron(length) {
  setWeights(inputValues, length);
}

InputNeuron::~InputNeuron() {
  delete[] weights;
}

double *InputNeuron::copyWeights() {
  double* weights1 = new double[length];
  for(int i = 0; i < length; i++) {
    weights1[i] = weights[i];
  }
  return weights1;
}
