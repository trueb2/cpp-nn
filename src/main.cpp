#include <iostream>
#include <fstream>
#include <vector>
#include "io/Dataset.h"
#include "neural/layers/NeuralLayer.h"
#include "functions/SigmoidFunction.h"
#include "io/OneHotAdapter.h"
#include "neural/layers/OutputLayer.h"
#include "neural/NeuralNetwork.h"

int main() {
  // Load a Dataset
  Dataset* dataset = new Dataset(Separability::linear, 1000, 2);

  // Define some layers
  NeuralLayer** nls = new NeuralLayer*[2];
  SigmoidFunction s;
  nls[0] = new NeuralLayer(2,2,&s);
  nls[1] = new OutputLayer(1,2,&s);

  // Create the neural network
  OneHotAdapter oha(1);
  NeuralNetwork* nn = new NeuralNetwork(nls, 2, &oha);

  // Train on dataset and output error
  for(int i = 0; i < 100000; i++) {
    double error = nn->evaluateError(dataset);
    if(i % 100 == 0) {
      double accuracy = nn->evaluateAccuracy(dataset);
      std::cout << "[" << i << "]Error :: " << error;
      std::cout << "[" << accuracy << "]" << std::endl;
    }
    nn->train(dataset);
  }

  return 0;
}