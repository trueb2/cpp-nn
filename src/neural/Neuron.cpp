//
// Created by jwtrueb on 7/31/17.
//

#include <cassert>
#include "Neuron.h"

int Neuron::idCounter = 0;

Neuron::Neuron(int length): length(length) {
  id = idCounter++;
  weights = new double[length];
  for(int i = 0; i < length; i++) {
    weights[i] = 0.0;
  }
}

Neuron::~Neuron() {
  delete[] weights;
}

void Neuron::resetIdCounter() {
  idCounter = 0;
}

void Neuron::setWeights(const double* weights, const int length) {
  // check that the new length is reasonable
  assert(length > 0);

  // free the old weights
  delete [] this->weights;

  // make a copy of the weights
  this->weights = new double[length];
  for(int i = 0; i < length; i++) {
    this->weights[i] = weights[i];
  }

  // update the length of the weights
  this->length = length;
}

double* Neuron::getWeights() {
  return weights;
}

int Neuron::getLength() {
  return length;
}

int Neuron::getId() {
  return id;
}

double Neuron::dot(const double* weights, const int length) {
  // weights must be the same length
  assert(this->getLength() == length);

  // reduce inner dot product
  double inner_dot_product = 0.0;
  for(int i =0; i < length; i++) {
    inner_dot_product += weights[i] * this->weights[i];
  }

  return inner_dot_product;
}

void Neuron::addToWeights(const double* values) {
  for(int i = 0; i < length; i++) {
    weights[i] += values[i];
  }
}
