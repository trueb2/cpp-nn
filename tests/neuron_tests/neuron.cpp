//
// Created by jwtrueb on 7/31/17.
//

#include <iostream>
#include "gtest/gtest.h"
#include "../../src/neurons/Neuron.h"

namespace {
  //The fixture for testing class Neuron
  class NeuronTest : public ::testing::Test {
  protected:
    NeuronTest() {
      // setup work goes here
    }

    virtual ~NeuronTest() {
      // cleanup work goes here
    }

    virtual void SetUp() {
      // called immediately after the constructor before each test
      neuron = new Neuron(10);
    }

    virtual void TearDown() {
      // called immediately after each test before the destructor
      delete neuron;
    }

    // objects declared here can be used by all tests in the test case for Foobar
    Neuron* neuron;
  };

  TEST_F(NeuronTest, NeuronInitalizedWithCorrectLength) {
    ASSERT_EQ(10, neuron->getLength()) << "Expecting a neuron instantiated with length 10 to have length 10";
  }

  TEST_F(NeuronTest, NeuronInitializedToZero) {
    double* weights = neuron->getWeights();
    int length = neuron->getLength();
    for(int i = 0; i < length; i++) {
      ASSERT_GT(1e-100, weights[i]) << "Expecting a newly instantiated neuron to have near 0 weights";
    }
  }
} // namespace
