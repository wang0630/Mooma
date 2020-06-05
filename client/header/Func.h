#ifndef FUNC_H_
#define FUNC_H_
/*
  The functor to be send to the thread
*/
class Func {
  public:
    virtual void operator()() = 0;
    bool getStop();
    void setStop();
  private:
    static bool stop;
};
#endif