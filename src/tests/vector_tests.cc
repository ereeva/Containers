#include <vector>

#include "../vector/vector.h"
#include "all_tests.h"

template <typename value_type>
bool compare_vectors(const s21::vector<value_type> &v1,
                     const std::vector<value_type> &v2) {
  if (v1.size() != v2.size()) return false;
  for (std::size_t i = 0; i < v1.size(); ++i)
    if (v1[i] != v2[i]) return false;
  return true;
}

TEST(VectorTest, DefaultConstructor) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, DefaultConstructor1) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, SizeConstructor) {
  s21::vector<int> v1(5);
  std::vector<int> v2(5);
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, SizeConstructor2) {
  s21::vector<std::string> v1(5);
  std::vector<std::string> v2(5);
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, InitializerListConstructor) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, InitializerListConstructor1) {
  s21::vector<std::string> v1{"qwe", "rty", ""};
  std::vector<std::string> v2{"qwe", "rty", ""};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, CopyConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_copy(v2);
  EXPECT_TRUE(compare_vectors(v1_copy, v2_copy));
}

TEST(VectorTest, CopyConstructor1) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  EXPECT_EQ(v1.size(), v1_copy.size());
}

TEST(VectorTest, CopyConstructor2) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  s21::vector<int> v1_wrong{1, 2, 3, 4};
  EXPECT_NE(v1_copy.size(), v1_wrong.size());
}

TEST(VectorTest, MoveConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved(std::move(v2));
  EXPECT_TRUE(compare_vectors(v1_moved, v2_moved));
}

TEST(VectorTest, MoveConstructor1) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  EXPECT_EQ(v1_moved[0], 1);
  EXPECT_EQ(v1_moved[1], 2);
  EXPECT_EQ(v1_moved[2], 3);
}

TEST(VectorTest, MoveConstructor2) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  EXPECT_NE(v1_moved.size(), v1.size());
}

TEST(VectorTest, CopyAssignment) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v2;
  v2 = v1;
  std::vector<int> v3{1, 2, 3};
  std::vector<int> v4;
  v4 = v3;
  EXPECT_TRUE(compare_vectors(v2, v4));
}

TEST(VectorTest, CopyAssignment2) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v2{1, 2, 3, 4, 5, 6, 7};
  v2 = v1;
  std::vector<int> v3{1, 2, 3};
  std::vector<int> v4{1, 2, 3, 4, 5, 6, 7};
  v4 = v3;
  EXPECT_TRUE(compare_vectors(v2, v4));
}

TEST(VectorTest, CopyAssignment3)
{
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v2;
  v2.reserve(7);
  v2 = v1;
  std::vector<int> v3{1, 2, 3};
  std::vector<int> v4;
  v4.reserve(7);
  v4 = v3;
  EXPECT_TRUE(compare_vectors(v2, v4));
}

TEST(VectorTest, MoveAssignment) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved;
  v2_moved = std::move(v2);
  EXPECT_TRUE(compare_vectors(v1_moved, v2_moved));
}

TEST(VectorTest, MoveAssignment1) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  EXPECT_EQ(v1_moved[0], 1);
  EXPECT_EQ(v1_moved[1], 2);
  EXPECT_EQ(v1_moved[2], 3);
}

TEST(VectorTest, MoveAssignment2) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  EXPECT_NE(v1_moved.size(), v1.size());
}

TEST(VectorTest, At) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  for (std::size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v1.at(i), v2.at(i));
  }
}

TEST(VectorTest, At1) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.at(0), 1);
  EXPECT_EQ(v1.at(1), 2);
  EXPECT_EQ(v1.at(2), 3);
}

TEST(VectorTest, At2) {
  const s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.at(0), 1);
  EXPECT_EQ(v1.at(1), 2);
  EXPECT_EQ(v1.at(2), 3);
}

TEST(VectorTest, At3) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_THROW(v1.at(3), std::out_of_range);
}

TEST(VectorTest, Front) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.front(), v2.front());
}

