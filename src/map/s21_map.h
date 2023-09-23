#ifndef S21_CONTAINERS_SRC_MAP_H
#define S21_CONTAINERS_SRC_MAP_H

#include "../set/s21_set.h"
#include "../tree/rb_tree.h"
#include <initializer_list>
#include <limits>
#include <stdexcept>
#include <tuple>
#include <utility>

namespace s21 {
template <class K, class T> struct pair;
/// @brief container holds pairs<key, value> derived from s21::set<pair<K,T>>
/// @tparam K 
/// @tparam T 
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

  /// @brief return reference of element or throw exception
  /// @param key 
  /// @return  reference to the mapped value of the element with key 
  reference at(const key_type &key) {
    iterator ptr;
    if (this->contains(key))
      ptr = (this->find(pair<key_type, value_type>(key)));
    else
      throw std::out_of_range("map::at");
    return (*ptr).value;
  };

  /// @brief check for element exists in container
  /// @param key 
  /// @return bool
  bool contains(const key_type &key) {
    return this->contains_tr(pair<key_type, value_type>(key, value_type()));
  };

  /// @brief insert element to container
  /// @param value 
  /// @return pair of iterator and true if inserted
  std::pair<iterator, bool> insert(pair<key_type, value_type> value){
    if (this->contains(value.key))
      return std::make_pair(iterator(nullptr), false);
    else {
      this->IncSize();
      return std::make_pair(iterator(this->Insert(value)), true);
    }
  };

  /// @brief insert element to map taking key and value
  /// @param key 
  /// @param obj 
  /// @return pair of iterator and true if inserted
  std::pair<iterator, bool> insert(const key_type &key, const T &obj) {
    return this->insert(pair<key_type, value_type>(key, obj));
  };

  /// @brief insert or assign an element in map
  /// @param key
  /// @param obj
  /// @return pair of iterator and true if inserted , false if assign
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const T &obj) {
    bool in = false;
    iterator ptr;
    if (!(this->contains(key))) {
      ptr = (this->insert(pair<key_type, value_type>(key))).first;
      in = true;
    } else {
      ptr = this->find(pair<key_type, value_type>(key));
      (*ptr).value = obj;
    }
    return std::pair<iterator, bool>(ptr, in);
  };

  /// @brief return reference of element (insert if doesn't exists) 
  /// @param key 
  /// @return reference
  reference operator[](const key_type &key) {
    if (!(this->contains(key)))
      this->insert(pair<key_type, value_type>(key));
    return this->at(key);
  }

private:
};

/// @brief hold key-value pair
/// @tparam key_type
/// @tparam value_type
template <class key_type, class value_type> struct pair {
  pair() : key(), value(){};
  pair(const key_type &key_) : key(key_), value(){};
  pair(const key_type &key_, value_type value_) : key(key_), value(value_){};
  pair(std::pair<key_type, value_type> &p) : key(p.first), value(p.second){};
  bool operator==(const pair &other) const{ return key == other.key; };
  bool operator<(const pair &other) const{ return key < other.key; };
  bool operator!=(const pair &other) const{ return !(*this == other); };
  bool operator>(const pair &other) const{ return other.key < key; };
  pair &make_pair(key_type &key, value_type &value) {
    return pair(key, value);
  };
  key_type key;
  value_type value;
};


template <class key_type, class value_type> map<key_type, value_type>::map(){};
/// @brief initializer_list costructor ( {{ key, value},...} )
/// @tparam key_type 
/// @tparam value_type 
/// @param items 
template <class key_type, class value_type>
map<key_type, value_type>::map(
    std::initializer_list<pair<key_type, value_type>> const &items)
    : map() {
  for (auto &item : items)
    this->insert(item);
};

} // namespace s21

#endif