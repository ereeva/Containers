#ifndef S21_CONTAINERS_SRC_MULTISET_H
#define S21_CONTAINERS_SRC_NULTISET_H

#include "../set/s21_set.h"
#include <functional>

namespace s21 {
template <class T> class multiset : public set<T, std::less_equal<T>> {
public:
  using RBTree<T, std::less_equal<T>>::BTreeIterator;
  using iterator = typename RBTree<T, std::less_equal<T>>::BTreeIterator;
  multiset(){};
  multiset(std::initializer_list<T> const &items) : multiset() {
    for (auto &item : items)
      this->insert(item);
  };
  std::pair<iterator, bool> insert(const T &value) {
    this->IncSize();
    return std::make_pair(iterator(this->Insert(value)), true);
  }
  void erase(iterator pos) {
    multiset<T> *tmp = new multiset<T>();
    for (auto it = this->begin(); it != this->end(); ++it)
      if (it != pos)
        tmp->insert(*it);
    this->swap(*tmp);
  };
};
} // namespace s21

#endif