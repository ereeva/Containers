#ifndef CPP2_S21_QUEUE_QUEUE_H_
#define CPP2_S21_QUEUE_QUEUE_H_

#include "../list/list.h"

namespace s21 {
template <class T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() : list_() {}
  queue(std::initializer_list<T> const &items) : list_(items) {}
  queue(const queue &q) : list_(q.list_) {}
  queue(queue &&q) : list_(std::move(q.list_)) {}
  ~queue() {}

  queue &operator=(const queue &q) {
    list_ = q.list_;
    return *this;
  };
  queue &operator=(queue &&q) {
    list_ = std::move(q.list_);
    return *this;
  }

  const_reference front() const { return list_.front(); }
  const_reference back() const { return list_.back(); }

  bool empty() const { return list_.empty(); }
  size_type size() const { return list_.size(); }

  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_front(); }
  void swap(queue &other) { list_.swap(other.list_); }

 private:
  list<T> list_;
};

}  // namespace s21

#endif  // CPP2_S21_QUEUE_QUEUE_H_