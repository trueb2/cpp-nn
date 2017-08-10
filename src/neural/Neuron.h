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
   * resetIdCounter - sets the static idCounter member to 0 to reset id values
   */
  static void resetIdCounter();

  /**
   * setWeights - sets the weights of the Neuron with the supplied length
   *
   * @param weights - The new weights copied for the Neuron
   * @param length - The length of the new weights array
   */
  void setWeights(const double * weights, const int length);

  /**
   * setWeights - sets the weights of the Neuron to the value supplied
   *
   * @param fillWeight - The double assigned for every weight in the Neuron.
   */
  void setWeights(double fillWeight);

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
   * getId - returns the unique id of the Neuron
   * @return id - 0-indexed id
   */
  int getId();

  /**
   * Neuron(length) - Instantiates a Neuron with an array of [length] weights, each roughly equal to 0.0.
   * Assigns a unique id to each Neuron.
   *
   * @param length - The length of the weights array
   */
  explicit Neuron(int length);

  /**
   * ~Neuron - Frees the memory allocated for the Neuron's weights
   */
  ~Neuron();

  /**
   * Adds the values to the weights of the neuron.
   *
   * @param values - The amounts to be added to the weights
   */
  void addToWeights(const double* values);

protected:
  static int idCounter;
  int id;


  double* weights;
  int length;
};


#endif //CPPNN_NEURON_H
