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
public:
  /**
   * Takes the output of a NeuralLayer and converts it
   * as specified by the derivative class to a desired output
   *
   * @param neuralLayerOutput - The output of a NeuralLayer
   * @return transformedOutput - The desired output format
   */
  virtual void* transform(double* neuralLayerOutput, int neuronCount) = 0;

  /**
   * Takes output from the transform function and a truth output, then
   * computes the margin of error.
   *
   * @param outputAdapterOutput - A value returned by transform
   * @param truthOutput - The correct output
   * @param outputLength - The length of the output if returning array
   * @return error - The margin of error on the output
   */
  virtual void *outputError(void *outputAdapterOutput, void *truthOutput, int outputLength) = 0;
};


#endif //CPPNN_OUTPUTADAPTER_H
