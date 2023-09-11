#ifndef S21_CONTAINERS_SRC_SET_H
#define S21_CONTAINERS_SRC_SET_H

#include "tree/rb_tree.h"

template <class T> class set : public RBTree {
public:
  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = BTreeIterator;

private:
};

#endif