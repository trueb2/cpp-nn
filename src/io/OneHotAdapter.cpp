//
// Created by jwtrueb on 8/1/17.
//

#include <cfloat>
#include "OneHotAdapter.h"

OneHotAdapter::OneHotAdapter(int length) : length(length) {};

void* OneHotAdapter::transform(double *neuralLayerOutput, int neuronCount) {
  int maxIdx = -1;
  int maxVal = -DBL_MAX;
  for(int i = 0; i < neuronCount; i++) {
    if(neuralLayerOutput[i] > maxVal) {
      maxIdx = 0;
      maxVal = neuralLayerOutput[i];
    }
  }

  bool* oneHot = new bool[neuronCount];
  for(int i = 0; i < neuronCount; i++) {
      oneHot[i] = (i == maxIdx);
  }
}