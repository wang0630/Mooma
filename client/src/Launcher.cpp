#pragma comment(lib, "Advapi32.lib")
#include <windows.h>
#include <winreg.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  // Move exe
  char* dest = getenv("HOMEPATH");
  if (!dest) {
    cout << "Can't find the path" << endl;
    return 0;
  }
  char exepath[80] = {0};
  sprintf(exepath, "C:%s\\Mooma.exe", dest);
  cout << exepath << endl;
  if (!MoveFileExA("a.exe", exepath, MOVEFILE_REPLACE_EXISTING)) {
    cout << "Fail to move files" << endl;
    return 0;
  }
  HKEY hkey = NULL;
  long createStatus = RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0L, KEY_ALL_ACCESS, &hkey);


  long status = RegSetValueEx(hkey, "Mooma", 0, REG_SZ, (BYTE *)exepath, sizeof(exepath));
  getchar();
}
