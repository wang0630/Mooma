#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include "RandomMouse.h"

void RandomMouse::operator()() {
  while(!this.getStop()) {
    srand(time(NULL));
    // SetCursorPos(rand(), rand());
    cout << "in random mouse" << endl;
  }
}
