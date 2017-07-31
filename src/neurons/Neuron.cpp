//
// Created by jwtrueb on 7/31/17.
//

#include "Neuron.h"

Neuron::Neuron(int length): length(length) {
  weights = new double[length];
  for(int i = 0; i < length; i++) {
    weights[i] = 0.0;
  }
}

Neuron::~Neuron() {
  delete[] weights;
}

double* Neuron::getWeights() {
  return weights;
}

int Neuron::getLength() {
  return length;
}