TEST(VectorTest, Front1) {
  const s21::vector<int> v1{1, 2, 3};
  const std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.front(), v2.front());
}

TEST(VectorTest, FrontAndBack1) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v1.back(), 3);
}

TEST(VectorTest, FrontAndBack2) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.front(), 3);
  EXPECT_NE(v1.back(), 1);
}

TEST(VectorTest, FrontAndBack3) {
  const s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.front(), 3);
  EXPECT_NE(v1.back(), 1);
}

TEST(VectorTest, Data) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(*v1.data(), *v2.data());
}

TEST(VectorTest, Data1) {
  const s21::vector<int> v1{1, 2, 3};
  const std::vector<int> v2{1, 2, 3};
  const int *ar1 = v1.data();
  const int *ar2 = v2.data();
  EXPECT_EQ(ar1[1], ar2[1]);
}

TEST(VectorTest, Empty) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VectorTest, Empty1) {
  s21::vector<int> v1;
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, Empty2) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_FALSE(v1.empty());
}

TEST(VectorTest, Size) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, Size1) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
}

TEST(VectorTest, Size2) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.size(), 4);
}

TEST(VectorTest, MaxSize) {
  s21::vector<int> v1;
  std::vector<int> v2;
  double ratio = static_cast<double>(v1.max_size()) / v2.max_size();
  EXPECT_NEAR(ratio, 2.0, 0.1);
}

TEST(VectorTest, MaxSize1) {
  s21::vector<int> v1;
  EXPECT_GT(v1.max_size(), 0);
}

TEST(VectorTest, ReserveAndCapacity) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.reserve(100);
  v2.reserve(100);
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTest, ReserveAndCapacity1) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  EXPECT_GE(v1.capacity(), 100);
}

TEST(VectorTest, ReserveAndCapacity2) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  EXPECT_NE(v1.capacity(), 50);
}

TEST(VectorTest, ShrinkToFit) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.shrink_to_fit();
  v2.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTest, ShrinkToFit1) {
  s21::vector<int> v1{1, 2, 3};
  v1.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v1.size());
}

TEST(VectorTest, ShrinkToFit2) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  v1.shrink_to_fit();
  EXPECT_NE(v1.capacity(), 100);
}

TEST(VectorTest, Clear) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.clear();
  v2.clear();
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, Clear1) {
  s21::vector<int> v1{1, 2, 3};
  v1.clear();
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, Clear2) {
  s21::vector<int> v1{1, 2, 3};
  v1.clear();
  EXPECT_FALSE(v1.size() == 3);
}

TEST(VectorTest, Insert){
  s21::vector<std::string> v1{"1", "2", "3"};
  auto i1 = v1.insert(v1.begin() + 2, "qwe");
  std::vector<std::string> v2{"1", "2", "3"};
  auto i2 = v2.insert(v2.begin() + 2, "qwe");
  EXPECT_TRUE(compare_vectors(v1, v2));
  EXPECT_EQ(*i1, *i2);
}

TEST(VectorTest, Erase){
  s21::vector<std::string> v1{"1", "2", "3"};
  v1.erase(v1.begin());
  std::vector<std::string> v2{"1", "2", "3"};
  v2.erase(v2.begin());
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, PushBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.push_back(4);
  v2.push_back(4);
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, PushBack1) {
  s21::vector<int> v1{1, 2, 3};
  v1.push_back(4);
  EXPECT_EQ(v1.size(), 4);
  EXPECT_EQ(v1.back(), 4);
}

TEST(VectorTest, PushBack2) {
  s21::vector<int> v1{1, 2, 3};
  v1.push_back(4);
  EXPECT_NE(v1.size(), 3);
  EXPECT_NE(v1.back(), 3);
}

TEST(VectorTest, PopBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.pop_back();
  v2.pop_back();
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, PopBack1) {
  s21::vector<int> v1{1, 2, 3};
  v1.pop_back();
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v1.back(), 2);
}

