#include "map.h"
#include <gtest/gtest.h>
#include <string>
#include <utility>
using key_value = std::pair<int, std::string>;
TEST(mapTest, Constructors) {
  s21::map<int, std::string> initList = {std::pair<int, std::string>(1, "abc"),
                                         std::pair<int, std::string>(2, "ced"),
                                         std::pair<int, std::string>(3, "efd"),
                                         std::pair<int, std::string>(4, "qwe")};
  s21::map<int, std::string> copyCons(initList);
  s21::map<int, std::string> moveCons(std::move(initList));
  EXPECT_EQ(copyCons.contains(1), true);
//   EXPECT_EQ(copyCons.contains(key_value(2, "ced")), true);
  //   EXPECT_EQ(copyCons.contains(3), true);
  //   EXPECT_EQ(copyCons.contains(4), true);
  //   EXPECT_EQ(moveCons.contains(1), true);
  //   EXPECT_EQ(moveCons.contains(2), true);
  //   EXPECT_EQ(moveCons.contains(3), true);
  //   EXPECT_EQ(moveCons.contains(4), true);
  //   EXPECT_EQ(initList.contains(1), false);
  //   EXPECT_EQ(initList.contains(2), false);
  //   EXPECT_EQ(initList.contains(3), false);
  //   EXPECT_EQ(initList.contains(4), false);
  //   EXPECT_EQ(initList.size(), 0);
  //   EXPECT_EQ(copyCons.size(), 4);
  //   EXPECT_EQ(moveCons.size(), 4);
}
// TEST(mapTest, InitializerList) {
//   s21::map<int, std::string> mymap = {std::pair(1, "abc"), std::pair(2,
//   "ced"),
//                                       std::pair(3, "efd") std::pair(4,
//                                       "qwe")};
//   EXPECT_NE(mymap.max_size(), 1);
//   EXPECT_EQ(mymap.contains(5), false);
//   EXPECT_EQ(mymap.contains(1), true);
//   EXPECT_EQ(mymap.contains(0), true);
//   EXPECT_EQ(mymap.contains(2), true);
//   EXPECT_EQ(mymap.contains(4), true);
//   EXPECT_EQ(mymap.contains(13), false);
//   EXPECT_EQ(mymap.contains(10), true);
//   EXPECT_EQ(mymap.contains(3), true);
//   EXPECT_EQ(mymap.size(), 9);
// }
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
//   s21::map<int, std::string> initList = {std::pair<int, std::string>(1, "abc"),
//                                          std::pair<int, std::string>(2, "ced"),
//                                          std::pair<int, std::string>(3, "efd"),
//                                          std::pair<int, std::string>(4, "qwe")};
//   s21::map<int, std::string> copyCons(initList);
//   s21::map<int, std::string> moveCons(std::move(initList));
//   ;
  return 0;
}