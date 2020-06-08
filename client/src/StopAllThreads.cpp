#include <string>
#include <iostream>
#include "StopAllThreads.h"

using namespace std;

void StopAllThreads::operator()() {
  cout << "Detect stop\n";
  this->setStop();
}