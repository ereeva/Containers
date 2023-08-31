#include <list>

#include "../list/list.h"
#include "gtest/gtest.h"

TEST(List, Constructor_Default) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Constructor_Size) {
  s21::list<int> s21_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Constructor_List) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Constructor_Copy) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> s21_copy(s21_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
}

TEST(List, Operator_Copy) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> s21_copy;
  s21_copy = s21_list;
  std::list<int> std_copy;
  std_copy = std_list;
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
}

TEST(List, Constructor_Move) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> s21_copy(std::move(s21_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Operator_Move) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> s21_copy;
  s21_copy = std::move(s21_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Size) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Push_Front) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Push_Back) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Pop_Front) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Pop_Back) {
	s21::list<int> s21_list = {1, 2, 3, 4, 5};
	std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.pop_back();
  std_list.pop_back();
	EXPECT_EQ(s21_list.size(), std_list.size());
	EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Iterator_Begin) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(List, Iterator_BeginPlusAndMinus) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator s21_it = s21_list.begin();
  ++s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  --s21_it;
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(List, Iterator_End_Last) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator s21_it = s21_list.end();
  --s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(List, Iterator_Equals) {
  s21::list<int> first_list = {1, 2, 3};
  s21::list<int>::iterator s21_it_first = first_list.begin();
  s21::list<int>::iterator s21_it_second = first_list.begin();
  EXPECT_TRUE(s21_it_first == s21_it_second);
  ++s21_it_second;
  EXPECT_TRUE(s21_it_first != s21_it_second);
}

TEST(List, Insert) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  s21_list.insert(s21_it, 5);
  std_list.insert(std_it, 5);
	EXPECT_EQ(s21_list.size(), std_list.size());
	EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.insert(s21_it, 7);
  std_list.insert(std_it, 7);
  s21_list.insert(s21_it, 9);
  std_list.insert(std_it, 9);
	EXPECT_EQ(s21_list.size(), std_list.size());
	EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Erase) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());
	EXPECT_EQ(s21_list.size(), std_list.size());
	EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21::list<int>::iterator s21_it = s21_list.begin();
  ++s21_it;
  std::list<int>::iterator std_it = std_list.begin();
  ++std_it;
	EXPECT_EQ(s21_list.size(), std_list.size());
	EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Splice) {
  s21::list<int> s21_list_first = {1};
  s21::list<int> s21_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::list<int>::iterator s21_it = s21_list_first.begin();
  std::list<int>::iterator std_it = std_list_first.begin();
  s21_list_first.splice(s21_it, s21_list_second);
  std_list_first.splice(std_it, std_list_second);
	EXPECT_EQ(s21_list_first.size(), std_list_first.size());
	EXPECT_EQ(s21_list_first.front(), std_list_first.front());
  EXPECT_EQ(s21_list_first.back(), std_list_first.back());
}

TEST(List, Merge) {
  s21::list<int> s21_list_first = {1};
  s21::list<int> s21_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21_list_first.merge(s21_list_second);
  std_list_first.merge(std_list_second);
	EXPECT_EQ(s21_list_first.size(), std_list_first.size());
	EXPECT_EQ(s21_list_first.front(), std_list_first.front());
  EXPECT_EQ(s21_list_first.back(), std_list_first.back());
  EXPECT_EQ(s21_list_second.empty(), std_list_second.empty());
}

TEST(List, Reverse) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.reverse();
  std_list.reverse();
	EXPECT_EQ(s21_list.size(), std_list.size());
	EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Unique) {
  s21::list<int> s21_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21_list.unique();
  std_list.unique();
  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
	while(s21_it != s21_list.end())
  EXPECT_EQ(*s21_it++, *std_it++);
}

TEST(List, Sort) {
  s21::list<int> s21_list = {2, 4, 1, 3, 5};
  std::list<int> std_list = {2, 4, 1, 3, 5};
  s21_list.sort();
  std_list.sort();
  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
	while(s21_it != s21_list.end())
  EXPECT_EQ(*s21_it++, *std_it++);
}

TEST(List, Insert_Many) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator s21_it = s21_list.begin();
  ++s21_it;
  s21_list.insert_many(s21_it, 7, 8, 9);
  s21_it = s21_list.begin();
  EXPECT_EQ(*s21_it, 1);
  ++s21_it;
  EXPECT_EQ(*s21_it, 7);
  ++s21_it;
  EXPECT_EQ(*s21_it, 8);
  ++s21_it;
  EXPECT_EQ(*s21_it, 9);
  ++s21_it;
  EXPECT_EQ(*s21_it, 2);
}

TEST(List, Insert_Many_Back) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  s21_list.insert_many_back(7, 8, 9);
  s21::list<int>::iterator s21_it = s21_list.end();
  --s21_it;
  EXPECT_EQ(*s21_it, 9);
  --s21_it;
  EXPECT_EQ(*s21_it, 8);
  --s21_it;
  EXPECT_EQ(*s21_it, 7);
  --s21_it;
  EXPECT_EQ(*s21_it, 5);
  --s21_it;
  EXPECT_EQ(*s21_it, 4);
}

TEST(List, Insert_Many_Front) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  s21_list.insert_many_front(7, 8, 9);
  s21::list<int>::iterator s21_it = s21_list.begin();
  EXPECT_EQ(*s21_it, 7);
  ++s21_it;
  EXPECT_EQ(*s21_it, 8);
  ++s21_it;
  EXPECT_EQ(*s21_it, 9);
  ++s21_it;
  EXPECT_EQ(*s21_it, 1);
  ++s21_it;
  EXPECT_EQ(*s21_it, 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}