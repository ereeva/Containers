#ifndef CPP2_S21_LIST_LIST_H_
#define CPP2_S21_LIST_LIST_H_

#include <initializer_list>

#include "list_iterators.h"

namespace s21 {

template <class T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  const_reference front()const;
  const_reference back()const;

  bool empty()const;
  size_type size()const;
  size_type max_size()const;

  void clear();
  iterator insert(iteraror pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

 private:
  struct Node {
    T data_;
    struct Node *next_ = nullptr;
    struct Node *prior_ = nullptr;

    Node(value_type data, Node *next = nullptr, Node *prior = nullptr)
        : data_(data), next_(next), prior_(prior) {}
  };
  size_type size_ = 0;
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
};
#include "list.tpp"
}  // namespace s21

#endif  // CPP2_S21_LIST_LIST_H_