//
// Created by jwtrueb on 8/1/17.
//

#ifndef CPPNN_NEURALLAYER_H
#define CPPNN_NEURALLAYER_H


#include "../../functions/ActivationFunction.h"
#include "../Neuron.h"

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
  virtual ~NeuralLayer();

  /**
   * Resets the id counter to 0
   */
  static void resetIdCounter();

  /**
   * Returns the unique id of the neural layer, starting at 0.
   */
  int getId() const;

  /**
   * Get the total number of Neurons in this NeuralLayer
   *
   * @return count - The number of Neurons for the NeuralLayer
   */
  int getNeuronCount() const;

  /**
   * Get the length of a Neuron in this NeuralLayer
   *
   * @return length - Neuron Length
   */
  int getNeuronLength() const;

  /**
   * Returns the name of the activation function used for the layer
   *
   * @return name - The name of the activation function
   */
  std::string getActivationFunctionName() const;

  /**
   * Accepts an array of weights that are the same length as the neuronLength.
   * Computes the output for each of the Neurons in the layer.
   * Memory is allocated twice for the outputs for the returned array.
   * The field member, layerOutputs, is set to the return value output
   *
   * @param input - The array to pass through the NeuralLayer
   * @param inputLength - The length of the input, which must match the neuronLength
   * @return output - The activated output of each Neuron in the layer
   */
  virtual double* passForward(double* input, int inputLength);

  /**
   * Calculates the updates for the weights of the NeuralLayer depending on the
   * next layer. This process produces artifacts that are necessary
   * for the preceding NeuralLayer to compute its update rules.
   *
   * The update rules are stored in an m x n array, where there are m neurons in the previous layer
   * that lead to n neurons in the output layer. An updateRules[i][j] value represents the change
   * in weight to the jth index of the weights of the ith neuron in the OutputLayer.
   *
   * @param nextLayer - The next layer in the neural network that is necessary for backpropagation
   * @param outputError - Unused param from a non output layer
   */
  virtual void calcUpdateRules(NeuralLayer* nextLayer, double* outputError);

  /**
   * Applies the calculated update rules to the weights of the neurons
   * in this NeuralLayer.
   *
   * calcUpdateRules should be called prior to this method each time.
   */
  void applyUpdates();

protected:
  static int idCounter;
  int id;

  int neuronCount;
  int neuronLength;
  ActivationFunction* activationFunction;
  Neuron** neurons;

  double* inputs;
  double* outputs;
  double* activatedOutputs;
  double* deltas;
  double** updateRules;

  /**
   * Looks up the weight by index from a neuron by index in this NeuralLayer.
   *
   * @param neuronIdx - The neuron's 0-based index
   * @param weightIdx - The weight's 0-based index
   * @return weight - A double representing weight
   */
  double getNeuronWeight(int neuronIdx, int weightIdx) const;

  /**
   * Saves a copy of the data to one of the field member pointers provided.
   * This is intended for use with inputs, outputs, activatedOutputs and deltas.
   * @param member - A pointer to the place to store the data
   * @param data - The data to store
   */
  void copyToMember(double* member, const double* data);
};

#endif //CPPNN_NEURALLAYER_H
