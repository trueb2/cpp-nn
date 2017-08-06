//
// Created by jwtrueb on 7/31/17.
//

#include <iostream>
#include "gtest/gtest.h"
#include "../../src/neural/NeuralNetwork.h"
#include "../../src/functions/SigmoidFunction.h"
#include "../../src/io/OneHotAdapter.h"
#include "../../src/neural/layers/OutputLayer.h"

namespace {
  //The fixture for testing class Neuron
  class NeuralNetworkTest : public ::testing::Test {
  protected:
    NeuralNetworkTest() {
      // setup work goes here
    }

    virtual ~NeuralNetworkTest() {
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

  TEST_F(NeuralNetworkTest, CanCreateNeuralNetworkWithOneLayer) {
    NeuralLayer** nls = new NeuralLayer*[1];
    SigmoidFunction* s = new SigmoidFunction();
    nls[0] = new OutputLayer(5,10,s);
    OneHotAdapter oha(5);

    NeuralNetwork* nn = new NeuralNetwork(nls, 1, &oha);
    ASSERT_EQ(1, nn->getLayerCount());
    delete nn;
    delete s;
  }

  TEST_F(NeuralNetworkTest, CanCreateNeuralNetworkWithMultipleLayers) {
    NeuralLayer** nls = new NeuralLayer*[3];
    SigmoidFunction s;
    OneHotAdapter oha(5);
    nls[0] = new NeuralLayer(5, 10, &s);
    nls[1] = new NeuralLayer(4, 5, &s);
    nls[2] = new OutputLayer(3, 4, &s);

    NeuralNetwork* nn = new NeuralNetwork(nls, 3, &oha);
    ASSERT_EQ(3, nn->getLayerCount());
    delete nn;
  }

  TEST_F(NeuralNetworkTest, CannotCreateMalformedNeuralNetwork) {
    NeuralLayer** nls = new NeuralLayer*[2];
    SigmoidFunction s;
    OneHotAdapter oha(20);
    nls[0] = new NeuralLayer(20,10,&s);
    nls[0] = new OutputLayer(20,10,&s);

    NeuralNetwork *nn = nullptr;
    // TODO: find out why assertion fails without message
    EXPECT_DEATH(nn = new NeuralNetwork(nls, 2, &oha), "");
    delete nn;
  }
} // namespace
