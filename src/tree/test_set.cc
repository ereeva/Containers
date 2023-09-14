#include <iostream>
#include <string>
#include "rb_tree.h"

int main() {
  int a_int[3] = {1, 2, 3};
  s21::RBTree<int> tree;
  s21::RBTree<std::string> set_string;
  std::string a = "abc";
  std::string b = "def";
  std::string c = "gh";
  tree.Insert(a_int[2]);
  tree.Insert(a_int[1]);
  tree.Insert(a_int[0]);
  set_string.Insert(c);
  set_string.Insert(b);
  set_string.Insert(a);
  s21::RBTree<int>::iterator ptr = tree.begin();
  std::cout << *ptr;
  ++ptr;
  std::cout << *ptr;
  ++ptr;
  std::cout << *ptr;
  s21::RBTree<std::string>::iterator str = set_string.begin();
  std::cout << *str;
  ++str;
  std::cout << *str;
  ++str;
  std::cout << *str;

}