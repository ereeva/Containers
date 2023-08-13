namespace s21 {

template <class T>
list<T>::list() : size_(0), head_(nullptr), tail_(nullptr), end(nullptr) {}

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
list<T>::iterator begin() {
  return iterator(head_);
}

template <class T>
list<T>::iterator end() {
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
  //////
}

template <class T>
list<T>::iterator insert(iteraror pos, const_reference value) {
  //////
}

template <class T>
list<T>::void erase(iterator pos) {
  
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
}

template <class T>
list<T>::void pop_back() {
  if(){

	}
	else{

	}
	--size_;
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
}

template <class T>
list<T>::void pop_front() {
  //////
}

template <class T>
list<T>::void swap(list &other) {
  //////
}

template <class T>
list<T>::void merge(list &other) {
  //////
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

}  // namespace s21