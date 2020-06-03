#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include "RandomMouse.h"

void RandomMouse::operator()() {
  while(1) {
    srand(time(NULL));
    SetCursorPos(rand(), rand());
  }
}