TEST(VectorTest, PopBack2) {
  s21::vector<int> v1{1, 2, 3};
  v1.pop_back();
  EXPECT_NE(v1.size(), 3);
  EXPECT_NE(v1.back(), 3);
}

TEST(VectorTest, Swap) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_swap{4, 5, 6};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_swap{4, 5, 6};
  v1.swap(v1_swap);
  v2.swap(v2_swap);

  EXPECT_TRUE(compare_vectors(v1, v2));
  EXPECT_TRUE(compare_vectors(v1_swap, v2_swap));
}

TEST(VectorTest, Swap1) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_swap{4, 5, 6};
  v1.swap(v1_swap);
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.front(), 4);
  EXPECT_EQ(v1.back(), 6);
  EXPECT_EQ(v1_swap.size(), 3);
  EXPECT_EQ(v1_swap.front(), 1);
  EXPECT_EQ(v1_swap.back(), 3);
}

TEST(VectorTest, IteratorIncrement1) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorTest, IteratorIncrement2) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  ++it;
  EXPECT_NE(*it, 1);
  ++it;
  EXPECT_NE(*it, 2);
}

TEST(VectorTest, IteratorDecrement1) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, IteratorDecrement2) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.end();
  --it;
  EXPECT_NE(*it, 2);
  --it;
  EXPECT_NE(*it, 1);
}

TEST(VectorTest, Dereference1) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, Dereference2) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  EXPECT_NE(*it, 2);
  ++it;
  EXPECT_NE(*it, 1);
}

TEST(VectorTest, Equal1) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it1 = v.begin();
  s21::vector<int>::iterator it2 = v.begin();
  EXPECT_TRUE(it1 == it2);
  ++it1;
  EXPECT_FALSE(it1 == it2);
}

TEST(VectorTest, Equal2) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it1 = v.begin();
  s21::vector<int>::iterator it2 = v.begin();
  EXPECT_FALSE(it1 != it2);
  ++it1;
  EXPECT_TRUE(it1 != it2);
}

TEST(VectorTest, ConstIteratorIncrement1) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.begin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorTest, ConstIteratorIncrement2) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.begin();
  ++it;
  EXPECT_NE(*it, 1);
  ++it;
  EXPECT_NE(*it, 2);
}

TEST(VectorTest, ConstIteratorDecrement1) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, ConstIteratorDecrement2) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.end();
  --it;
  EXPECT_NE(*it, 2);
  --it;
  EXPECT_NE(*it, 1);
}

TEST(VectorTest, ConstIteratorDereference1) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, ConstIteratorDereference2) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.begin();
  EXPECT_NE(*it, 2);
  ++it;
  EXPECT_NE(*it, 1);
}

TEST(VectorTest, ConstIteratorEqual1) {
  const s21::vector<int> v{1, 2, 3};
  auto it1 = v.begin();
  auto it2 = v.begin();
  EXPECT_TRUE(it1 == it2);
  ++it1;
  EXPECT_FALSE(it1 == it2);
}

TEST(VectorTest, ConstIteratorEqual2) {
  const s21::vector<int> v{1, 2, 3};
  auto it1 = v.begin();
  auto it2 = v.begin();
  EXPECT_FALSE(it1 != it2);
  ++it1;
  EXPECT_TRUE(it1 != it2);
}

TEST(VectorTest, ConstIteratorPlus1) {
  const s21::vector<int> v{1, 2, 3};

  auto it = v.begin();
  auto result = it + 2;

  EXPECT_EQ(*result, 3);
}

TEST(VectorTest, ConstIteratorMinus1) {
  const s21::vector<int> v{1, 2, 3};
  auto it = v.end();
  auto result = it - 2;

  EXPECT_EQ(*result, 2);
}

TEST(VectorTest, ConstIteratorMinus2) {
  const s21::vector<int> v{1, 2, 3};

  auto it1 = v.begin();
  auto it2 = v.end();

  ptrdiff_t result = it2 - it1;

  EXPECT_EQ(result, 3);
}