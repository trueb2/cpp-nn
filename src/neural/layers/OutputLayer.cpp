//
// Created by Jacob Trueb on 8/5/17.
//

#include "OutputLayer.h"


OutputLayer::OutputLayer(int neuronCount, int neuronLength, ActivationFunction* activationFunction)
    : NeuralLayer(neuronCount, neuronLength, activationFunction) {}

void OutputLayer::calcUpdateRules(NeuralLayer* nextLayer, double* outputError) {
  // There is not a next NeuralLayer
  (void) nextLayer;

  // Populate a delta for each output neuron
  for(int i = 0; i < neuronCount; i++) {
    double activationDerivative = activationFunction->evaluateDerivative(inputs[i]);
    deltas[i] = outputError[i] * activationDerivative;
  }

  // Compute update rules for each neuron in the OutputLayer
  for(int i = 0; i < neuronCount; i++) {
    for(int j = 0; j < neuronLength; j++) {
      updateRules[i][j] = deltas[i] * inputs[j];
    }
  }
}