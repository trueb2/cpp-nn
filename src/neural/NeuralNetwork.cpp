//
// Created by jwtrueb on 8/1/17.
//

#include <cassert>
#include "layers/NeuralLayer.h"
#include "layers/OutputLayer.h"
#include "../io/OutputAdapter.h"
#include "NeuralNetwork.h"
#include "../io/Dataset.h"

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
  assert(typeid(*neuralLayers[layerCount-1]) == typeid(OutputLayer));
}

NeuralNetwork::~NeuralNetwork() {
  for (int i = 0; i < layerCount; i++) {
    delete neuralLayers[i];
  }
  delete[] neuralLayers;
}

void NeuralNetwork::train(Dataset* dataset) {
  Input** inputs = dataset->getExamples();
  for (int i = 0; i < dataset->getNumExamples(); i++) {
    // Get the next input
    Input* input = inputs[i];

    // Compute the output of the network on the input
    double* output = evaluate(input);

    // Compute the error on the input
    double* error = outputAdapter->outputError(output, input->getLabels(), input->getLabelsLength());

    // Compute update rules from each layer
    NeuralLayer* nextLayer = nullptr;
    for(int j = layerCount - 1; j > -1; j--) {
      neuralLayers[j]->findUpdateRules(nextLayer, error);
      nextLayer = neuralLayers[j];
    }

    // Apply update rules
    for(int j = 0; j < layerCount; j++) {
      neuralLayers[j]->applyUpdates();
    }
  }
}

double* NeuralNetwork::evaluate(Input* input) {
  assert(input->getDataLength() == neuralLayers[0]->getNeuronLength());

  // Forward Propagation
  double* data = input->getData();
  double* inputData = new double[input->getDataLength()];
  std::copy(data, data+input->getDataLength(), inputData);
  int inputLength = input->getDataLength();
  for (int i = 0; i < layerCount; i++) {
    double* output = neuralLayers[i]->passForward(inputData, inputLength);
    delete[] inputData;
    inputData = output;
    inputLength = neuralLayers[i]->getNeuronCount();
  }

  // Propagated output
  return inputData;
}

int NeuralNetwork::getLayerCount() {
  return layerCount;
}

double NeuralNetwork::evaluateError(Dataset* dataset) {
  int labelsLength = dataset->getOutputLength();
  double error = 0.0;
  Input** examples = dataset->getExamples();
  for(int i = 0; i < dataset->getNumExamples(); i++) {
    Input* input = examples[i];
    double* output = evaluate(input);
    double* exampleError = outputAdapter->outputError(output, input->getLabels(), labelsLength);
    for(int j = 0; j < labelsLength; j++) {
      error += exampleError[i] > 0 ? exampleError[i] : -exampleError[i];
    }
  }
  return error;
}

double NeuralNetwork::evaluateAccuracy(Dataset* dataset) {
  int labelsLength = dataset->getOutputLength();
  double count = 0;
  Input** examples = dataset->getExamples();
  for(int i = 0; i < dataset->getNumExamples(); i++) {
    Input* input = examples[i];
    double* output = evaluate(input);
    double* transformedOutput = outputAdapter->transform(output, labelsLength);
    double* difference = outputAdapter->outputError(transformedOutput, input->getLabels(), labelsLength);
    for(int i = 0; i < labelsLength; i++) {
      if(difference[i] > 0.0e-10) {
        count += 1;
        break;
      }
    }
  }

  double correct = dataset->getNumExamples() - count;
  return correct / ((double) dataset->getNumExamples());
}
