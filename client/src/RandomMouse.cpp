#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <iostream>
#include "RandomMouse.h"

using namespace std;

void RandomMouse::operator()() {
  while(!this->getStop()) {
    srand(time(NULL));
    Sleep(2000);
    // cout << this->getStop() << endl;
    SetCursorPos(rand() % 1500, rand() % 1500);
    // cout << "in random mouse" << endl;
  }
}
