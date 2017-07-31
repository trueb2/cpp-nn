//
// Created by jwtrueb on 7/31/17.
//

#include "gtest/gtest.h"
#include "../../src/foo/Bar.h"

namespace {
  //The fixture for testing class Foo
  class BarTest : public ::testing::Test {
  protected:
    BarTest() {
        // setup work goes here
    }

    virtual ~BarTest() {
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

  // Tests that the Bar::add() method adds
  TEST_F(BarTest, AddMethodAddsInputs) {
    const int x = 1;
    const int y = 2;
    Bar b;
    ASSERT_EQ(3, b.add(x,y)) << "Bar::add(1,2) should return 3";
  }

  // Tests that the Bar::sub() method subtracts
  TEST_F(BarTest, SubMethodSubtractsInputs) {
    const int x = 5;
    const int y = 10;
    Bar b;
    ASSERT_EQ(-5, b.sub(5, 10));
  }

} // namespace
