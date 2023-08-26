#ifndef CPP2_S21_STACK_STACK_H_
#define CPP2_S21_STACK_STACK_H_

#include "../list/list.h"

namespace s21 {
template <class T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack() : list_() {}
  stack(std::initializer_list<T> const &items) : list_(items) {}
  stack(const stack &q) : list_(q.list_) {}
  stack(stack &&q) : list_(std::move(q.list_)) {}
  ~stack() {}

  stack &operator=(const stack &q) {
    list_ = q.list_;
    return *this;
  }
  stack &operator=(stack &&q) {
    list_ = std::move(q.list_);
    return *this;
  }

  const_reference top() const { return list_.back(); }

  bool empty() const {return list_.empty()} size_type size() const {
    return list_.size()
  }

  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_back() }
  void swap(stack &other) { list_.swap(other.list_) }

 private:
  list<T> list_;
}

}  // namespace s21

#endif  // CPP2_S21_STACK_STACK_H_