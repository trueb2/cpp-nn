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
      Neuron::resetIdCounter();
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

  TEST_F(NeuronTest, CanSetWeightsValues) {
    double weights[] = {1.0, 2.0, 3.0, 4.0};
    neuron->setWeights(weights, 4);

    ASSERT_EQ(4, neuron->getLength());

    double* neuronWeights = neuron->getWeights();
    for(int i = 0; i < 4; i++) {
      ASSERT_EQ(neuronWeights[i], weights[i]);
    }
  }

  TEST_F(NeuronTest, CannotSetWeigthsToEmpty) {
    double weights[] = {};
    EXPECT_DEATH(neuron->setWeights(weights, 0), "Assertion `length > 0' failed");
  }

  TEST_F(NeuronTest, CanDotWeightsWithNeuron) {
    double w1[] = { 1.0, 2.0, 3.0, 4.0};
    double w2[] = { 5.0, 6.0, 7.0, 8.0};

    neuron->setWeights(w1, 4);
    ASSERT_EQ(70, neuron->dot(w2, 4));
  }

  TEST_F(NeuronTest, CannotDotMismatchedWeights) {
    double w1[] = { 1.0, 2.0, 3.0, 4.0};
    double w2[] = { 5.0, 6.0, 7.0, 8.0, 9.0};

    neuron->setWeights(w1, 4);
    EXPECT_DEATH(neuron->dot(w2, 5), "Assertion `this->getLength\\(\\) == length' failed");
  }

  TEST_F(NeuronTest, HasUniqueIds) {
    delete neuron;
    Neuron::resetIdCounter();

    neuron = new Neuron(5);
    Neuron neuron1(5);
    Neuron neuron2(5);

    ASSERT_EQ(neuron->getId(), 0);
    ASSERT_EQ(neuron1.getId(), 1);
    ASSERT_EQ(neuron2.getId(), 2);
  }
} // namespace
