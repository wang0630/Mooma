#include "Func.h"

bool Func::stop = false;

bool Func::getStop() {
  return stop;
}

void Func::setStop() {
  stop = true;
}