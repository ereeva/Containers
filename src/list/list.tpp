namespace s21 {

template <class T>
list<T>::list() : size_(0), end_(new Node()) {
  end_->Connect(end_);
}

template <class T>
list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) push_back(value_type());
}

template <class T>
list<T>::list(std::initializer_list<T> const &items) : list() {
  for (auto &item : items) push_back(item);
}

template <class T>
list<T>::list(const list &l) : list() {
  for (auto node : l) push_back(node.ptr_->value_);
}

template <class T>
list<T>::list(list &&l) : list() {
  splice(begin(), l);
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
    end_ = l.end_;
    l.size_ = 0;
    l.end_ = nullptr;
  }
}

template <class T>
typename list<T>::const_reference list<T>::front() const {
  return end_->next_->value_;
}

template <class T>
typename list<T>::const_reference list<T>::back() const {
  return end_->prior_->value_;
}

template <class T>
typename list<T>::iterator list<T>::begin() const {
  return iterator(end_->next_);
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
  while (!empty()) pop_back();
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node *n = new Node(value);
  pos.ptr_->prior_->Connect(n);
  n->Connect(pos.ptr_);
  ++size_;
  return iterator(n);
}

template <class T>
void list<T>::erase(iterator pos) {
  pos.ptr_->prior_->Connect(pos.ptr_->next_);
  delete pos.ptr_;
  --size_;
}

template <class T>
void list<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <class T>
void list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <class T>
void list<T>::pop_back() {
  erase(iterator(end_->prior_));
}

template <class T>
void list<T>::pop_front() {
  erase(begin());
}

template <class T>
void list<T>::swap(list &other) {
  std::swap(end_, other.end_);
  std::swap(size_, other.size_);
}

template <class T>
void list<T>::merge(list &other) {
  other.end_->prior_->next_ = end_;
  Merge(end_->next_, other.end_->next_);
  size_ += other.size_;
  other.end_->Connect(other.end_);
  other.size_ = 0;
}

template <class T>
void list<T>::splice(const iterator pos, list &other) {
  if (!other.empty()) {
    pos.ptr_->prior_->Connect(other.end_->next_);
    other.end_->prior_->Connect(pos.ptr_);
    size_ += other.size_;
    other.end_->Connect(other.end_);
    other.size_ = 0;
  }
}

template <class T>
void list<T>::reverse() {
  iterator h = begin();
  iterator t = iterator(end_->prior_);
  for (size_type i = 0; i < size() / 2; ++i) std::swap(*h++, *t--);
}

template <class T>
void list<T>::unique() {
  if (!empty())
    for (auto i = begin(); i != end(); ++i)
      if (i.ptr_->value_ == i.ptr_->prior_->value_) erase(i--);
}

template <class T>
void list<T>::sort() {
  MergeSort(end_->next_);
}

template <class T>
typename list<T>::Node *list<T>::Middle(Node *head) {
  Node *slow = head;
  Node *fast = head->next_;
  while (fast != end_ && fast->next_ != end_) {
    slow = slow->next_;
    fast = fast->next_->next_;
  }
  return slow;
}

template <class T>
typename list<T>::Node *list<T>::MergeSort(Node *head) {
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

template <class T>
typename list<T>::Node *list<T>::Merge(Node *a, Node *b) {
  Node *head;
  if (a == end_)
    head = b;
  else if (b == end_)
    head = a;
  else if (a->value_ < b->value_) {
    a->next_ = Merge(a->next_, b);
    head = a;
  } else {
    b->next_ = Merge(a, b->next_);
    head = b;
  }
  end_->Connect(head);
  for (auto i = head; i != end_; i = i->next_) i->next_->prior_ = i;
  return head;
}

template <class T>
// template <class... Args>
typename list<T>::iterator insert_many(const_iterator pos, Args &&...args) {
  for (auto &arg : {args...}) insert(pos, arg);
  return pos;
}

template <class T>
// template <class... Args>
void insert_many_back(Args &&...args) {
  for (auto &arg : {args...}) push_back(arg);
}

template <class T>
// template <class... Args>
void insert_many_front(Args &&...args) {
  for (auto &arg : {args...}) push_front(arg);
}

}  // namespace s21