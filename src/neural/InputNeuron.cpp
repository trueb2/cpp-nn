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
