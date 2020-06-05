#include "Func.h"
#include "ThreadPool.h"

class StopAllThreads: public Func {
  public:
    virtual void operator()();
};