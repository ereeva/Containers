#ifndef S21_CONTAINERS_SRC_MULTISET_H
#define S21_CONTAINERS_SRC_NULTISET_H

#include "set.h"
#include <functional>
namespace s21 {
template <class T> class multiset : public set<T, std::less_equal<T>> {
public:
  multiset(){};
  multiset(std::initializer_list<T> const &items) : multiset() {
    for (auto &item : items)
      this->insert(item);
  };
};
} // namespace s21

#endif