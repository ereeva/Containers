#ifndef CPP2_S21_LIST_LIST_H_
#define CPP2_S21_LIST_LIST_H_

#include <initializer_list>

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

  template <class T>
  class ListIterator {
   public:
    ListIterator() : ptr_(nullptr){};
    ListIterator(Node *ptr) : ptr_(ptr){};

    ListIterator &operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }
    ListIterator &operator--() {
      ptr_ = ptr_->prior_;
      return *this;
    }
    ListIterator operator++(int) {
      ListIterator tmp = *this;
      ptr_ = ptr_->next_;
      return tmp;
    }
    ListIterator operator--(int) {
      ListIterator tmp = *this;
      ptr_ = ptr_->prior_;
      return tmp;
    }
    bool operator==(ListIterator other) { return ptr_ == other.ptr_; }
    bool operator!=(ListIterator other) { return ptr_ != other.ptr_; }

   private:
    Node *ptr_;
    friend class list<T>;
  };

  template <class T>
  class ListConstIterator : public ListIterator<T> {};

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

  // iterator insert_many(const_iterator pos, Args &&...args);
  // void insert_many_back(Args &&...args);
  // void insert_many_front(Args &&...args);

 private:
  template <class T>
  struct Node {
    T value_;
    Node *next_;
    Node *prior_;

    Node(value_type value = value_type(), Node *next = this, Node *prior = this)
        : value_(value), next_(next), prior_(prior) {}
  };
  size_type size_;
  Node *head_;
  Node *tail_;
  Node *end_;

  Node *Middle(Node *head);
  Node *MergeSorted(Node *a, Node *b);
  Node *MergeSort(Node *head);
  void Connect(Node *first, Node *second);
};

}  // namespace s21

#include "list.tpp"

#endif  // CPP2_S21_LIST_LIST_H_