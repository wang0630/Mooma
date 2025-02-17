#include "ThreadPool.h"

using namespace std;

void ThreadPool::setThread(Func* func) {
  thread mthread(ref(*func));
  ThreadPool::threadPool.push_back(&mthread);
  mthread.detach();
}
