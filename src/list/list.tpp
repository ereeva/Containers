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
list<T>::list(const list &l) : list() {
  for (auto i = l.begin(); i != l.end(); ++i) push_back(i.ptr_->value_);
}

template <class T>
list<T>::list(list &&l) : list() {
  swap(l);
}

template <class T>
list<T>::~list() {
  clear();
}

template <class T>
class list<T>::list &list<T>::operator=(const list &l){
  //////
}

template <class T>
class list<T>::list &list<T>::operator=(list &&l) {
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
bool list<T>::empty() const {
  return size_ == 0;
}

template <class T>
list<T>::size_type list<T>::size() const {
  return size_;
}

template <class T>
list<T>::size_type list<T>::max_size() const {
  //////
}

template <class T>
void list<T>::clear() {
  while (!empty()) pop_back();
}

template <class T>
list<T>::iterator list<T>::insert(iterator pos, const_reference value) {
  Node *n = new Node(value);
  Node *prior = empty() ? end().ptr_ : pos->prior_;
  pos->prior_ = n;
  prior->next_ = n;
  n->next_ = pos;
  n->prior_ = prior;
  if (pos == begin() || empty()) head_ = n;
  if (pos == end() || empty()) tail_ = n;
  ++size_;
  return iterator(n);
}

template <class T>
void list<T>::erase(iterator pos) {
  if (pos == begin())
    head_ = head_->next_;
  else if (pos == iterator(tail_))
    tail_ = tail_->prior_;
  pos->prior_->next_ = pos->next_;
  pos->next_->prior_ = pos->prior_;
  delete pos.ptr_;
  --size_;
  if (empty()) {
    head_ = nullptr;
    tail_ = nullptr;
  }
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
  erase(iterator(tail_));
}

template <class T>
void list<T>::pop_front() {
  erase(begin());
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
      else if (other.front()->value_ < i->value_ || i == end()) {
        i = insert(i, other.front()->value_);
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

    other.end_->next_ = other.end_->prior_ = other.end_;
    other.head_ = other.tail_ = nullptr;
    other.size_ = 0;
  }
}

template <class T>
void list<T>::reverse() {
  iterator h = begin();
  iterator t = iterator(tail_);
  for (size_type i = 0; i < size / 2; ++i) std::swap(*h++, *t--);
}

template <class T>
void list<T>::unique() {
  if (!empty())
    for (auto i = begin(); i != end(); ++i)
      if (i->value_ == i->prior_->value_) erase(i--);
}

template <class T>
void list<T>::sort() {}

template <class T>
list<T>::Node *list<T>::MergeSort(Node *head) {}

}  // namespace s21