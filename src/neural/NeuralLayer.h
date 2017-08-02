//
// Created by jwtrueb on 8/1/17.
//

#ifndef CPPNN_NEURALLAYER_H
#define CPPNN_NEURALLAYER_H


#include "../functions/ActivationFunction.h"
#include "Neuron.h"

class NeuralLayer {
public:
  /**
   * Creates a NeuralLayer with neuronCount neurons that have length neuronLength.
   * The activation function for each of the layers is the ActivationFunction passed.
   *
   * @param neuronCount - The number of neurons in the layer
   * @param neuronLength - The length of the neurons in the layer
   * @param activationFunction - A pointer to the activation function performed on the output of each neuron
   */
  NeuralLayer(int neuronCount, int neuronLength, ActivationFunction* activationFunction);

  /**
   * Frees memory for each neuron as well the array holding their pointers.
   * Frees memory for the artifacts if any was allocated.
   */
  ~NeuralLayer();

  /**
   * Resets the id counter to 0
   */
  static void resetIdCounter();

  /**
   * Returns the unique id of the neural layer, starting at 0.
   */
  int getId();

  /**
   * Get the total number of Neurons in this NeuralLayer
   *
   * @return count - The number of Neurons for the NeuralLayer
   */
  int getNeuronCount();

  /**
   * Get the length of a Neuron in this NeuralLayer
   *
   * @return length - Neuron Length
   */
  int getNeuronLength();

  /**
   * Returns the name of the activation function used for the layer
   *
   * @return name - The name of the activation function
   */
  std::string getActivationFunctionName();

  /**
   * Accepts an array of weights that are the same length as the neuronLength.
   * Computes the output for each of the Neurons in the layer. Stores
   * the results of the pass in a field member.
   *
   * @param input - The array to pass through the NeuralLayer
   * @param inputLength - The length of the input, which must match the neuronLength
   * @return output - The activated output of each Neuron in the layer
   */
  double *passForward(double *input, int inputLength);

private:
  static int idCounter;
  int id;

  int neuronCount;
  int neuronLength;
  ActivationFunction* activationFunction;
  Neuron** neurons;

  double* artifacts;
};


#endif //CPPNN_NEURALLAYER_H
