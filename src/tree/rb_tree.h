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
  using iterator = BTreeIterator;

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
  Node(key_type data)
      : data_(data), color(RED), parent_(), left_(), right_(){};
};

template <class key_type> 
class RBTree<key_type>::BTreeIterator {
  BTreeIterator (Node* node);
  iterator begin();
  iterator end();
  iterator next();
  iterator prev();
  iterator operator++();
  iterator operator--();
  iterator operator++(int);
  iterator operator--(int);
  bool operator==();
  bool operator<();
  reference operator*();
  const_reference operator*() const;

private:
  Node* FindMax(Node* ptr);
  Node* FindMin(Node* ptr);
  Node *ptr;
};

}; // namespace s21

#include "rb_tree.tpp"
#endif // S21_CONTAINERS_TREE_RB_TREE_H
