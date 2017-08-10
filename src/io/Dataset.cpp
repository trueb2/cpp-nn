//
// Created by Jacob Trueb on 8/8/17.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Dataset.h"

Dataset::Dataset(Separability separability1, int numExamples, int numFeatures)
    : separability(separability1), numExamples(numExamples), numFeatures(numFeatures) {
  // The relative directory of the project's data folder
  std::string dir("../../data/");

  // Check that {separability}_examples_{numExamples}_{numFeatures} exists
  std::stringstream ss;
  ss << dir << SeparabilityStr::strForEnum(separability) << "_examples_" << numExamples << "_" << numFeatures;
  examplesFileName = ss.str();
  std::ifstream examplesFile(examplesFileName);
  if(examplesFile.good()) {
//    std::cout << "Dataset examples are located at " << examplesFileName << std::endl;
  } else {
//    std::cout << "Failed to find Dataset examples located at " << examplesFileName << std::endl;
  }

  // Check that {separability}_labels_{numExamples}_{numFeatures} exists
  ss.str("");
  ss << dir << SeparabilityStr::strForEnum(separability) << "_labels_" << numExamples << "_" << numFeatures;
  labelsFileName = ss.str();
  std::ifstream labelsFile(labelsFileName);
  if(examplesFile.good()) {
//    std::cout << "Dataset labels are located at " << labelsFileName << std::endl << std::endl;
  } else {
//    std::cout << "Failed to find Dataset labels located at " << labelsFileName << std::endl;
  }

  // Load the data
  readExamples();
  readLabels();
}

Dataset::~Dataset() {
  for(int i = 0; i < numExamples; i++) {
    delete examples[i];
  }
  delete[] examples;
}

void Dataset::readExamples() {
  // Allocate memory for the examples
  examples = new Input*[numExamples];

  // Prepare for iterating through examples
  std::ifstream file(examplesFileName);
  std::string line;
  int discoveredFeatures = 0;
  int exampleCount = 0;

  // Read in example rows up to numExamples
  while(std::getline(file, line, '\n') && exampleCount < numExamples) {
    // Read the line as comma separated strings
    std::stringstream lineStream(line);
    std::vector<std::string> features;
    std::string feature;
    int featureCount = 0;
    while(std::getline(lineStream, feature, ',')) {
      features.push_back(feature);
      featureCount++;
    }

    // Generate an input with the feature vector
    examples[exampleCount++] = new Input(features);

    // Check that the inputs have the same features length
    if(discoveredFeatures == 0) {
      discoveredFeatures = featureCount;
    } else if(featureCount != discoveredFeatures) {
      std::cout << "The discovered number of features does not match." << std::endl;
    }
  }
}

void Dataset::readLabels() {
  std::ifstream file(labelsFileName);
  std::string line;
  int discoveredLabels = 0;
  int exampleCount = 0;

  // Read in labels for each example
  while(std::getline(file, line, '\n') && exampleCount < numExamples) {
    // Read the line as comma separated strings
    std::stringstream lineStream(line);
    std::vector<std::string> labels;
    std::string label;
    int labelCount = 0;
    while(std::getline(lineStream, label, ',')) {
      labels.push_back(label);
      labelCount++;
    }

    // Update the inputs for each label read
    examples[exampleCount++]->setLabels(labels);

    // Check that the inputs have the same number of labels as the other examples.
    if(discoveredLabels == 0) {
      discoveredLabels = labelCount;
    } else if(labelCount != discoveredLabels) {
      std::cout << "The discovered number of labels does not match." << std::endl;
    }
  }
}

Input** Dataset::getExamples() {
  return examples;
}

int Dataset::getNumExamples() {
  return numExamples;
}

int Dataset::getOutputLength() {
  return examples[0]->getLabelsLength();
}
