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
  using reference = T &;
  using const_reference = const T &;

  RBTree();

  Node *Insert(T &x);
  Node *Search(T &x, Node *first) const;
  Node *Remove(T &x);
protected:
  void Balance(Node *&root, Node *&pt);
private:
  Node *root_;
};

template <class key_type> struct RBTree<key_type>::Node {
  key_type data_;
  Node *left_, *right_, *parent_;
  Node();
  Node(key_type data, Node *p = nullptr, Color c = RED, Node *r = nullptr,
       Node *l = nullptr)
      : data_(data), parent_(p), left_(l), right_(r){};
};

template <class key_type> class RBTree<key_type>::BTreeIterator {
  iterator operator++();
  iterator operator--();
  bool operator==();
  bool operator<();
  Node &operator*();

private:
  Node *ptr;
}

} // namespace s21

#endif // S21_CONTAINERS_TREE_RB_TREE_H
