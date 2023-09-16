#ifndef S21_CONTAINERS_SRC_SET_H
#define S21_CONTAINERS_SRC_SET_H

#include <initializer_list>
#include "tree/rb_tree.h"


namespace s21 {
template <class T> class set : public RBTree<T> {
public:
  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;

  set();
  set(std::initializer_list<T> const &items);
  set(const set &s);
  set(set &&s);
  ~set();
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

template <class value_type> set<value_type>::set(){};
template <class value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set(){
  for (auto &item : items)
    this->Insert(item);
};
template <class value_type> set<value_type>::set(const set<value_type> &s){
  for(const auto it : s)
    this->Insert(it);
};
template <class value_type> set<value_type>::set(set &&s){};
template <class value_type> set<value_type>::~set(){};

} // namespace s21

#endif