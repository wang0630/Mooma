#ifndef RANDOM_MOUSE_H_
#define RANDOM_MOUSE_H_

#include <windows.h>
#include <winuser.h>
#include "Func.h"

class RandomMouse: public Func {
  public:
    virtual void operator()();
};
#endif