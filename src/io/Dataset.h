/**
 * Dataset.h
 *
 * Represents a csv reading utility that can read in data
 * from the project level data directory. It reads
 * in both the training examples as well as their labels.
 * Will parse are return in the data as an array of Inputs
 *
 * @author Jacob Trueb
 */
#ifndef CPPNN_DATASET_H
#define CPPNN_DATASET_H

#include "../enums/Separability.h"
#include "Input.h"


class Dataset {
public:
  /**
   * Loads the data examples and examples labels for a dataset
   * in the cpp-nn/data directory.
   *
   * @param separability - Enum for the type of separability.
   * @param numExamples - The number of examples in the dataset.
   * @param numFeatures - The number of columns in the dataset.
   */
  Dataset(Separability separability, int numExamples, int numFeatures);

  /**
   * Frees memory for data and labels
   */
  ~Dataset();

  /**
   * Read the examples from a csv file
   */
  void readExamples();

  /**
   * Read the labels from a csv file
   */
  void readLabels();

  /**
   * Get the reference to the examples in the dataset.
   *
   * @return Pointer to the loaded examples
   */
  Input** getExamples();

  /**
   * @return numExamples - The number of examples in the examples field member.
   */
  int getNumExamples();

  /**
   * Gets the size of the output array from an Input
   */
  int getOutputLength();

private:
  Input** examples;

  Separability separability;
  int numExamples;
  int numFeatures;

  std::string examplesFileName;
  std::string labelsFileName;
};


#endif //CPPNN_DATASET_H
