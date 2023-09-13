#include <iostream>
#include "rb_tree.h"

int main() {
  int a[3] = {1, 2, 3};
  s21::RBTree<int> tree;
  tree.Insert(a[0]);
  tree.Insert(a[1]);
  tree.Insert(a[2]);
  s21::RBTree<int>::iterator ptr = tree.begin();
  std::cout << *ptr++;
  std::cout << *ptr++;
  std::cout << *ptr;
}