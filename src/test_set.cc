#include "set.h"
#include <iostream>
#include <set>

int main() {
  std::set<int> sint = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  sint.insert(2);
  std::set<int>::iterator ptr = sint.begin();
  std::cout << *ptr;
  ptr++;
  std::cout << *ptr;
  for (auto &ptr : sint) {
    std::cout << ptr;
  }
  return 0;
}