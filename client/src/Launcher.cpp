#pragma comment(lib, "Advapi32.lib")
#include <windows.h>
#include <winreg.h>
#include <iostream>

using namespace std;

int main() {
  cout << "In Launcher" << endl;
  const char path[30] = "C:\\USERS\\a.exe";
  HKEY hkey = NULL;
  // long createStatus = RegCreateKeyEx(HKEY_CURRENT_USER, "\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, REG_OPTION_NON_VOLATILE, 
  // KEY_ALL_ACCESS, NULL, NULL, NULL);
  long createStatus = RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0L, KEY_ALL_ACCESS, &hkey);


  long status = RegSetValueEx(hkey, "Mooma", 0, REG_SZ, (BYTE *)path, sizeof(path));
  getchar();
}
