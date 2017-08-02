/**
 * Represents a Neural Network
 *
 * Has an array of NeuralLayers that are checked for compatibility.
 * Accepts an InputNeuron to evaluate and train the NeuralLayers.
 * Accepts an OutputTransform to configure the values output for a given Inpu
 */

#ifndef CPPNN_NEURALNETWORK_H
#define CPPNN_NEURALNETWORK_H


#include "NeuralLayer.h"
#include "../io/OutputAdapter.h"
#include "InputNeuron.h"

class NeuralNetwork {
public:
  NeuralNetwork(NeuralLayer* neuralLayers, OutputAdapter* outputAdapter);
  ~NeuralNetwork();
  Output* consume(InputNeuron input);
protected:
  NeuralLayer* neuralLayers;
  OutputAdapter* outputAdapter;
};


#endif //CPPNN_NEURALNETWORK_H
