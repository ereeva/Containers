#ifndef CPP2_S21_QUEUE_QUEUE_H_
#define CPP2_S21_QUEUE_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {
template <class T, class Container = list<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() : list_() {}
  queue(std::initializer_list<T> const &items) : list_(items) {}
  queue(const queue &q) : list_(q.list_) {}
  queue(queue &&q) noexcept : list_(std::move(q.list_)) {}
  ~queue() {}

  queue &operator=(const queue &q) {
    list_ = q.list_;
    return *this;
  };
  queue &operator=(queue &&q) noexcept {
    list_ = std::move(q.list_);
    return *this;
  }

  reference front() { return list_.front(); }
  const_reference front() const { return list_.front(); }
  reference back() { return list_.back(); }
  const_reference back() const { return list_.back(); }

  bool empty() const { return list_.empty(); }
  size_type size() const { return list_.size(); }

  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_front(); }
  void swap(queue &other) noexcept { list_.swap(other.list_); }

  template <class... Args>
  void insert_many_back(Args &&...args) {
    list_.insert_many_back(args...);
  }

 private:
  Container list_;
};

}  // namespace s21

#endif  // CPP2_S21_QUEUE_QUEUE_H_