//
// Created by jwtrueb on 8/1/17.
//

#include "Input.h"

int Input::idCounter = 0;

Input::Input(double* data, int dataLength, double* labels, int labelsLength)
    : data(data), dataLength(dataLength), labels(labels), labelsLength(labelsLength) {
  id = idCounter++;
}

Input::~Input() {
  delete[] data;
  delete[] labels;
}

double* Input::getData() {
  return data;
}

int Input::getDataLength() {
  return dataLength;
}

double* Input::getLabels() {
  return labels;
}

int Input::getLabelsLength() {
  return labelsLength;
}

int Input::getId() {
  return id;
}

void Input::resetIdCounter() {
  idCounter = 0;
}
