#ifndef CPP2_S21_LIST_LIST_ITERATORS_H_
#define CPP2_S21_LIST_LIST_ITERATORS_H_

namespace s21 {

template <class T>
class ListIterator {
  friend class list<T>;

 public:
  ListIterator() : ptr_(nullptr){};
  ListIterator(Node *ptr) : ptr_(ptr){};

  ListIterator &operator++() {
    ptr_ = ptr_->next_;
    return *this;
  }
  ListIterator &operator--() {
    ptr_ = ptr_->prior_;
    return *this;
  }
  ListIterator operator++(int) {
    ListIterator tmp = *this;
    ptr_ = ptr_->next_;
    return tmp;
  }
  ListIterator operator--(int) {
    ListIterator tmp = *this;
    ptr_ = ptr_->prior_;
    return tmp;
  }
  bool operator==(ListIterator other) { return ptr_ == other.ptr_; }
  bool operator!=(ListIterator other) { return ptr_ != other.ptr_; }

 private:
  Node *ptr_;
};

template <class T>
class ListConstIterator : public ListIterator<T> {};

}  // namespace s21

#endif  // CPP2_S21_LIST_LIST_ITERATORS_H_