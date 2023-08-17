#ifndef S21_CONTAINERS_TREE_RB_TREE_H
#define S21_CONTAINERS_TREE_RB_TREE_H

namespace s21 {
enum Color { RED, BLACK };

template <class T> class RBTree {
public:
  struct Node;
  class BTreeIterator;

  using key_type = T;
  using value_type = key_type;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Node*;

  RBTree();

  Node *Insert(reference x);
  Node *Search(Node *root, Node *first) const;
  Node *Remove(reference x);
protected:
  void Balance(Node *&root, Node *&pt);
private:
  void RotateLeft(Node *&root, Node *&pt);
  void RotateRight(Node *&root, Node *&pt); 
  Node *root_;
};

template <class key_type> struct RBTree<key_type>::Node {
  key_type data_;
  Node *left_, *right_, *parent_;
  Node();
  Node(key_type data, Color c = RED, Node *p = nullptr, Node *r = nullptr,
       Node *l = nullptr)
      : data_(data), color(c), parent_(p), left_(l), right_(r){};
};

template <class key_type> 
class RBTree<key_type>::BTreeIterator {
  iterator begin();
  iterator end();
  iterator next();
  iterator operator++();
  iterator operator--();
  iterator operator++(int);
  iterator operator--(int);
  bool operator==();
  bool operator<();
  reference operator*();
  const_reference operator*() const;

private:
  Node *ptr;
};

}; // namespace s21

#include "rb_tree.tpp"
#endif // S21_CONTAINERS_TREE_RB_TREE_H
