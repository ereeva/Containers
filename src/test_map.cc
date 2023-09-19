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
}
// TEST(mapTest, Insertion) {
//   s21::map<int, std::string> mymap;
//   EXPECT_EQ(mymap.contains(0), false);
//   mymap.insert(0);
//   mymap.insert(2);
//   mymap.insert(9);
//   mymap.insert(7);
//   EXPECT_EQ(mymap.contains(9), true);
//   EXPECT_EQ(mymap.contains(0), true);
//   EXPECT_EQ(mymap.contains(2), true);
//   EXPECT_EQ(mymap.contains(7), true);
//   int i = mymap.size();
//   for (auto &it : mymap)
//     i--;
//   EXPECT_EQ(i, 0);
// }

// TEST(mapTest, RengeBasedFor) {
//   s21::map<int, std::string> mymap = {std::pair(1, "abc"), std::pair(2,
//   "ced"),
//                                       std::pair(3, "efd") std::pair(4,
//                                       "qwe")};
//   int i = mymap.size();
//   for (auto &it : mymap)
//     i--;
//   EXPECT_EQ(i, 0);
// }
// TEST(mapTest, Erase) {
//   s21::map<int, std::string> mymap = {std::pair(1, "abc"), std::pair(2,
//   "ced"),
//                                       std::pair(3, "efd") std::pair(4,
//                                       "qwe")};
//   auto ptr = mymap.begin();
//   for (int i = 0; i < 4; i++)
//     ptr++;
//   mymap.erase(ptr);
//   EXPECT_EQ(mymap.size(), 8);
// }

// TEST(mapTest, Swap) {
//   s21::map<int, std::string> mymap = {std::pair(1, "abc"), std::pair(2,
//   "ced"),
//                                       std::pair(3, "efd") std::pair(4,
//                                       "qwe")};
//   s21::map<int, std::string> mymap2;
//   mymap.swap(mymap2);
//   EXPECT_EQ(mymap.size(), 0);
//   EXPECT_EQ(mymap2.contains(3), 1);
// }

// TEST(mapTest, Find) {
//   s21::map<int, std::string> mymap = {std::pair(1, "abc"), std::pair(2,
//   "ced"),
//                                       std::pair(3, "efd") std::pair(4,
//                                       "qwe")};
//   s21::map<int, std::string>::iterator ptr = mymap.find(10);
//   EXPECT_EQ(*ptr, 10);
//   ptr = mymap.find(1);
//   EXPECT_EQ(*ptr, 1);
//   ptr = mymap.find(0);
//   EXPECT_EQ(*ptr, 0);
//   ptr = mymap.find(6);
//   EXPECT_EQ(*ptr, 6);
//   ptr = mymap.find(17);
//   EXPECT_EQ(*ptr, 0);
// }
int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
    // std::map<int, std::string> m;
  //   s21::map<int, std::string> initList = {std::pair<int, std::string>(1,
  //   "abc"),
  //                                          std::pair<int, std::string>(2,
  //                                          "ced"), std::pair<int,
  //                                          std::string>(3, "efd"),
  //                                          std::pair<int, std::string>(4,
  //                                          "qwe")};
  //   s21::map<int, std::string> copyCons(initList);
  //   s21::map<int, std::string> moveCons(std::move(initList));
  //   ;
  return 0;
}