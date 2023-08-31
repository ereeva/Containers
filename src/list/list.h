#ifndef CPP2_S21_LIST_LIST_H_
#define CPP2_S21_LIST_LIST_H_

#include <initializer_list>
#include <limits>

namespace s21 {
template <class T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  struct Node {
    T *value_;
    Node *next_;
    Node *prior_;

    Node() : value_(nullptr), next_(nullptr), prior_(nullptr) {}
    Node(T value) : value_(new T(value)), next_(nullptr), prior_(nullptr) {}

    void Connect(Node *other) {
      next_ = other;
      other->prior_ = this;
    }
  };

 public:
  template <class value_type>
  class ListIterator {
    friend class list<T>;

   public:
    ListIterator(Node *ptr) : ptr_(ptr){};

    T &operator*() { return *ptr_->value_; }

    T *operator->() { return ptr_->value_; }

    ListIterator &operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }
    ListIterator &operator--() {
      ptr_ = ptr_->prior_;
      return *this;
    }
    ListIterator operator++(int) {
      iterator tmp(*this);
      ++(*this);
      return tmp;
    }
    ListIterator operator--(int) {
      iterator tmp(*this);
      --(*this);
      return tmp;
    }
    bool operator==(ListIterator other) { return ptr_ == other.ptr_; }
    bool operator!=(ListIterator other) { return ptr_ != other.ptr_; }

   protected:
    Node *ptr_;
  };
  template <class value_type>
  class ListConstIterator : public ListIterator<T> {
   public:
    ListConstIterator() : ListIterator<T>() {}
    ListConstIterator(const ListIterator<T> &node_) : ListIterator<T>(node_) {}
    const_reference operator*() const { return ListIterator<T>::operator*(); }
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  list() : size_(0), end_(new Node()) { end_->Connect(end_); }

  list(size_type n) : list() {
    for (size_type i = 0; i < n; ++i) push_back(value_type());
  }

  list(std::initializer_list<T> const &items) : list() {
    for (auto &item : items) push_back(item);
  }

  list(const list &l) : list() {
    for (auto node : l) push_back(node);
  }

  list(list &&l) : list() { swap(l); }

  ~list() { clear(); }

  list operator=(const list &l) {
    list<T> tmp = l;
    *this = std::move(tmp);
  }

  list operator=(list &&l) {
    if (this != &l) {
      size_ = l.size_;
      end_ = l.end_;
      l.size_ = 0;
      l.end_ = nullptr;
    }
  }

  const_reference front() const { return *end_->next_->value_; }
  const_reference back() const { return *end_->prior_->value_; }

  iterator begin() const { return iterator(end_->next_); }
  iterator end() const { return iterator(end_); }

  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }
  size_type max_size() const {
    return (std::numeric_limits<size_type>::max() / 2 / sizeof(Node));
  }

  void clear() {
    while (!empty()) pop_back();
  }

  iterator insert(iterator pos, const_reference value) {
    Node *n = new Node(value);
    pos.ptr_->prior_->Connect(n);
    n->Connect(pos.ptr_);
    ++size_;
    return iterator(n);
  }

  void erase(iterator pos) {
    pos.ptr_->prior_->Connect(pos.ptr_->next_);
    delete pos.ptr_;
    --size_;
  }

  void push_back(const_reference value) { insert(end(), value); }
  void pop_back() { erase(iterator(end_->prior_)); }
  void push_front(const_reference value) { insert(begin(), value); }
  void pop_front() { erase(begin()); }

  void swap(list &other) {
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }

  void merge(list &other) {
    other.end_->prior_->next_ = end_;
    Merge(end_->next_, other.end_->next_);
    size_ += other.size_;
    other.end_->Connect(other.end_);
    other.size_ = 0;
  }

  void splice(const const_iterator pos, list &other) {
    if (!other.empty()) {
      pos.ptr_->prior_->Connect(other.end_->next_);
      other.end_->prior_->Connect(pos.ptr_);
      size_ += other.size_;
      other.end_->Connect(other.end_);
      other.size_ = 0;
    }
  }

  void reverse() {
    iterator h = begin();
    iterator t = iterator(end_->prior_);
    for (size_type i = 0; i < size() / 2; ++i) std::swap(*h++, *t--);
  }

  void unique() {
    if (!empty())
      for (auto i = begin(); i != end(); ++i)
        if (*i.ptr_->value_ == *i.ptr_->prior_->value_) erase(i--);
  }

  void sort() { MergeSort(end_->next_); }

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    iterator res = pos;
    --res;
    for (auto &&arg : {std::forward<Args>(args)...}) insert(pos, arg);
    return ++res;
  }

  template <class... Args>
  void insert_many_back(Args &&...args) {
    insert_many(end(), args...);
  }

  template <class... Args>
  void insert_many_front(Args &&...args) {
    insert_many(begin(), args...);
  }

 private:
  size_type size_;
  Node *end_;

  Node *Middle(Node *head) {
    Node *slow = head;
    Node *fast = head->next_;
    while (fast != end_ && fast->next_ != end_) {
      slow = slow->next_;
      fast = fast->next_->next_;
    }
    return slow;
  }

  Node *Merge(Node *a, Node *b) {
    Node *head;
    if (a == end_)
      head = b;
    else if (b == end_)
      head = a;
    else if (*a->value_ < *b->value_) {
      a->next_ = Merge(a->next_, b);
      // a->next_->prior_ = a;
      head = a;
    } else {
      b->next_ = Merge(a, b->next_);
      // b->next_->prior_ = b;
      head = b;
    }
    end_->Connect(head);
    for (auto i = head; i != end_; i = i->next_) i->next_->prior_ = i;  ///////
    return head;
  }

  Node *MergeSort(Node *head) {
    if (head != end_ && head->next_ != end_) {
      Node *mid = Middle(head);
      Node *second = mid->next_;
      mid->next_ = end_;
      Node *a = MergeSort(head);
      Node *b = MergeSort(second);
      head = Merge(a, b);
    }
    return head;
  }
};

}  // namespace s21

#endif  // CPP2_S21_LIST_LIST_H_