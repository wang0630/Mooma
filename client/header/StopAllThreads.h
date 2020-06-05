#ifndef SAT_H_
#define SAT_H_
#include "Func.h"
#include "ThreadPool.h"

class StopAllThreads: public Func {
  public:
    virtual void operator()();
};
#endif