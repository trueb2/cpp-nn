/**
 * Represents a Neural Network
 *
 * Has an array of NeuralLayers that are checked for compatibility.
 * Accepts an InputNeuron to evaluate and train the NeuralLayers.
 * Accepts an OutputTransform to configure the values output for a given Inpu
 */

#ifndef CPPNN_NEURALNETWORK_H
#define CPPNN_NEURALNETWORK_H


#include "layers/NeuralLayer.h"
#include "../io/OutputAdapter.h"
#include "../io/Input.h"

class NeuralNetwork {
public:
  /**
   * Creates a NeuralNetwork that checks for proper dimensions between layers.
   * The output of the NeuralNetwork when evaluated on the input is determined
   * by the output adapter. After instantiating a NeuralNetwork, it must be trained.
   *
   * @param neuralLayers - The layers of the network
   * @param layerCount - The total number of NeuralLayers
   * @param outputAdapter - The OutputAdapter that gives the desired style of output
   */
  NeuralNetwork(NeuralLayer** neuralLayers, int layerCount, OutputAdapter* outputAdapter);

  /**
   * Frees the memory for the neuralLayers that are passed in
   * the constructor
   */
  ~NeuralNetwork();

  /**
   * Performs a training iteration on the array of inputs provided.
   * Updates the weights of the neurons in the NeuralLayers
   * using back propagation.
   *
   * @param inputs - An array of input neurons
   * @param inputsLength - The number of inputs in inputs
   */
  void train(Input** inputs, int inputsLength);

  /**
   * Evaluates the neural network for a single input
   *
   * @param input - The input to run through the network
   * @return output - The ouput computed and wrangled
   * by the NeuralNetwork and OutputAdapter
   */
  void* evaluate(Input* input);

  /**
   * Returns the number of layers within the NeuralNetwork.
   * This value is equal to the layerCount passed in the constructor,
   * and neither counts the InputNeurons nor the OutputAdapter
   */
  int getLayerCount();

protected:
  NeuralLayer** neuralLayers;
  int layerCount;
  OutputAdapter* outputAdapter;
};


#endif //CPPNN_NEURALNETWORK_H
