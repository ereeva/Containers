#include "set.h"
#include <gtest/gtest.h>

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
    EXPECT_EQ(mySet.contains(0),  false);
    mySet.insert(0);
    mySet.insert (2);
    mySet.insert(9);
    mySet.insert(7);
    EXPECT_EQ(mySet.contains(9), true);
    EXPECT_EQ(mySet.contains(0), true);
    EXPECT_EQ(mySet.contains(2), true);
    EXPECT_EQ(mySet.contains(7), true);
    int i = mySet.size();
    for(auto &it : mySet)
        i--;
    EXPECT_EQ(i, 0); 
}


 TEST(SetTest, RengeBasedFor) {
    s21::set<int> mySet =  {1, 0, 2, 4, 3, 10, 9, 6, 7};
    int i = mySet.size();
    for(auto &it : mySet)
        i--;
    EXPECT_EQ(i, 0); 
}
 TEST(SetTest, Erase) {
    s21::set<int> mySet =  {1, 0, 2, 4, 3, 10, 9, 6, 7};
    auto ptr = mySet.begin();
    for(int i = 0; i<4; i++)ptr++;
    mySet.erase(ptr);
    EXPECT_EQ(mySet.size(), 8);
}

 TEST(SetTest, Swap) {
    s21::set<int> mySet =  {1, 0, 2, 4, 3, 10, 9, 6, 7};
    s21::set<int> mySet2;
    mySet.swap(mySet2);
    EXPECT_EQ(mySet.size(), 0);
    EXPECT_EQ(mySet2.contains(3), 1);
}

 TEST(SetTest, Find) {
    s21::set<int> mySet =  {1, 0, 2, 4, 3, 10, 9, 6, 7};
    mySet.find(6);
    EXPECT_EQ(*(mySet.find(6)), 6);
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
//   s21::set<int> mySet;
//     mySet.insert(0);
//     mySet.insert (2);
//     mySet.insert(9);
//     mySet.insert(7);
//       int i = mySet.size();
//       auto it_end = mySet.end();
//       auto it_begin = mySet.begin();
//     for(; it_begin != it_end; ++it_begin )
//         i--;
  // std::cout<<a.contains(2);
  // std::cout << a. contains(3);
  // std::cout<<a.contains(0);
  // std::cout<<a.contains(9);
  // std::cout<<a.contains(7);
  return 0;
}