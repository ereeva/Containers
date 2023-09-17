#ifndef S21_CONTAINERS_TREE_RB_TREE_H
#define S21_CONTAINERS_TREE_RB_TREE_H

#include <utility>
namespace s21 {
enum Color { RED, BLACK };

template <class T> class RBTree {
public:
  struct Node;
  class BTreeIterator;

  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = BTreeIterator;
  using size_type = std::size_t;

  RBTree();
  RBTree(RBTree &&other) {
    root_ = other.root_;
    other.root_ = nullptr;
  };
  ~RBTree() { 
    clear(); 
    delete end_;
  };

  iterator begin() const {
    iterator iter(root_, end_);
    return iter.begin();
  };

  iterator end() const {
    return iterator(end_, end_);
  };

  Node *Insert(const_reference x);
  Node *Search(Node *root, Node *first) const;
  Node *Remove();
  void clear();
  bool contains(const key_type key);

private:
  void Balance(Node *&root, Node *&pt);
  void RotateLeft(Node *&root, Node *&pt);
  void RotateRight(Node *&root, Node *&pt);
  Node *root_, *end_;
};

template <class key_type> struct RBTree<key_type>::Node {
  key_type data_;
  bool color;
  Node *left_, *right_, *parent_;
  Node() : data_(){};
  Node(const_reference data) : data_(data), color(RED), parent_(), left_(), right_(){};
  void Clear() {
    if (left_ != nullptr) {
      left_->Clear();
      delete left_;
    }
    if (right_ != nullptr) {
      right_->Clear();
      delete right_;
    }
  }
};

template <class key_type> class RBTree<key_type>::BTreeIterator {
public:
  BTreeIterator(Node *node);
  BTreeIterator(Node *node, Node *end);
  iterator begin();
  iterator end();
  iterator next();
  iterator prev();
  iterator operator++();
  iterator operator--();
  iterator operator++(int);
  iterator operator--(int);
  bool operator==(const iterator rhs) const;
  bool operator<(const iterator rhs) const;
  bool operator!=(const iterator rhs) const { return !operator==(rhs); };
  reference operator*();
  const_reference operator*() const;

private:
  Node *FindMax(Node *ptr);
  Node *FindMin(Node *ptr);
  Node *ptr, *end_;
};

}; // namespace s21

#include "rb_tree.tpp"
#endif // S21_CONTAINERS_TREE_RB_TREE_H
