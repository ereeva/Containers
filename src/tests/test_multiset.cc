#include "../multiset/s21_multiset.h"
#include "../vector/vector.h"
#include <gtest/gtest.h>

TEST(multisetTest, Constructors) {
  s21::multiset<int> initList = {1, 2, 3, 4};
  s21::multiset<int> copyCons(initList);
  s21::multiset<int> moveCons(std::move(initList));
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
TEST(multisetTest, InitializerList) {
  s21::multiset<int> mymultiset = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  EXPECT_NE(mymultiset.max_size(), 1);
  EXPECT_EQ(mymultiset.contains(5), false);
  EXPECT_EQ(mymultiset.contains(1), true);
  EXPECT_EQ(mymultiset.contains(0), true);
  EXPECT_EQ(mymultiset.contains(2), true);
  EXPECT_EQ(mymultiset.contains(4), true);
  EXPECT_EQ(mymultiset.contains(13), false);
  EXPECT_EQ(mymultiset.contains(10), true);
  EXPECT_EQ(mymultiset.contains(3), true);
  EXPECT_EQ(mymultiset.size(), 9);
}
TEST(multisetTest, Insertion) {
  s21::multiset<int> mymultiset;
  EXPECT_EQ(mymultiset.contains(0), false);
  mymultiset.insert(0);
  mymultiset.insert(2);
  mymultiset.insert(9);
  mymultiset.insert(7);
  EXPECT_EQ(mymultiset.contains(9), true);
  EXPECT_EQ(mymultiset.contains(0), true);
  EXPECT_EQ(mymultiset.contains(2), true);
  EXPECT_EQ(mymultiset.contains(7), true);
  int i = mymultiset.size();
  for (auto &it : mymultiset)
    i--;
  EXPECT_EQ(i, 0);
}

TEST(multisetTest, RengeBasedFor) {
  s21::multiset<int> mymultiset = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  int i = mymultiset.size();
  for (auto &it : mymultiset)
    i--;
  EXPECT_EQ(i, 0);
}
TEST(multisetTest, Erase) {
  s21::multiset<int> mymultiset = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  auto ptr = mymultiset.begin();
  for (int i = 0; i < 4; i++)
    ptr++;
  mymultiset.erase(ptr);
  EXPECT_EQ(mymultiset.size(), 8);
}

TEST(multisetTest, Swap) {
  s21::multiset<int> mymultiset = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  s21::multiset<int> mymultiset2;
  mymultiset.swap(mymultiset2);
  EXPECT_EQ(mymultiset.size(), 0);
  EXPECT_EQ(mymultiset2.contains(3), 1);
}

TEST(multisetTest, Find) {
  s21::multiset<int> mymultiset = {1, 0, 2, 4, 3, 10, 9, 6, 7};
  s21::multiset<int>::iterator ptr = mymultiset.find(10);
  EXPECT_EQ(*ptr, 10);
  ptr = mymultiset.find(1);
  EXPECT_EQ(*ptr, 1);
  ptr = mymultiset.find(0);
  ptr = mymultiset.find(6);
  EXPECT_EQ(*ptr, 6);
  ptr = mymultiset.find(17);
  EXPECT_EQ(*ptr, 0);
}

TEST(multisetTest, TestInsertMany) {
  s21::multiset<int> mymultiset;
  s21::vector<std::pair<s21::multiset<int>::iterator, bool>> res =
      mymultiset.insert_many(1, 2, 3, 4, 5, 6);
  EXPECT_EQ(mymultiset.contains(5), true);
  EXPECT_EQ(mymultiset.contains(6), true);
  for (auto &a : mymultiset)
    std::cout << a << std::endl;
  for (auto &a : res)
    EXPECT_EQ(a.second, true);
}
TEST(multisetTest, TestInsertEqual) {
  s21::multiset<int> initList = {2, 2, 2, 2};
  initList.erase(initList.find(2));
  for (auto &a : initList)
    std::cout << a << std::endl;
  EXPECT_EQ(initList.size(), 3);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}