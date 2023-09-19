#ifndef S21_CONTAINERS_SRC_MAP_H
#define S21_CONTAINERS_SRC_MAP_H

#include "set.h"
#include "tree/rb_tree.h"
#include <initializer_list>
#include <tuple>
#include <limits>
#include <utility>

namespace s21 {
template <class K, class T> struct pair;
template <class K, class T> class map : public set<pair<K, T>> {
public:
  using typename RBTree<pair<K, T>>::Node;
  using typename RBTree<pair<K, T>>::BTreeIterator;
  using key_type = K;
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = typename RBTree<pair<K, T>>::BTreeIterator;
  map();
  map(std::initializer_list<pair<K, T>> const &items);
  //   map(const map &s);
  //   map(map &&s);
  //   map(Node *node);
  //   ~map();
  //   bool empty();
  //   size_type size();
  //   size_type max_size();
  //   void clear();
  //   std::pair<iterator, bool> insert(const value_type &value);
  //   void erase(iterator pos);
  //   void swap(map &other);
  //   void merge(map &other);
  bool contains(const key_type &key) {
    return this->contains_tr(pair<key_type, value_type>(key, value_type()));
  };

  //   std::pair<iterator, bool> insert(const key_type &key, const T &obj) {
  //     return this->insert(pair<key_type, value_type>(key, obj));
  //   };
  //   std::pair<iterator, bool> insert_or_assign(const key_type &key,
  //                                              const T &obj) {
  //     if (!this->contains(key))
  //       this->insert(pair<key_type, value_type>(key, obj));
  //     else this->operator[](key).value = obj;
  //   };
  value_type &operator[](const key_type &key) {
    iterator ptr;
    if(!(this->contains(key)))
        this->insert(pair<key_type, value_type>(key));
        ptr = (this->find(pair<key_type, value_type>(key)));
    return (*ptr).value;
  }

private:
};

/// @brief
/// @tparam key_type
/// @tparam value_type
template <class key_type, class value_type> struct pair {
  pair() : key(), value(){};
  pair(const key_type &key_) : key(key_), value(){};
  pair(const key_type &key_, value_type value_) : key(key_), value(value_){};
  pair(std::pair<key_type, value_type> &p) : key(p.first), value(p.second){};
  bool operator==(const pair &other) { return key == other.key; };
  bool operator<(const pair &other) { return key < other.key; };
  bool operator!=(const pair &other) { return !(*this == other); };
  bool operator>(const pair &other) { return other.key < key; };
  pair &make_pair(key_type &key, value_type &value) {
    return pair(key, value);
  };
  key_type key;
  value_type value;
};

template <class key_type, class value_type> map<key_type, value_type>::map(){};
template <class key_type, class value_type>
map<key_type, value_type>::map(
    std::initializer_list<pair<key_type, value_type>> const &items)
    : map() {
  for (auto &item : items)
    this->insert(item);
};
// template <class value_type> map<value_type>::map(const map<value_type> &s) {
//   for (auto &it : s)
//     this->insert(it);
// };
// template <class value_type> map<value_type>::map(map<value_type> &&s){
//   swap(s);
//   };
// template <class value_type> map<value_type>::map(Node *node){};
// template <class value_type> map<value_type>::~map(){};

// template <class value_type> bool map<value_type>::empty() {
//   return this->root_ == this->end_;
// };
// template <class value_type>
// typename map<value_type>::size_type map<value_type>::size() {
//   return size_;
// };
// template <class value_type>
// typename map<value_type>::size_type map<value_type>::max_size() {
//   return (std::numeric_limits<typename
//   s21::map<value_type>::size_type>::max() *
//           sizeof(Node));
// };

// template <class value_type> void map<value_type>::erase(iterator pos) {
//   Node *ptr = pos.GetPtr();
//   size_type tmp_size = size_ - 1;
//   map<value_type> lft(ptr->left_);
//   map<value_type> rht(ptr->right_);
//   if (ptr->parent_ != nullptr) {
//     if (ptr == ptr->parent_->left_)
//       ptr->parent_->left_ = nullptr;
//     else
//       ptr->parent_->right_ = nullptr;
//   }
//   delete ptr;
//   merge(lft);
//   merge(rht);
//   size_ = tmp_size;
// };
// template <class value_type> void map<value_type>::merge(map &other) {
//   for (auto &node : other)
//     this->insert(node);
// }

// template <class value_type> void map<value_type>::swap(map &other) {
//   std::swap(size_, other.size_);
//   this->Swap(other);
// }

// template <class value_type>
// typename std::pair<typename s21::map<value_type>::iterator, bool>
// s21::map<value_type>::insert(const value_type &value) {
//   if (this->contains(value))
//     return std::make_pair(iterator(nullptr), false);
//   else {
//     this->size_++;
//     return std::make_pair(iterator(this->Insert(value)), true);
//   }
} // namespace s21

#endif