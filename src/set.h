#ifndef S21_CONTAINERS_SRC_SET_H
#define S21_CONTAINERS_SRC_SET_H

#include "tree/rb_tree.h"
#include "vector/vector.h"
#include <functional>
#include <initializer_list>
#include <limits>
#include <tuple>
#include <utility>

namespace s21 {
template <class T, class comp = std::less<T>>
class set : public RBTree<T, comp> {
public:
  using typename RBTree<T, comp>::Node;
  using typename RBTree<T, comp>::BTreeIterator;
  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = typename RBTree<T, comp>::BTreeIterator;
  using const_iterator = typename RBTree<T, comp>::ConstBTreeIterator;

  set();
  set(std::initializer_list<T> const &items);
  set(const set &s);
  set(set &&s);
  set(Node *node);
  ~set();
  set<T> &operator=(set<T> &&other) {
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
  template <class... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    s21::vector<std::pair<iterator, bool>> result;
    for (auto &&arg : {std::forward<Args>(args)...})
      result.push_back(insert(arg));
    return result;
  };
  void IncSize() { size_++; };

private:
  size_type size_ = 0;
};

/// @brief default constructor
/// @tparam value_type
template <class value_type, class comp> set<value_type, comp>::set(){};

/// @brief itializer_list constructor
/// @tparam valuen_type
/// @param items
template <class value_type, class comp>
set<value_type, comp>::set(std::initializer_list<value_type> const &items)
    : set() {
  for (auto &item : items)
    this->insert(item);
};

/// @brief copy constructor
/// @tparam value_type
/// @param s
template <class value_type, class comp>
set<value_type, comp>::set(const set<value_type, comp> &s) {
  for (auto &it : s)
    this->insert(it);
};

/// @brief move constructor
/// @tparam value_type
/// @param s
template <class value_type, class comp>
set<value_type, comp>::set(set<value_type, comp> &&s) {
  swap(s);
};

/// @brief constructor from node taken as root in new set
/// @tparam value_type
/// @param node
template <class value_type, class comp>
set<value_type, comp>::set(Node *node) {};

/// @brief destructor
/// @tparam value_type
template <class value_type, class comp> set<value_type, comp>::~set(){};

/// @brief check set for empty
/// @tparam value_type
/// @return return true if empty
template <class value_type, class comp> bool set<value_type, comp>::empty() {
  return this->root_ == this->end_;
};

/// @brief size of container
/// @tparam value_type
/// @return number of elements
template <class value_type, class comp>
typename set<value_type, comp>::size_type set<value_type, comp>::size() {
  return size_;
};

/// @brief return maximum of elements able to hold due to system
/// @tparam value_type
/// @return
template <class value_type, class comp>
typename set<value_type, comp>::size_type set<value_type, comp>::max_size() {
  return (std::numeric_limits<
              typename s21::set<value_type, comp>::size_type>::max() /
          sizeof(Node));
};

/// @brief erase element from set in pos
/// @tparam value_type
/// @param pos
template <class value_type, class comp>
void set<value_type, comp>::erase(iterator pos) {
   set<value_type, comp> *tmp = new set<value_type, comp>();
   for(auto it = this->begin(); it != this->end(); ++it)
    if (it != pos )tmp->insert(*it); 
  swap(*tmp);
};

/// @brief merge two sets
/// @tparam value_type
/// @param other
template <class value_type, class comp>
void set<value_type, comp>::merge(set &other) {
  for (auto &node : other)
    this->insert(node);
}

/// @brief swap data of sets
/// @tparam value_type
/// @param other
template <class value_type, class comp>
void set<value_type, comp>::swap(set &other) {
  std::swap(size_, other.size_);
  this->Swap(other);
}

/// @brief insert element to set
/// @tparam value_type
/// @param value
/// @return pair of iterator and true if inserted
template <class value_type, class comp>
typename std::pair<typename s21::set<value_type, comp>::iterator, bool>
s21::set<value_type, comp>::insert(const value_type &value) {
  if (this->contains(value))
    return std::make_pair(this->find(value), false);
  else {
    this->size_++;
    return std::make_pair(iterator(this->Insert(value)), true);
  }
};
} // namespace s21

#endif