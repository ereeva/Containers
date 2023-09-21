#ifndef S21_CONTAINERS_SRC_MULTISET_H
#define S21_CONTAINERS_SRC_NULTISET_H

#include "set.h"
#include <functional>

namespace s21 {
template <class T> class multiset : public set<T, std::less_equal<T>> {
public:
  using typename RBTRee<T>::BTreeIterator;
  using iterator = typename RBTRee<T>::BTreeIterator;
  multiset(){};
  multiset(std::initializer_list<T> const &items) : multiset() {
    for (auto &item : items)
      this->insert(item);
  };
  std::pair<iterator, bool> insert(const T &value) {
    if (this->contains(value))
      return std::make_pair(this->find(value), false);
    else {
      this->IncSize();
      return std::make_pair(iterator(this->Insert(value)), true);
    }
  }
};
} // namespace s21

#endif