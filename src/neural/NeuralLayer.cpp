//
// Created by jwtrueb on 8/1/17.
//

#include <cassert>
#include "NeuralLayer.h"

int NeuralLayer::idCounter = 0;

NeuralLayer::NeuralLayer(int neuronCount, int neuronLength, ActivationFunction *activationFunction):
  neuronCount(neuronCount), neuronLength(neuronLength), activationFunction(activationFunction)
{
  neurons = new Neuron*[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    neurons[i] = new Neuron(neuronLength);
  }

  id = idCounter++;
  artifacts = nullptr;
}

NeuralLayer::~NeuralLayer() {
  for(int i = 0; i < neuronCount; i++) {
    delete neurons[i];
  }

  delete [] neurons;

  if(artifacts != nullptr) {
    delete artifacts;
  }
}

void NeuralLayer::resetIdCounter() {
  idCounter = 0;
}

int NeuralLayer::getId() {
  return id;
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

double * NeuralLayer::passForward(double* input, int inputLength) {
  assert(neuronLength == inputLength);

  if(artifacts != nullptr) {
    delete artifacts;
  }

  artifacts = new double[neuronCount];
  double* retArtifacts = new double[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    artifacts[i] = retArtifacts[i] = neurons[i]->dot(input, inputLength);
  }

  return retArtifacts;
}
