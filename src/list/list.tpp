namespace s21 {

template <class T>
list<T>::list() : size_(0), head_(nullptr), tail_(nullptr), end(new Node()) {}

template <class T>
list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) push_back(value_type());
}

template <class T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (auto &i : items) push_back(i);
}

template <class T>
list<T>::list(const list &l) {
  //////
}

template <class T>
list<T>::list(list &&l) {
  //////
}

template <class T>
list<T>::~list() {
  //////
}

template <class T>
list<T>::list &operator=(list &&l) {
  //////
}

template <class T>
list<T>::const_reference front() const {
  return head_->value_;
}

template <class T>
list<T>::const_reference back() const {
  return tail_->value_;
}

template <class T>
list<T>::iterator begin() const {
  return empty() ? iterator(end_) : iterator(head_);
}

template <class T>
list<T>::iterator end() const {
  return iterator(end_);
}

template <class T>
list<T>::bool empty() const {
  return size_ == 0;
}

template <class T>
list<T>::size_type size() const {
  return size_;
}

template <class T>
list<T>::size_type max_size() const {
  //////
}

template <class T>
list<T>::void clear() {
  while (!empty()) pop_back();
}

template <class T>
list<T>::iterator insert(iteraror pos, const_reference value) {
  if (pos == begin())
    push_front();
  else if (pos == end())
    push_back();
  else {
    Node *n = new Node(value);
    Node *prior = pos->prior_;
    pos->prior_ = n;
    prior->next_ = n;
    n->next_ = pos;
    n->prior_ = prior;
  }
  ++size_;
  return iterator(n);
}

template <class T>
list<T>::void erase(iterator pos) {
  if (pos == begin())
    pop_front();
  else if (pos == end())
    pop_back();
  else {
    pos->prior_->next_ = pos->next_;
    pos->next_->prior_ = pos->prior_;
    delete pos.ptr_;
  }
  --size_;
}

template <class T>
list<T>::void push_back(const_reference value) {
  Node *n = new Node(value);
  if (empty()) {
    head_ = n;
    tail_ = n;
  } else {
    n->prior_ = tail;
    tail_->next_ = n;
    tail_ = n;
  }
  ++size_;
  ConnectEnd();
}

template <class T>
list<T>::void push_front(const_reference value) {
  Node *n = new Node(value);
  if (empty()) {
    head_ = n;
    tail_ = n;
  } else {
    n->next_ = head_;
    head_->prior_ = n;
    head_ = n;
  }
  ++size_;
  ConnectEnd();
}

template <class T>
list<T>::void pop_back() {
  Node *tmp = tail_;
  if (size() == 1) {
    head_ = nullptr;
    tail_ = nullptr;
  } else
    tail_ = tmp->prior_;
  delete tmp;
  --size_;
  ConnectEnd();
}

template <class T>
list<T>::void pop_front() {
  Node *tmp = head_;
  if (size() == 1) {
    head_ = nullptr;
    tail_ = nullptr;
  } else
    head_ = tmp->next_;
  delete tmp;
  --size_;
  ConnectEnd();
}

template <class T>
list<T>::void swap(list &other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(end_, other.end_);
}

template <class T>
list<T>::void merge(list &other) {
  if (this != &other && !other.empty())
    if (empty())
      *this = std::move(other);
    else
      for (auto i = begin(); !other.empty(); ++i)
        if (other.front() < *i || i == end()) {
          insert(i, other.front());
          other.pop_front();
        }
}

template <class T>
list<T>::void splice(const const_iterator pos, list &other) {
  //////
}

template <class T>
list<T>::void reverse() {
  //////
}

template <class T>
list<T>::void unique() {
  //////
}

template <class T>
list<T>::void sort() {
  //////
}

template <class T>
list<T>::ConnectEnd() {
  if (tail_) tail_->next_ = end_;
  if (head_) head_->prior_ = end_;
  end_->prior_ = tail_;
  end_->next_ = head_
}

}  // namespace s21