//
// Created by jwtrueb on 8/1/17.
//

#include "NeuralLayer.h"

NeuralLayer::NeuralLayer(int neuronCount, int neuronLength, ActivationFunction *activationFunction):
  neuronCount(neuronCount), neuronLength(neuronLength), activationFunction(activationFunction)
{
  neurons = new Neuron*[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    neurons[i] = new Neuron(neuronLength);
  }
}

NeuralLayer::~NeuralLayer() {
  for(int i = 0; i < neuronCount; i++) {
    delete neurons[i];
  }

  delete [] neurons;
}

int NeuralLayer::getNeuronCount() {
  return neuronCount;
}

int NeuralLayer::getNeuronLength() {
  return neuronLength;
}

std::string NeuralLayer::getActivationFunctionName() {
  return activationFunction->getName();
}