//
// Created by Jacob Trueb on 8/9/17.
//
#ifndef CPPNN_SEPARABILITY_H
#define CPPNN_SEPARABILITY_H

enum Separability {
  linear,
  polynomial,
  unknown
};

namespace SeparabilityStr
{

  const char* strForEnum(Separability separability);
}

#endif //CPPNN_SEPARABILITY_H