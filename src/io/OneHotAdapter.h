/**
 * OneHotAdapter.h
 *
 * Produces a one-hot vector output for a neuralLayer
 *
 * Accepts the final output of a NeuralLayer, and
 * produces the desired format of output
 *
 * @author Jacob Trueb
 */

#ifndef CPPNN_ONEHOTADAPTER_H
#define CPPNN_ONEHOTADAPTER_H


#include "OutputAdapter.h"

class OneHotAdapter : public OutputAdapter {
public:
  /**
   * Creates a OneHotAdapter that can transform a NeuralLayer output
   * of length length. The length supplied should be equal to the
   * NeuralLayer's neuronCount.
   *
   * @param length - The length of the one hot vector.
   */
  OneHotAdapter(int length);

  /**
   * Transforms the NeuralLayer output if dimensions match.
   *
   * The index of the greatest output will be set to true in the
   * resulting vector, while the rest will be set to false.
   *
   * @param neuralLayerOutput - result from each Neuron in NeuralLayer
   * @return oneHot - double* of length this->length
   */
  void* transform(double* neuralLayerOutput, int neuronCount);

  /**
   * Computes the margin of error for each index of the OneHotAdapter
   * transform output.
   *
   * @param outputAdapterOutput - A double* array of output from transform
   * @param truthOutput - A double* array of truth
   * @param outputLength - The length of outputAdapterOutput, truthOutput, and error
   * @return error - A double* array of margin of error on each index
   */
  void *outputError(void *outputAdapterOutput, void *truthOutput, int outputLength);


private:
  int length;

};


#endif //CPPNN_ONEHOTADAPTER_H