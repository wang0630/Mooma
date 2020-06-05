#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_
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
#endif
