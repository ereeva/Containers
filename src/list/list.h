#ifndef CPP2_S21_LIST_LIST_H_
#define CPP2_S21_LIST_LIST_H_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <class T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  struct Node {
    T value_;
    Node *next_;
    Node *prior_;

    // Node() : value_(nullptr), next_(nullptr), prior_(nullptr){};
    Node(T value = T()) : value_(value), next_(nullptr), prior_(nullptr){};
  };

 public:
  template <class value_type>
  class ListIterator {
    friend class list<T>;

   public:
    ListIterator(Node *ptr) : ptr_(ptr){};

    T &operator*() { return ptr_->value_; }

    T *operator->() { return &ptr_->value_; }

    ListIterator &operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }
    ListIterator &operator--() {
      ptr_ = ptr_->prior_;
      return *this;
    }
    ListIterator operator++(int) {
      iterator tmp(*this);
      ++(*this);
      return tmp;
    }
    ListIterator operator--(int) {
      iterator tmp(*this);
      --(*this);
      return tmp;
    }
    bool operator==(ListIterator other) { return ptr_ == other.ptr_; }
    bool operator!=(ListIterator other) { return ptr_ != other.ptr_; }

   protected:
    Node *ptr_;
  };
  template <class value_type>
  class ListConstIterator : public ListIterator<T> {
   public:
    ListConstIterator();
    ListConstIterator(const ListIterator<T> &node_);
    const_reference operator*() const;
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(const list &l);
  list &operator=(list &&l);

  const_reference front() const;
  const_reference back() const;

  iterator begin() const;
  iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const iterator pos, list &other);  //////////////
  void reverse();
  void unique();
  void sort();

  // iterator insert_many(const_iterator pos, Args &&...args);
  // void insert_many_back(Args &&...args);
  // void insert_many_front(Args &&...args);

 private:
  size_type size_;
  Node *end_;

  void Connect(Node *first, Node *second);
  Node *Middle(Node *head);
  Node *Merge(Node *a, Node *b);
  Node *MergeSort(Node *head);
};

}  // namespace s21

#include "list.tpp"

#endif  // CPP2_S21_LIST_LIST_H_