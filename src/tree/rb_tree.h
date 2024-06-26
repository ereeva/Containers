#ifndef S21_CONTAINERS_TREE_RB_TREE_H
#define S21_CONTAINERS_TREE_RB_TREE_H

#include <functional>
#include <utility>

namespace s21 {
enum Color { RED, BLACK };

template <class T, class comp = std::less<T>>
class RBTree {
 public:
  struct Node;
  class BTreeIterator;

  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = BTreeIterator;
  using const_iterator = BTreeIterator;
  using size_type = std::size_t;

  RBTree();
  RBTree(Node *node) : RBTree() { root_ = node; };
  RBTree(RBTree &&other);
  ~RBTree() {
    clear();
    delete end_;
  };

  iterator begin() const {
    iterator iter(root_, end_);
    return iter.begin();
  };

  iterator end() const { return iterator(end_, end_); };

  Node *Insert(const_reference x);
  Node *Search(Node *root, Node *first) const;
  void Remove(Node *node);

  void Swap(RBTree &other) {
    std::swap(root_, other.root_);
    std::swap(end_, other.end_);
  };
  void clear();
  bool contains_tr(const key_type key) {
    if (root_ == end_) return false;
    return root_->contains(root_, key);
  };
  iterator find(const key_type key) noexcept {
    Node *fptr = root_->find_node(root_, key);
    if (fptr == nullptr) fptr = end_;
    return iterator(fptr, end_);
  };
  const_iterator find(const key_type key) const noexcept {
    Node *fptr = root_->find_node(root_, key);
    if (fptr == nullptr) fptr = end_;
    return const_iterator(fptr, end_);
  };

 private:
  void Balance(Node *&root, Node *&pt);
  void RotateLeft(Node *&root, Node *&pt);
  void RotateRight(Node *&root, Node *&pt);
  Node *root_, *end_;
};

template <class key_type, class comp>
struct RBTree<key_type, comp>::Node {
  key_type data_;
  bool color;
  Node *parent_, *left_, *right_;
  Node() : data_(), color(RED), parent_(), left_(), right_(){};
  Node(const Node *other)
      : data_(other->data_),
        color(other->color),
        parent_(other->parent_),
        left_(other->left_),
        right_(other->right_){};
  Node(const_reference data)
      : data_(data),
        color(RED),
        parent_(nullptr),
        left_(nullptr),
        right_(nullptr){};
  void Clear() {
    if (left_ != nullptr) {
      left_->Clear();
      delete left_;
      left_ = nullptr;
    }
    if (right_ != nullptr) {
      right_->Clear();
      delete right_;
      right_ = nullptr;
    }
  }
  Node *find_node(Node *node, const key_type key) const;
  bool contains(Node *node, const key_type key) const;
};

template <class key_type, class comp>
class RBTree<key_type, comp>::BTreeIterator {
 public:
  BTreeIterator();
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
  const_reference operator*() const;
  reference operator*();

 private:
  Node *FindMax(Node *ptr);
  Node *FindMin(Node *ptr);
  Node *ptr, *end_, *root;
};

};  // namespace s21

#include "rb_tree.inc"
#endif  // S21_CONTAINERS_TREE_RB_TREE_H
