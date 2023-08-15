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
list<T>::list &list<T>::operator=(list &&l) {
  //////
}

template <class T>
list<T>::const_reference list<T>::front() const {
  return head_->value_;
}

template <class T>
list<T>::const_reference list<T>::back() const {
  return tail_->value_;
}

template <class T>
list<T>::iterator list<T>::begin() const {
  return empty() ? iterator(end_) : iterator(head_);
}

template <class T>
list<T>::iterator list<T>::end() const {
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
list<T>::iterator list<T>::insert(iteraror pos, const_reference value) {
  Node *n = new Node(value);
  if (empty()) {
    head_ = n;
    tail_ = n;
    tail_->next_ = end_;
    head_->prior_ = end_;
    end_->prior_ = n;
    end_->next_ = n;
  } else {
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
void list<T>::erase(iterator pos) {
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
void list<T>::push_back(const_reference value) {
  insert(begin(), value);
}

template <class T>
void list<T>::push_front(const_reference value) {
  insert(end(), value);
}

template <class T>
void list<T>::pop_back() {
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
void list<T>::pop_front() {
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
void list<T>::swap(list &other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(end_, other.end_);
}

template <class T>
void list<T>::merge(list &other) {
  if (this != &other && !other.empty())
    for (auto i = begin(); !other.empty(); ++i)
      if (empty())
        swap(other);
      else if (other.front() < *i || i == end()) {
        i = insert(i, other.front());
        other.pop_front();
      }
}

template <class T>
void list<T>::splice(const const_iterator pos, list &other) {
  if (!other.empty()) {
    Node *prior = pos->prior_;
    pos->prior_ = other.tail_;
    prior->next_ = other.head_;
    other.tail_->next_ = pos;
    other.head_->prior_ = prior;

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
}

template <class T>
void list<T>::reverse() {
  iterator b = begin();
  iterator e = end();
  for (size_type i = 0; i < size / 2; ++i) std::swap(*b++, *e--);
}

template <class T>
void list<T>::unique() {
  if (!empty())
    for (auto i = begin(); i != end(); ++i)
      if (i->value_ == i->prior_->value_) erase(i--);
}

template <class T>
void list<T>::sort() {
  //////
}

}  // namespace s21