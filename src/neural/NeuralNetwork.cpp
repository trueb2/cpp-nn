//
// Created by jwtrueb on 8/1/17.
//

#include <cassert>
#include <iostream>
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(NeuralLayer** neuralLayers, int layerCount, OutputAdapter* outputAdapter)
    : neuralLayers(neuralLayers), layerCount(layerCount), outputAdapter(outputAdapter) {
  // Assert that the NeuralNetwork is architecturally sound
  assert(layerCount > 0);
  int count = neuralLayers[0]->getNeuronCount();
  for(int i = 1; i < layerCount; i++) {
    NeuralLayer* neuralLayer = neuralLayers[i];
    assert(count == neuralLayer->getNeuronLength());
    count = neuralLayer->getNeuronCount();
  }
}

NeuralNetwork::~NeuralNetwork() {
  for(int i = 0; i < layerCount; i++) {
    delete neuralLayers[i];
  }
  delete [] neuralLayers;
}

void NeuralNetwork::train(InputNeuron** inputNeurons, int inputNeuronsLength) {

  //TODO:: Call Evaluate

  //TODO: Use Back Propagation
}

void* NeuralNetwork::evaluate(InputNeuron* inputNeuron) {
  assert(inputNeuron->getLength() == neuralLayers[0]->getNeuronLength());

  //TODO: Implement Forward Propagation

  //TODO: Transform Forward Propagation with OutputAdapter

  //TODO: Store artifacts from propagation
}

int NeuralNetwork::getLayerCount() {
  return layerCount;
}