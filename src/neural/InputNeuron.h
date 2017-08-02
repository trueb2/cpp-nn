/**
 * InputNeuron.h
 *
 * Represents the Input for the Neural Network.
 * The length of the Neuron determines the neuronLength of
 * the first NeuralLayer.
 *
 * @author Jacob Trueb
 */
#ifndef CPPNN_INPUTNEURON_H
#define CPPNN_INPUTNEURON_H


#include "Neuron.h"

class InputNeuron : public Neuron {
  /**
   * Creates an InputNeuron with the provided inputValues as
   * the weights of the Neuron
   *
   * @param inputValues - An array of double values to initalize weights
   * @param length - The length of the inputValues array
   */
  InputNeuron(double* inputValues, int length);

  /**
   * Frees space allocated by InputNeuron
   */
  ~InputNeuron();

public:
  double* copyWeights();
};


#endif //CPPNN_INPUTNEURON_H
