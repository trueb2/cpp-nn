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


#include <gdbm.h>

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

public:
  static int idCounter;
  int id;

  double* data;
  double* labels;
  int dataLength;
  int labelsLength;
};


#endif //CPPNN_INPUT_H
