//
// Created by jwtrueb on 7/31/17.
//

#include <iostream>
#include "gtest/gtest.h"
#include "../../src/neural/layers/NeuralLayer.h"
#include "../../src/functions/SigmoidFunction.h"

namespace {
  //The fixture for testing class Neuron
  class NeuralLayerTest : public ::testing::Test {
  protected:
    NeuralLayerTest() {
      // setup work goes here
    }

    virtual ~NeuralLayerTest() {
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

  TEST_F(NeuralLayerTest, CanCreateNeuralLayer) {
    SigmoidFunction sigmoid;
    NeuralLayer nl(2,3,&sigmoid);

    ASSERT_EQ(2, nl.getNeuronCount());
    ASSERT_EQ(3, nl.getNeuronLength());
    ASSERT_EQ("Sigmoid", nl.getActivationFunctionName());
  }

  TEST_F(NeuralLayerTest, MultipleLayersHaveUniqueIds) {
    NeuralLayer::resetIdCounter();

    SigmoidFunction sigmoid;
    NeuralLayer nl(1,1,&sigmoid);
    NeuralLayer nl1(2,2,&sigmoid);
    NeuralLayer nl2(3,3,&sigmoid);

    ASSERT_EQ(0, nl.getId());
    ASSERT_EQ(1, nl1.getId());
    ASSERT_EQ(2, nl2.getId());
  }
} // namespace
