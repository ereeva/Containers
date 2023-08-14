#include "rb_tree.h"

namespace s21 {
template <class key_type> RBTree<key_type>::RBTree() : root(){};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Insert(key_type &x) {
  Node *node = Search(x);
};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Search(key_type &x,
                                                 Node *first) const {
  if (first->data_ == x)
    return first;
  else if (x < first->data_)
    return Search(x, first->left_);
  else
    return Search(x, first->right_)
};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Remove(T &x){

};
} // namespace s21