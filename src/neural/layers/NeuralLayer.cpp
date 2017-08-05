//
// Created by jwtrueb on 8/1/17.
//

#include <cassert>
#include "NeuralLayer.h"

int NeuralLayer::idCounter = 0;

NeuralLayer::NeuralLayer(int neuronCount, int neuronLength, ActivationFunction* activationFunction) :
    neuronCount(neuronCount), neuronLength(neuronLength), activationFunction(activationFunction) {
  neurons = new Neuron* [neuronCount];
  for (int i = 0; i < neuronCount; i++) {
    neurons[i] = new Neuron(neuronLength);
  }

  id = idCounter++;

  inputs = new double[neuronCount];
  outputs = new double[neuronCount];
  activatedOutputs = new double[neuronCount];
  deltas = new double[neuronCount];
}

NeuralLayer::~NeuralLayer() {
  for (int i = 0; i < neuronCount; i++) {
    delete neurons[i];
  }
  delete[] neurons;

  delete[] inputs;
  delete[] outputs;
  delete[] activatedOutputs;
  delete[] deltas;
}

void NeuralLayer::resetIdCounter() {
  idCounter = 0;
}

int NeuralLayer::getId() const {
  return id;
}

int NeuralLayer::getNeuronCount() const {
  return neuronCount;
}

int NeuralLayer::getNeuronLength() const {
  return neuronLength;
}

std::string NeuralLayer::getActivationFunctionName() const {
  return activationFunction->getName();
}

double* NeuralLayer::passForward(double* input, int inputLength) {
  // Assert that the input dimensions match the expected dimensions
  assert(neuronLength == inputLength);

  // Update a copy of the inputs
  copyToMember(inputs, input);

  // Dot the input with each neuron
  double* out = new double[neuronCount];
  for (int i = 0; i < neuronCount; i++) {
    out[i] = neurons[i]->dot(input, inputLength);
  }

  // Update a copy of the outputs
  copyToMember(outputs, out);

  // Activate the out using the layer's activation function
  for(int i = 0; i < neuronCount; i++) {
    out[i] = activationFunction->evaluate(out[i]);
  }

  // Update a copy of the activatedOutputs
  copyToMember(activatedOutputs, out);

  return out;
}

double* NeuralLayer::calcUpdateRules(NeuralLayer* nextLayer, double* outputError) {
  // Output Error is only useful for the OutputLayer
  (void)outputError;

  // Update the deltas array
  double* outputDerivatives = new double[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    outputDerivatives[i] = activationFunction->evaluateDerivative(inputs[i]);
    double sum = 0.0;
    for(int j = 0; j < nextLayer->getNeuronCount(); j++) {
      sum += nextLayer->deltas[j] * nextLayer->getNeuronWeight(j, i);
    }
    deltas[i] = outputDerivatives[i] * sum;
  }
  delete[] outputDerivatives;

  // Calculate the update rules using the deltas and the inputs
  double* updateRules = new double[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    updateRules[i] = /* learning_rate */ deltas[i] * activatedOutputs[i];
  }

  return updateRules;
}

double NeuralLayer::getNeuronWeight(int neuronIdx, int weightIdx) const {
  return neurons[neuronIdx]->getWeights()[weightIdx];
}

void NeuralLayer::copyToMember(double* member, const double* data) {
  for(int i = 0; i < neuronLength; i++) {
    member[i] = data[i];
  }
}

