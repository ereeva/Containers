#ifndef S21_CONTAINERS_SRC_SET_H
#define S21_CONTAINERS_SRC_SET_H

#include "tree/rb_tree.h"

template <class T> class set : public RBTree {
public: 
set();
set(std::initializer_list<value_type> const &items);
set(const set &s);
set(set &&s);
~set();
operator=(set &&s);
bool empty();
size_type size();
size_type max_size();

private:
};

#endif