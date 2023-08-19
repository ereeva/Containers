namespace s21 {

template <class T>
list<T>::list() : size_(0), head_(nullptr), tail_(nullptr), end_(new Node()) {
  Connect(end_, end_);
}

template <class T>
list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) push_back(value_type());
}

template <class T>
list<T>::list(std::initializer_list<T> const &items) : list() {
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
typename list<T>::list &list<T>::operator=(const list &l) {
  list<T> tmp = l;
  *this = std::move(tmp);
}

template <class T>
typename list<T>::list &list<T>::operator=(list &&l) {
  if (this != &l) {
    size_ = l.size_;
    head_ = l.head_;
    tail_ = l.tail_;
    end_ = l.end_;

    l.size_ = 0;
    l.head_ = nullptr;
    l.tail_ = nullptr;
  }
}

template <class T>
typename list<T>::const_reference list<T>::front() const {
  return head_ ? head_->value_ : end_->value_;
}

template <class T>
typename list<T>::const_reference list<T>::back() const {
  return tail_ ? tail_->value_ : end_->value_;
}

template <class T>
typename list<T>::iterator list<T>::begin() const {
  return empty() ? iterator(end_) : iterator(head_);
}

template <class T>
typename list<T>::iterator list<T>::end() const {
  return iterator(end_);
}

template <class T>
bool list<T>::empty() const {
  return size_ == 0;
}

template <class T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

template <class T>
typename list<T>::size_type list<T>::max_size() const {
  return (std::numeric_limits<size_type>::max() / 2 / sizeof(Node));
}

template <class T>
void list<T>::clear() {
  // while (!empty()) pop_back();
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node *n = new Node(value);
  Node *prior = pos.ptr_->prior_;
  Connect(pos.ptr_->prior_, n);
  Connect(n, pos.ptr_);
  if (pos == begin() || empty()) head_ = n;
  if (pos == end() || empty()) tail_ = n;
  ++size_;
  return iterator(n);
}

template <class T>
void list<T>::erase(iterator pos) {
  if (pos == begin()) head_ = head_->next_;
  if (pos == iterator(tail_)) tail_ = tail_->prior_;
  Connect(pos.ptr_->prior_, pos.ptr_->next_);
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
  // std::swap(head_, other.head_);
  // std::swap(tail_, other.tail_);
  // std::swap(end_, other.end_);
}

template <class T>
void list<T>::merge(list &other) {
  // if (this != &other)
  //   for (auto i = begin(); !other.empty(); ++i)
  //     if (empty())
  //       swap(other);
  //     else if (other.front()->value_ < i->value_ || i == end()) {
  //       i = insert(i, other.front()->value_);
  //       other.pop_front();
  //     }
}

template <class T>
void list<T>::splice(const const_iterator pos, list &other) {
  // if (!other.empty()) {
  //   Node *prior = pos->prior_;
  //   pos->prior_ = other.tail_;
  //   prior->next_ = other.head_;
  //   other.tail_->next_ = pos;
  //   other.head_->prior_ = prior;

  //   other.end_->next_ = other.end_->prior_ = other.end_;
  //   other.head_ = other.tail_ = nullptr;
  //   other.size_ = 0;
  // }
}

template <class T>
void list<T>::reverse() {
  // iterator h = begin();
  // iterator t = iterator(tail_);
  // for (size_type i = 0; i < size / 2; ++i) std::swap(*h++, *t--);
}

template <class T>
void list<T>::unique() {
  // if (!empty())
  //   for (auto i = begin(); i != end(); ++i)
  //     if (i->value_ == i->prior_->value_) erase(i--);
}

template <class T>
void list<T>::sort() {
  // MergeSort(head_);
}

template <class T>
typename list<T>::Node *list<T>::Middle(Node *head) {
  Node *slow = head;
  // Node *fast = head->next_;
  // while (fast != end_ && fast->next_ != end_) {
  //   slow = slow->next_;
  //   fast = (fast->next_)->next_;
  // }
  return slow;
}

template <class T>
typename list<T>::Node *list<T>::MergeSort(Node *head) {
  // if (size() > 1) {
  //   Node *mid = Middle(head);
  //   Node *second = mid->next_;
  //   mid->next_ = end_;
  //   Node *a = MergeSort(head);
  //   Node *b = MergeSort(second);
  //   head = MergeSorted(a, b);
  // }
  return head;
}

template <class T>
typename list<T>::Node *list<T>::MergeSorted(Node *a, Node *b) {
  Node *first = a, *second = b;
  // if (a->value_ > b->value_) std::swap(first, second);
  // Node *curr = first;
  // while (curr != end_)
  //   if (second < curr || curr == end_) {
  //     Connect(curr, second);
  //     second = second->next_;
  //     curr = curr->next_;
  //   }
  return first;
}

template <class T>
void list<T>::Connect(Node *first, Node *second) {
  first->next_ = second;
  second->prior_ = first;
}

}  // namespace s21