//
// Created by Jacob Trueb on 8/5/17.
//

#include "OutputLayer.h"


OutputLayer::OutputLayer(int neuronCount, int neuronLength, ActivationFunction* activationFunction)
    : NeuralLayer(neuronCount, neuronLength, activationFunction) {}

double* OutputLayer::calcUpdateRules(NeuralLayer* nextLayer, double* outputError) {
  // There is not another layer
  (void) nextLayer;

  // Populate deltas
  for(int i = 0; i < neuronCount; i++) {
    double activationDerivative = activationFunction->evaluateDerivative(inputs[i]);
    deltas[i] = outputError[i] * activationDerivative;
  }

  // Compute output layer update rules
  double* updateRules = new double[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    updateRules[i] = deltas[i] * inputs[i];
  }

  return updateRules;
}