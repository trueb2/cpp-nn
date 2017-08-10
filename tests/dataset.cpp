//
// Created by jwtrueb on 7/31/17.
//

#include <iostream>
#include "gtest/gtest.h"
#include "../src/enums/Separability.h"
#include "../src/io/Dataset.h"

namespace {
  //The fixture for testing class Dataset
  class DatasetTest : public ::testing::Test {
  protected:
    DatasetTest() {
      // setup work goes here
    }

    virtual ~DatasetTest() {
      // cleanup work goes here
    }

    virtual void SetUp() {
      // called immediately after the constructor before each test
    }

    virtual void TearDown() {
      // called immediately after each test before the destructor
    }

    // objects declared here can be used by all tests in the test case for Foobar
  };

  TEST_F(DatasetTest, CanLoadDataset) {
    Dataset* dataset = new Dataset(Separability::linear, 1000, 2);
    delete dataset;
  }

  TEST_F(DatasetTest, CheckDatasetHasCorrectData) {
    int numExamples = 1000;
    Dataset* dataset = new Dataset(Separability::linear, numExamples, 2);

    // Check that the first and last entries are correct
    std::stringstream ss;
    Input** examples = dataset->getExamples();
    ss << *examples[0] << "," << *examples[dataset->getNumExamples()-1];
    ASSERT_EQ("Input(0.31289,0.473721),Input(0.375705,0.301955)", ss.str());
    ASSERT_EQ(numExamples, dataset->getNumExamples());
  }
} // namespace
