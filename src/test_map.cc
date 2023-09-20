#include "map.h"
#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>
TEST(mapTest, Constructors) {
  s21::map<int, std::string> initList = {
      {1, "qw"}, {2, "ced"}, {3, "efd"}, {4, "abc"}};
  s21::map<int, std::string> copyCons(initList);
  s21::map<int, std::string> moveCons(std::move(initList));
  EXPECT_EQ(copyCons.contains(1), true);
  EXPECT_EQ(copyCons.contains(2), true);
  EXPECT_EQ(copyCons.contains(3), true);
  EXPECT_EQ(copyCons.contains(4), true);
  EXPECT_EQ(moveCons.contains(1), true);
  EXPECT_EQ(moveCons.contains(2), true);
  EXPECT_EQ(moveCons.contains(3), true);
  EXPECT_EQ(moveCons.contains(4), true);
  EXPECT_EQ(initList.contains(1), false);
  EXPECT_EQ(initList.contains(2), false);
  EXPECT_EQ(initList.contains(3), false);
  EXPECT_EQ(initList.contains(4), false);
  EXPECT_EQ(initList.size(), 0);
  EXPECT_EQ(copyCons.size(), 4);
  EXPECT_EQ(moveCons.size(), 4);
}
TEST(mapTest, operator_) {
  s21::map<int, std::string> mymap = {{1, "abc"},
                                      {2, "ced"},
                                      {3, "efd"},
                                      {4, "qwe"}};
  EXPECT_EQ(mymap[1], "abc");
  EXPECT_EQ(mymap[2], "ced");
  EXPECT_EQ(mymap[3], "efd");
  EXPECT_EQ(mymap[4], "qwe");
  mymap[1] = "aaa";
  mymap[4] = "bbb";
  EXPECT_EQ(mymap[1], "aaa");
  EXPECT_EQ(mymap[4], "bbb");
  mymap[5] = "blabla";
  EXPECT_EQ(mymap[5], "blabla");
  s21::map<int, std::string> mcmap = std::move(mymap);
  EXPECT_EQ(mcmap[5], "blabla");
  EXPECT_EQ(mymap.size(), 0);
  EXPECT_ANY_THROW (mcmap.at(6));
}
TEST(mapTest, Insertion) {
  s21::map<int, std::string> mymap;
  EXPECT_EQ(mymap.contains(0), false);
  mymap.insert(0);
  mymap.insert(2);
  mymap.insert(9);
  mymap.insert(7);
  mymap.insert_or_assign(7, "bla");
  EXPECT_EQ(mymap.at(7), "bla");
  EXPECT_EQ(mymap.contains(9), true);
  EXPECT_EQ(mymap.contains(0), true);
  EXPECT_EQ(mymap.contains(2), true);
  EXPECT_EQ(mymap.contains(7), true);
  int i = mymap.size();
  for (auto &it : mymap)
    i--;
  EXPECT_EQ(i, 0);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}