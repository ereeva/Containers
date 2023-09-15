#include "set.h"
#include <set>
#include <iostream>

int main() {
  s21::set<int> sint = {1, 0, 2};
  s21::set<int> m;
  std::set<int> c;
  std::set<int>::iterator ptr =c.begin();
  std::cout << *ptr;
  ++ptr;
  std::cout << *ptr;
//   ++ptr;
//   std::cout << *ptr;
  return 0;
}