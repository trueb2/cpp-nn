/**
 * OutputLayer.h
 *
 * Represents the final NeuralLayer in a NeuralNetwork.
 * It contains different logic for computing update rules, and
 * will aid in configuring output from the NeuralNetwork.
 *
 * @author Jacob Trueb
 */

#ifndef CPPNN_OUTPUTLAYER_H
#define CPPNN_OUTPUTLAYER_H


#include "NeuralLayer.h"

class OutputLayer : public NeuralLayer {
public:
  /**
   * Initializes an OutputLayer, which is the final NeuralLayer in a NeuralNetwork
   * @param neuronCount
   * @param neuronLength
   * @param activationFunction
   */
  OutputLayer(int neuronCount, int neuronLength, ActivationFunction* activationFunction);

  /**
   * Calculates the weight updating rules for the output layer of a neural network.
   * It relies on the outputError that is previously computed, and does not use the nextLayer.
   * It updates the values in the deltas field member.
   *
   * The update rules are stored in an m x n array, where there are m neurons in the previous layer
   * that lead to n neurons in the output layer. An updateRules[i][j] value represents the change
   * in weight to the jth index of the weights of the ith neuron in the OutputLayer.
   *
   * @param nextLayer - Unused param for the output layer
   * @param outputError - The difference between the truth and actual outputs of the neural network
   */
  void calcUpdateRules(NeuralLayer* nextLayer, double* outputError) override;
};


#endif //CPPNN_OUTPUTLAYER_H
