#include "set.h"
#include <gtest/gtest.h>

TEST(SetTest, InitializerList) {
    s21::set<int> mySet = {1, 0, 2, 4, 3, 10, 9, 6, 7};
    EXPECT_EQ(mySet.contains(5), false);
    EXPECT_EQ(mySet.contains(1), true);
    EXPECT_EQ(mySet.contains(0), true);
    EXPECT_EQ(mySet.contains(2), true);
    EXPECT_EQ(mySet.contains(4), true);
    EXPECT_EQ(mySet.contains(13), false);
    EXPECT_EQ(mySet.contains(10), true);
    EXPECT_EQ(mySet.contains(3), true);
}
TEST(SetTest, Insertion) {
    s21::set<int> mySet; 
    mySet.insert(0);
    mySet.insert (2);
    mySet.insert(9);
    mySet.insert(7);
    EXPECT_EQ(mySet.contains(9), true);
    EXPECT_EQ(mySet.contains(0), true);
    EXPECT_EQ(mySet.contains(2), true);
    EXPECT_EQ(mySet.contains(7), true);
 }
/*
TEST(SetTest, AssignmentOperator) {
    s21::set<int> mySet;
    mySet.Insert(5);
    mySet.Insert(10);
    s21::set<int> assignedSet;
    assignedSet = mySet;
    EXPECT_NE(assignedSet.contains(5), assignedSet.end());
    EXPECT_NE(assignedSet.find(10), assignedSet.end());
}
*/

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
  // s21::set<int> a;
  //   mySet.insert(0);
  //   mySet.insert (2);
  //   mySet.insert(9);
  //   mySet.insert(7);
  // std::cout<<a.contains(2);
  // std::cout << a. contains(3);
  // std::cout<<a.contains(0);
  // std::cout<<a.contains(9);
  // std::cout<<a.contains(7);
  return 0;
}