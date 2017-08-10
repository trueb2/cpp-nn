/**
 * InputNeuron.h
 *
 * Represents the Input for the Neural Network.
 * The length of the Neuron determines the neuronLength of
 * the first NeuralLayer.
 *
 * @author Jacob Trueb
 */
#ifndef CPPNN_INPUT_H
#define CPPNN_INPUT_H


#include <string>
#include <vector>

class Input {
public:
  /**
   * Creates an Input with the data and label provided
   *
   * @param data - An array of input data
   * @param dataLength - The length of the data array
   * @param labels - An array of labels of the data
   * @param labelsLength - The length of the labels array
   */
  Input(double* data, int dataLength, double* labels, int labelsLength);

  /**
   * Accepting a vector of strings representing double data values.
   *
   * The data and dataLength field member variables are created from the
   * vector argument, while labels and labelsLength must be set later using
   * setLabels()
   */
  Input(std::vector<std::string> strData);

  /**
   * Frees space allocated by InputNeuron
   */
  ~Input();

  /**
   * Get the data pointer. Do not free the pointer.
   */
  double* getData();

  /**
   * Get the length of the data array
   */
  int getDataLength();

  /**
   * Get the labels pointer. Do not free the labels.
   */
  double* getLabels();

  /**
   * Get the length of the labels array.
   */
  int getLabelsLength();

  /**
   * Get the id of the Input. The ids are 0-based
   * and can be reset using resetIdCounter.
   */
  int getId();

  /**
   * Resets the idCounter static member to 0.
   */
  static void resetIdCounter();

  /**
   * A vector of labels for the example that will be stored for the
   * Input and compared for training purposes.
   *
   * @param vector - The labels in string form to be interpreted as doubles
   */
  void setLabels(std::vector<std::string> vector);


protected:
  static int idCounter;
  int id;

  double* data;
  double* labels;
  int dataLength;
  int labelsLength;

private:
  friend std::ostream& operator<<(std::ostream& strm, const Input& input);
};


#endif //CPPNN_INPUT_H
