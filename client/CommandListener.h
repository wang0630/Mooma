#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <memory>
#include <iostream>
#include <array>
#include "ThreadPool.h"
#include "StopAllThreads.h"

#define PORT_NUM (6666)
#define IP_ADDR ("127.0.0.1")

using namespace std;

class CommandListener
{
  private:
    /* data */
    SOCKET sConnect;
    SOCKADDR_IN addr;
    int r;
    char message[200];
  public:
    CommandListener();
    ~CommandListener();
    void startListening();
    void setupSocket();
    void handleCommand(const char* cmd);
    string executeCommand(const char* cmd);
    // Thread pool
    ThreadPool tp;
};