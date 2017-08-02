//
// Created by jwtrueb on 8/1/17.
//

#include <cassert>
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(NeuralLayer** neuralLayers, int layerCount, OutputAdapter* outputAdapter)
    : neuralLayers(neuralLayers), layerCount(layerCount), outputAdapter(outputAdapter) {
  // Assert that the NeuralNetwork is architecturally sound
  assert(layerCount > 0);
  int count = neuralLayers[0]->getNeuronCount();
  for (int i = 1; i < layerCount; i++) {
    NeuralLayer* neuralLayer = neuralLayers[i];
    assert(count == neuralLayer->getNeuronLength());
    count = neuralLayer->getNeuronCount();
  }
}

NeuralNetwork::~NeuralNetwork() {
  for (int i = 0; i < layerCount; i++) {
    delete neuralLayers[i];
  }
  delete[] neuralLayers;
}

void NeuralNetwork::train(Input** inputs, int inputsLength) {
  for (int i = 0; i < inputsLength; i++) {
    // Get the next input
    Input* input = inputs[i];
    // Compute the output of the network on the input
    void* output = evaluate(input);
    // Compute the error on the input
    void* error = outputAdapter->outputError(output, input->getLabels(), input->getLabelsLength());

    //TODO: Use Back Propagation
  }
}

void* NeuralNetwork::evaluate(Input* input) {
  assert(input->getDataLength() == neuralLayers[0]->getNeuronLength());

  // Forward Propagation
  double* inputData = input->getData();
  int inputLength = input->getDataLength();
  for (int i = 0; i < layerCount; i++) {
    double* output = neuralLayers[i]->passForward(inputData, inputLength);
    delete inputData;
    inputData = output;
    inputLength = neuralLayers[i]->getNeuronCount();
  }

  // Convert output
  return outputAdapter->transform(inputData, inputLength);
}

int NeuralNetwork::getLayerCount() {
  return layerCount;
}