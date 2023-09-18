#include <list>

#include "../list/list.h"
#include "all_tests.h"

bool listsEqual(s21::list<int> L1, std::list<int> L2) {
  if (L1.size() != L2.size()) return false;
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  for (; it_L1 != L1.end(); ++it_L1, ++it_L2)
    if (*it_L1 != *it_L2) return false;
  return true;
}

TEST(ListTest, DefaultConstructor) {
  s21::list<int> L1;
  std::list<int> L2;
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, SizeConstructor) {
  s21::list<int> L1(3);
  std::list<int> L2(3);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, CopyConstructor) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2(L1);
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4(L3);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, MoveConstructor) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2(std::move(L1));
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4(std::move(L3));
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, Empty) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(ListTest, EmptyN) {
  s21::list<int> L1(1);
  std::list<int> L2(1);
  ASSERT_EQ(L1.empty(), L2.empty());

  s21::list<int> L3(0);
  std::list<int> L4(0);
  ASSERT_EQ(L3.empty(), L4.empty());

  s21::list<int> L5(0);
  std::list<int> L6(0);
  L5.push_back(0);
  L6.push_back(0);
  ASSERT_EQ(L5.empty(), L6.empty());
  L5.pop_front();
  L6.pop_front();
  ASSERT_EQ(L5.empty(), L6.empty());
}

TEST(ListTest, EmptyList) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  ASSERT_EQ(L1.empty(), L2.empty());

  s21::list<int> L3 = {1};
  std::list<int> L4 = {1};
  ASSERT_EQ(L3.empty(), L4.empty());

  L1.push_back(1);
  L2.push_back(1);
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(ListTest, EmptyCopy) {
  s21::list<int> L1;
  s21::list<int> L2(L1);
  std::list<int> L3;
  std::list<int> L4(L3);
  ASSERT_EQ(L2.empty(), L4.empty());

  s21::list<int> L5 = {1};
  s21::list<int> L6(L5);
  std::list<int> L7 = {1};
  std::list<int> L8(L7);
  ASSERT_EQ(L6.empty(), L8.empty());
}

TEST(ListTest, EmptyMove) {
  s21::list<int> L1;
  s21::list<int> L2(std::move(L1));
  std::list<int> L3;
  std::list<int> L4(std::move(L3));
  ASSERT_EQ(L1.empty(), L3.empty());
  ASSERT_EQ(L2.empty(), L4.empty());
}

TEST(ListTest, SwapOneListEmpty) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {};
  L1.swap(L2);
  L3.swap(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, SwapOneListEmpty2) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, SwapBothEmpty) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {};
  std::list<int> L3 = {};
  std::list<int> L4 = {};
  L1.swap(L2);
  L3.swap(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, SwapSameSize) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, SwapDiffSize) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, SwapDiffSize2) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6, 128, 40};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6, 128, 40};
  L1.swap(L2);
  L3.swap(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, Reverse5) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};
  L1.reverse();
  L2.reverse();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Reverse4) {
  s21::list<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};
  L1.reverse();
  L2.reverse();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Reverse1) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.reverse();
  L2.reverse();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Reverse0) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  L1.reverse();
  L2.reverse();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertStart) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertMiddle) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertStart2) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertEnd) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ++it_L1;
  ++it_L2;
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertStartEnd) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ++it_L1;
  ++it_L1;
  ++it_L2;
  ++it_L2;
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertEmpty) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, MaxSize) {
  s21::list<double> L1;
  std::list<double> L2;
  ASSERT_EQ(L1.max_size(), L2.max_size());
}

TEST(ListTest, EraseFirst) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.erase(it_L1);
  L2.erase(it_L2);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, EraseLast) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = --L1.end();
  std::list<int>::iterator it_L2 = --L2.end();
  L1.erase(it_L1);
  L2.erase(it_L2);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, EraseMiddle) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  L1.erase(it_L1);
  L2.erase(it_L2);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Sort) {
  s21::list<int> L1 = {9, 2, 3, 1, 4};
  std::list<int> L2 = {9, 2, 3, 1, 4};
  L1.sort();
  L2.sort();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Sort2) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.sort();
  L2.sort();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Sort3) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  L1.sort();
  L2.sort();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, SortString) {
  s21::list<std::string> L1 = {"abcd", "abcdef", "abc"};
  std::list<std::string> L2 = {"abcd", "abcdef", "abc"};
  L1.sort();
  L2.sort();
  s21::list<std::string>::iterator it_L1 = L1.begin();
  std::list<std::string>::iterator it_L2 = L2.begin();
  for (; it_L2 != L2.end(); ++it_L2, ++it_L1) {
    ASSERT_EQ(*it_L1, *it_L2);
  }
}

