#ifndef S21_CONTAINERS_SRC_SET_H
#define S21_CONTAINERS_SRC_SET_H

#include "tree/rb_tree.h"
namespace s21 {
template <class T> class set : public RBTree {
public:
  // set();
  // set(std::initializer_list<value_type> const &items);
  // set(const set &s);
  // set(set &&s);
  // ~set();
  // operator=(set &&s);
  // bool empty();
  // size_type size();
  // size_type max_size();
  // void clear();
  // std::pair<iterator, bool> insert(const value);
  // void erase(iterator pos);
  // void swap(set &other);
  // void merge(set &other);
  // iterator find(const key_type &key);
  // bool contains(const key_type key);

private:
};

// template <class T> class set::set(){};
// template <class T>
// class set::set(std::initializer_list<value_type> const &items){};
// template <class T> class set::set(const set &s){};
// template <class T> class set::set(set &&s){};
// template <class T> class set::~set(){};

} // namespace s21

#endif