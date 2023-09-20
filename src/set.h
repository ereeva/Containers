#ifndef S21_CONTAINERS_SRC_SET_H
#define S21_CONTAINERS_SRC_SET_H

#include "tree/rb_tree.h"
#include <initializer_list>
#include <limits>
#include <utility>

namespace s21 {
template <class T> class set : public RBTree<T> {
public:
  using typename RBTree<T>::Node;
  using typename RBTree<T>::BTreeIterator;
  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = typename RBTree<T>::BTreeIterator;

  set();
  set(std::initializer_list<T> const &items);
  set(const set &s);
  set(set &&s);
  set(Node *node);
  ~set();
  set<T> &operator = (set<T> && other) {
    swap(other);
    return *this;
  };
  bool empty();
  size_type size();
  size_type max_size();
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(set &other);
  void merge(set &other);
  bool contains(const key_type &key) { return this->contains_tr(key); };
  void IncSize(){ size_++;};

private:
  size_type size_ = 0;
};

/// @brief default constructor
/// @tparam value_type 
template <class value_type> set<value_type>::set(){};

/// @brief itializer_list constructor
/// @tparam valuen_type 
/// @param items 
template <class value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set() {
  for (auto &item : items)
    this->insert(item);
};

/// @brief copy constructor
/// @tparam value_type 
/// @param s 
template <class value_type> set<value_type>::set(const set<value_type> &s) {
  for (auto &it : s)
    this->insert(it);
};

/// @brief move constructor
/// @tparam value_type 
/// @param s 
template <class value_type> set<value_type>::set(set<value_type> &&s) {
  swap(s);
};

/// @brief constructor from node taken as root in new set
/// @tparam value_type 
/// @param node 
template <class value_type> set<value_type>::set(Node *node){};

/// @brief destructor
/// @tparam value_type 
template <class value_type> set<value_type>::~set(){};

/// @brief check set for empty 
/// @tparam value_type 
/// @return return true if empty
template <class value_type> bool set<value_type>::empty() {
  return this->root_ == this->end_;
};

/// @brief size of container
/// @tparam value_type 
/// @return number of elements
template <class value_type>
typename set<value_type>::size_type set<value_type>::size() {
  return size_;
};

/// @brief return maximum of elements able to hold due to system 
/// @tparam value_type 
/// @return 
template <class value_type>
typename set<value_type>::size_type set<value_type>::max_size() {
  return (std::numeric_limits<typename s21::set<value_type>::size_type>::max() /
          sizeof(Node));
};

/// @brief erase element from set in pos
/// @tparam value_type 
/// @param pos 
template <class value_type> void set<value_type>::erase(iterator pos) {
  Node *ptr = pos.GetPtr();
  size_type tmp_size = size_ - 1;
  set<value_type> lft(ptr->left_);
  set<value_type> rht(ptr->right_);
  if (ptr->parent_ != nullptr) {
    if (ptr == ptr->parent_->left_)
      ptr->parent_->left_ = nullptr;
    else
      ptr->parent_->right_ = nullptr;
  }
  delete ptr;
  merge(lft);
  merge(rht);
  size_ = tmp_size;
};

/// @brief merge two sets
/// @tparam value_type 
/// @param other 
template <class value_type> void set<value_type>::merge(set &other) {
  for (auto &node : other)
    this->insert(node);
}

/// @brief swap data of sets
/// @tparam value_type 
/// @param other 
template <class value_type> void set<value_type>::swap(set &other) {
  std::swap(size_, other.size_);
  this->Swap(other);
}

/// @brief insert element to set
/// @tparam value_type 
/// @param value 
/// @return pair of iterator and true if inserted 
template <class value_type>
typename std::pair<typename s21::set<value_type>::iterator, bool>
s21::set<value_type>::insert(const value_type &value) {
  if (this->contains(value))
    return std::make_pair(iterator(nullptr), false);
  else {
    this->size_++;
    return std::make_pair(iterator(this->Insert(value)), true);
  }
};
} // namespace s21

#endif