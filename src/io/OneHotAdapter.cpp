//
// Created by jwtrueb on 8/1/17.
//

#include "OneHotAdapter.h"

OneHotAdapter::OneHotAdapter(int length) : length(length) {};

double* OneHotAdapter::transform(double *neuralLayerOutput, int neuronCount) {
  auto output = new double[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
    output[i] = neuralLayerOutput[i];
  }
  return output;
}

double* OneHotAdapter::outputError(double* outputAdapterOutput, double* targetOutput, int outputLength) {
  auto error = new double[outputLength];
  for(int i = 0; i < outputLength; i++) {
    error[i] = targetOutput[i] - outputAdapterOutput[i];
  }

  return error;
}