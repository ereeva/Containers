#include <queue>
#include <cstring>

#include "../queue/queue.h"
#include "gtest/gtest.h"

template <typename T>
class QueueTest : public testing::Test {
  using stdQueue = std::queue<T>;
  using s21Queue = s21::queue<T>;
};

using MyTypes = ::testing::Types<double, std::string, std::queue<int>>;
TYPED_TEST_SUITE(QueueTest, MyTypes);

TYPED_TEST(QueueTest, DefaultConstructor){
  using s21Queue = typename TestFixture::s21Queue;
  s21Queue s21q();
  
}