TEST(ListTest, SortSorted) {
  s21::list<int> L1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  L1.sort();
  L2.sort();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, MergeIdentical) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {1, 2, 3, 4, 5};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {1, 2, 3, 4, 5};
  L1.merge(L2);
  L3.merge(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, MergeFirstEmpty) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {5, 4, 3, 2, 1};
  std::list<int> L3 = {};
  std::list<int> L4 = {5, 4, 3, 2, 1};
  L1.merge(L2);
  L3.merge(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, MergeSecondEmpty) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {};
  L1.merge(L2);
  L3.merge(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, Merge1) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {6, 7, 8, 9, 10};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {6, 7, 8, 9, 10};
  L1.merge(L2);
  L3.merge(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, Merge2) {
  s21::list<int> L1 = {1, 3, 5, 7};
  s21::list<int> L2 = {2, 4, 6, 8};
  std::list<int> L3 = {1, 3, 5, 7};
  std::list<int> L4 = {2, 4, 6, 8};
  L1.merge(L2);
  L3.merge(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, MergeStrings) {
  s21::list<std::string> L1 = {"abc", "abcd", "abcdef"};
  s21::list<std::string> L2 = {"ab", "abcde"};
  std::list<std::string> L3 = {"abc", "abcd", "abcdef"};
  std::list<std::string> L4 = {"ab", "abcde"};
  L1.merge(L2);
  L3.merge(L4);
  s21::list<std::string>::iterator it_L1 = L1.begin();
  s21::list<std::string>::iterator it_L2 = L2.begin();
  std::list<std::string>::iterator it_L3 = L3.begin();
  std::list<std::string>::iterator it_L4 = L4.begin();
  for (; it_L3 != L3.end(); ++it_L3, ++it_L1) ASSERT_EQ(*it_L1, *it_L3);
  for (; it_L4 != L4.end(); ++it_L4, ++it_L2) ASSERT_EQ(*it_L2, *it_L4);
}

TEST(ListTest, Unique) {
  s21::list<int> L1 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
  std::list<int> L2 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
  L1.unique();
  L2.unique();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, Unique2) {
  s21::list<int> L1 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
  std::list<int> L2 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
  L1.unique();
  L2.unique();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, UniqueEmpty) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  L1.unique();
  L2.unique();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, UniqueOne) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.unique();
  L2.unique();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, SpliceFirst) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {4, 5, 6, 1, 2, 3};
  s21::list<int>::const_iterator it = L1.begin();
  L1.splice(it, L2);
  EXPECT_TRUE(listsEqual(L1, result));
  EXPECT_TRUE(listsEqual(L2, empty_list));
}

TEST(ListTest, SpliceSecond) {
  s21::list<int> L1 = {1, 2};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {1, 4, 5, 6, 2};
  s21::list<int>::const_iterator it = ++L1.begin();
  L1.splice(it, L2);
  EXPECT_TRUE(listsEqual(L1, result));
  EXPECT_TRUE(listsEqual(L2, empty_list));
}

TEST(ListTest, SpliceEmpty) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {4, 5, 6};
  s21::list<int>::const_iterator it = L1.begin();
  L1.splice(it, L2);
  EXPECT_TRUE(listsEqual(L1, result));
  EXPECT_TRUE(listsEqual(L2, empty_list));
}

TEST(ListTest, SpliceFromEmpty) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {};
  std::list<int> empty_list = {};
  std::list<int> result = {1, 2, 3};
  s21::list<int>::const_iterator it = L1.begin();
  L1.splice(it, L2);
  EXPECT_TRUE(listsEqual(L1, result));
  EXPECT_TRUE(listsEqual(L2, empty_list));
}

TEST(ListTest, FrontEmpty) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.front(), L2.front());
}

TEST(ListTest, Front) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.front(), L2.front());
}

TEST(ListTest, BackEmpty) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.back(), L2.back());
}

TEST(ListTest, Back) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.back(), L2.back());
}

TEST(ListTest, PushFront) {
  s21::list<int> L1;
  std::list<int> L2;
  L1.push_front(1);
  L2.push_front(1);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, PushBack) {
  s21::list<int> L1;
  std::list<int> L2;
  L1.push_back(1);
  L2.push_back(1);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, PopFront) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.pop_front();
  L2.pop_front();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, PopBack) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.pop_back();
  L2.pop_back();
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, IteratorIncrement) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ListTest, IteratorIncrement2) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin()++;
  std::list<int>::iterator it_L2 = L2.begin()++;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ListTest, IteratorDecrement) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin()--;
  std::list<int>::iterator it_L2 = L2.begin()--;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ListTest, Dereference) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ListTest, Dereference2) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  *it_L1 = 128;
  *it_L2 = 128;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ListTest, NotEqual) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.begin() != L1.begin(), L2.begin() != L2.begin());
}

TEST(ListTest, Equal) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.begin() == L1.begin(), L2.begin() == L2.begin());
}

TEST(ListTest, EqualCopy) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = L2;
  L3 = L4;
  EXPECT_TRUE(listsEqual(L1, L3));
  EXPECT_TRUE(listsEqual(L2, L4));
}

TEST(ListTest, EqualMove) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = std::move(L2);
  L3 = std::move(L4);
  EXPECT_TRUE(listsEqual(L1, L3));
}

TEST(ListTest, InsertMany) {
  s21::list<int> L1 = {1, 5, 6};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6};
  L1.insert_many(++L1.begin(), 2, 3, 4);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertManyBack) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6};
  L1.insert_many_back(6);
  EXPECT_TRUE(listsEqual(L1, L2));
}

TEST(ListTest, InsertManyFront) {
  s21::list<int> L1 = {5, 6};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6};
  L1.insert_many_front(1, 2, 3, 4);
  EXPECT_TRUE(listsEqual(L1, L2));
}