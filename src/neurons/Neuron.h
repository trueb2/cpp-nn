/**
 * Neuron.h
 *
 * Represents a node in a neural network
 * aka Perceptron
 *
 * @author Jacob Trueb
 */
#ifndef CPPNN_NEURON_H
#define CPPNN_NEURON_H


class Neuron {
public:

  /**
   * dot - performs an inner dot product with this Neuron's weights and the weights provided
   *
   * @param weights - The weights to dot with this Neuron's weights
   * @param length - The length of the weights array provided
   * @return inner_dot_product - The inner dot product of the weights
   */
  double dot(const double* weights, const int length);

  /**
   * setWeights - sets the weights of the Neuron with the supplied length
   *
   * @param weights - The new weights copied for the Neuron
   * @param length - The length of the new weights array
   */
  void setWeights(const double * weights, const int length);

  /**
   * getWeights() - returns the weights of the Neuron
   *
   * @return weights - The double array with the weights of the Neuron
   */
  double* getWeights();


  /**
   * getLength() - returns width of Neuron
   *
   * @return length - The length of the weights array of the Neuron
   */
  int getLength();

  /**
   * Neuron(length) - Instantiates a Neuron with an array of [length] weights, each roughly equal to 0.0
   *
   * @param length - The length of the weights array
   */
  explicit Neuron(int length);

  /**
   * ~Neuron - Frees the memory allocated for the Neuron's weights
   */
  ~Neuron();

private:
  double* weights;
  int length;

};


#endif //CPPNN_NEURON_H
