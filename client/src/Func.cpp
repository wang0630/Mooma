#include "Func.h"

volatile bool Func::stop = false;

bool Func::getStop() {
  return stop;
}

void Func::setStop() {
  stop = true;
}