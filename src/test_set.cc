#include "set.h"
#include <iostream>
#include <set>

int main() {
  s21::set<int> sint = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  std::cout<<sint.contains(5);
  return 0;
}