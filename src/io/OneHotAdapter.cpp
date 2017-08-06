//
// Created by jwtrueb on 8/1/17.
//

#include "OneHotAdapter.h"

OneHotAdapter::OneHotAdapter(int length) : length(length) {};

void* OneHotAdapter::transform(double *neuralLayerOutput, int neuronCount) {
  auto output = new double[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    output[i] = neuralLayerOutput[i];
  }
  return output;
}

void * OneHotAdapter::outputError(void* outputAdapterOutput, void* targetOutput, int outputLength) {
  auto error = new double[outputLength];

  auto calculated = (double*) outputAdapterOutput;
  auto target = (double*) targetOutput;
  for(int i = 0; i < outputLength; i++) {
    error[i] = target[i] - calculated[i];
  }

  return (void*) error;
}