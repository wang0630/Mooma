#include <string>
#include <iostream>
#include "StopAllThreads.h"

using namespace std;

void StopAllThreads::operator()() {
  /* 
    Called when stop is enter
  */
  // string stopKey("asdf");
  // string s("");
  // while(s.compare(stopKey) != 0) {
  //   s.clear();
  //   cin >> s;
  // }
  // // Stop all threads
  // cout << "Detect stop\n";
  this->setStop();
}