#include <thread>
#include <vector>
#include <iostream>
#include "Func.h"

using namespace std;

class ThreadPool {
  public:
    void setThread(Func*);
  private:
    vector<thread*> threadPool;
};
