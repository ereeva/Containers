#include "set.h"
#include "vector/vector.h"
#include <gtest/gtest.h>

TEST(SetTest, Constructors) {
  s21::set<int> initList = {1, 2, 3, 4};
  s21::set<int> copyCons(initList);
  s21::set<int> moveCons(std::move(initList));
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
TEST(SetTest, InitializerList) {
  s21::set<int> mySet = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  EXPECT_NE(mySet.max_size(), 1);
  EXPECT_EQ(mySet.contains(5), false);
  EXPECT_EQ(mySet.contains(1), true);
  EXPECT_EQ(mySet.contains(0), true);
  EXPECT_EQ(mySet.contains(2), true);
  EXPECT_EQ(mySet.contains(4), true);
  EXPECT_EQ(mySet.contains(13), false);
  EXPECT_EQ(mySet.contains(10), true);
  EXPECT_EQ(mySet.contains(3), true);
  EXPECT_EQ(mySet.size(), 9);
}
TEST(SetTest, Insertion) {
  s21::set<int> mySet;
  EXPECT_EQ(mySet.contains(0), false);
  mySet.insert(0);
  mySet.insert(2);
  mySet.insert(9);
  mySet.insert(7);
  EXPECT_EQ(mySet.contains(9), true);
  EXPECT_EQ(mySet.contains(0), true);
  EXPECT_EQ(mySet.contains(2), true);
  EXPECT_EQ(mySet.contains(7), true);
  int i = mySet.size();
  for (auto &it : mySet)
    i--;
  EXPECT_EQ(i, 0);
}

TEST(SetTest, RengeBasedFor) {
  s21::set<int> mySet = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  int i = mySet.size();
  for (auto &it : mySet)
    i--;
  EXPECT_EQ(i, 0);
}
TEST(SetTest, Erase) {
  s21::set<int> mySet = {1, 0, 2,2, 4, 3, 10, 9, 6, 7};
  auto ptr = mySet.begin();
  for (int i = 0; i < 4; i++)
    ptr++;
  mySet.erase(ptr);
  EXPECT_EQ(mySet.size(), 8);
}

TEST(SetTest, Swap) {
  s21::set<int> mySet = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  s21::set<int> mySet2;
  mySet.swap(mySet2);
  EXPECT_EQ(mySet.size(), 0);
  EXPECT_EQ(mySet2.contains(3), 1);
}

TEST(SetTest, Find) {
  s21::set<int> mySet = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  s21::set<int>::iterator ptr = mySet.find(10);
  EXPECT_EQ(*ptr, 10);
  ptr = mySet.find(1);
  EXPECT_EQ(*ptr, 1);
  ptr = mySet.find(0);
  ptr = mySet.find(6);
  EXPECT_EQ(*ptr, 6);
  ptr = mySet.find(17);
  EXPECT_EQ(*ptr, 0);
}

TEST(SetTest, TestInsertMany) {
  s21::set<int> mySet;
  s21::vector<std::pair<s21::set<int>::iterator, bool>> res =
      mySet.insert_many(1, 2, 3, 4, 5, 6);
  EXPECT_EQ(mySet.contains(5), true);
  EXPECT_EQ(mySet.contains(6), true);
  for (auto &a : res)
    EXPECT_EQ(a.second, true);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
   return 0;
}