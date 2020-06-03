#include <string>
#include <iostream>
#include "StopAllThreads.h"

using namespace std;

void StopAllThreads::operator()() {
  /* 
    Read keyboard input
    If it is stop, stop all threads including the server
    else keep listening
  */
  string stopKey("asdf");
  string s("");
  while(s.compare(stopKey) != 0) {
    s.clear();
    cin >> s;
  }
  // Stop all threads
  cout << "Detect stop\n";
}