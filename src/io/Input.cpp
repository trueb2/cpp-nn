//
// Created by jwtrueb on 8/1/17.
//

#include <sstream>
#include "Input.h"

int Input::idCounter = 0;

Input::Input(double* data, int dataLength, double* labels, int labelsLength)
    : data(data), dataLength(dataLength), labels(labels), labelsLength(labelsLength) {
  id = idCounter++;
}

Input::Input(std::vector<std::string> strData) {
  dataLength = static_cast<int>(strData.size());
  data = new double[dataLength];
  int i = 0;
  for(const auto &strDouble : strData) {
    std::stringstream ds(strDouble);
    double d;
    ds >> d;
    data[i++] = d;
  }
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

void Input::setLabels(std::vector<std::string> vector) {
  labelsLength = static_cast<int>(vector.size());
  labels = new double[labelsLength];
  int i = 0;
  for(const auto& strDouble : vector) {
    std::stringstream ds(strDouble);
    double d;
    ds >> d;
    labels[i++] = d;
  }
}

std::ostream& operator<<(std::ostream & strm, const Input & input) {
  strm << "Input(";
  for(int i = 0; i < input.dataLength-1; i++) {
    strm << input.data[i] << ",";
  }
  return strm << input.data[input.dataLength - 1] << ")";
}
