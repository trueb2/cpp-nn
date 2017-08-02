/**
 * OutputAdapter.h
 *
 * Accepts the final output of a NeuralLayer, and
 * produces the desired format of output
 *
 * @author Jacob Trueb
 */
#ifndef CPPNN_OUTPUTADAPTER_H
#define CPPNN_OUTPUTADAPTER_H


class OutputAdapter {
  /**
   * Takes the output of a NeuralLayer and converts it
   * as specified by the derivative class to a desired output
   *
   * @param neuralLayerOutput - The output of a NeuralLayer
   * @return transformedOutput - The desired output format
   */
  virtual void* transform(double* neuralLayerOutput, int neuronCount) = 0;
};


#endif //CPPNN_OUTPUTADAPTER_H
