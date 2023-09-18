#include <stack>

#include "../stack/stack.h"
#include "../vector/vector.h"
#include "all_tests.h"

TEST(StackTest, DefaultConstructor) {
  s21::stack<int> my_stack;
  std::stack<int> std_stack;

  ASSERT_EQ(my_stack.empty(), std_stack.empty());
  ASSERT_EQ(my_stack.size(), std_stack.size());
}

TEST(StackTest, PushAndTop) {
  s21::stack<int> my_stack;
  std::stack<int> std_stack;

  my_stack.push(1);
  std_stack.push(1);
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.push(2);
  std_stack.push(2);
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.push(3);
  std_stack.push(3);
  ASSERT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Pop) {
  s21::stack<int, s21::vector<int>> my_stack;
  std::stack<int, s21::vector<int>> std_stack;

  my_stack.push(1);
  std_stack.push(1);
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.push(2);
  std_stack.push(2);
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.push(3);
  std_stack.push(3);
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.pop();
  std_stack.pop();
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.pop();
  std_stack.pop();
  ASSERT_EQ(my_stack.top(), std_stack.top());

  my_stack.pop();
  std_stack.pop();
  ASSERT_EQ(my_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size) {
  s21::stack<int> my_stack;
  std::stack<int> std_stack;

  ASSERT_EQ(my_stack.size(), std_stack.size());

  my_stack.push(1);
  std_stack.push(1);
  ASSERT_EQ(my_stack.size(), std_stack.size());

  my_stack.push(2);
  std_stack.push(2);
  ASSERT_EQ(my_stack.size(), std_stack.size());

  my_stack.pop();
  std_stack.pop();
  ASSERT_EQ(my_stack.size(), std_stack.size());

  my_stack.push(3);
  std_stack.push(3);
  ASSERT_EQ(my_stack.size(), std_stack.size());

  my_stack.pop();
  std_stack.pop();
  ASSERT_EQ(my_stack.size(), std_stack.size());

  my_stack.pop();
  std_stack.pop();
  ASSERT_EQ(my_stack.size(), std_stack.size());
}

TEST(StackTest, Swap) {
  s21::stack<int> my_stack1;
  s21::stack<int> my_stack2;
  std::stack<int> std_stack1;
  std::stack<int> std_stack2;

  my_stack1.push(1);
  my_stack1.push(2);
  my_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  my_stack1.swap(my_stack2);
  std_stack1.swap(std_stack2);

  ASSERT_EQ(my_stack1.empty(), std_stack1.empty());
  ASSERT_EQ(my_stack1.size(), std_stack1.size());

  ASSERT_EQ(my_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(my_stack2.size(), std_stack2.size());

  ASSERT_EQ(my_stack2.top(), std_stack2.top());
}

TEST(StackTest, CopyConstructor) {
  s21::stack<int> my_stack1;
  std::stack<int> std_stack1;

  my_stack1.push(1);
  my_stack1.push(2);
  my_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::stack<int> my_stack2(my_stack1);
  std::stack<int> std_stack2(std_stack1);

  ASSERT_EQ(my_stack1.empty(), std_stack1.empty());
  ASSERT_EQ(my_stack1.size(), std_stack1.size());
  ASSERT_EQ(my_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(my_stack2.size(), std_stack2.size());
  ASSERT_EQ(my_stack1.top(), std_stack1.top());
  ASSERT_EQ(my_stack2.top(), std_stack2.top());
}

TEST(StackTest, MoveConstructor) {
  s21::stack<int> my_stack1;
  std::stack<int> std_stack1;

  my_stack1.push(1);
  my_stack1.push(2);
  my_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::stack<int> my_stack2(std::move(my_stack1));
  std::stack<int> std_stack2(std::move(std_stack1));

  ASSERT_EQ(my_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(my_stack2.size(), std_stack2.size());
  ASSERT_EQ(my_stack2.top(), std_stack2.top());
}

TEST(StackTest, CopyAssignmentOperator)
{
  s21::stack<int> my_stack1;
  std::stack<int> std_stack1;

  my_stack1.push(1);
  my_stack1.push(2);
  my_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::stack<int> my_stack2;
  std::stack<int> std_stack2;

  my_stack2 = my_stack1;
  std_stack2 = std_stack1;

  ASSERT_EQ(my_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(my_stack2.size(), std_stack2.size());
  ASSERT_EQ(my_stack2.top(), std_stack2.top());
}

TEST(StackTest, MoveAssignmentOperator) {
  s21::stack<int> my_stack1;
  std::stack<int> std_stack1;

  my_stack1.push(1);
  my_stack1.push(2);
  my_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::stack<int> my_stack2;
  std::stack<int> std_stack2;

  my_stack2 = std::move(my_stack1);
  std_stack2 = std::move(std_stack1);

  ASSERT_EQ(my_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(my_stack2.size(), std_stack2.size());
  ASSERT_EQ(my_stack2.top(), std_stack2.top());
}

TEST(StackTest, InitializerListConstructor) {
  s21::stack<int> my_stack({1, 2, 3});
  std::stack<int> std_stack({1, 2, 3});

  ASSERT_EQ(my_stack.empty(), std_stack.empty());
  ASSERT_EQ(my_stack.size(), std_stack.size());
  ASSERT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, InsertManyBack)
{
  s21::stack<int> st{1, 2, 3, 4};
  st.insert_many_front(5, 6, 7, 8, 9, 0);
  EXPECT_EQ(st.size(), 10);
  EXPECT_EQ(st.top(), 0);
}