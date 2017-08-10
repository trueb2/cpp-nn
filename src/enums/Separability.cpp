//
// Created by Jacob Trueb on 8/9/17.
//

#include "Separability.h"

namespace SeparabilityStr {
  const char* enumStrs[] = { "lin", "poly", "" };

  const char* strForEnum(Separability separability) {
    return enumStrs[separability];
  }
}