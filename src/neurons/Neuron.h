//
// Created by jwtrueb on 7/31/17.
//

#ifndef CPPNN_NEURON_H
#define CPPNN_NEURON_H


class Neuron {
public:
  double* getWeights();
  int getLength();
  explicit Neuron(int length);
  ~Neuron();

private:
  double* weights;
  int length;

};


#endif //CPPNN_NEURON_H
