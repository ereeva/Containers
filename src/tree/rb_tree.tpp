namespace s21 {

template <class key_type> RBTree<key_type>::RBTree() : root_(new Node()), end_(root_) {};

template <class key_type>
typename RBTree<key_type>::Node *RBTree<key_type>::Insert(const_reference data_) {
  if(root_ == end_) root_ = nullptr;
  Node *pt = new Node(data_);
  root_ = Search(root_, pt);
   Balance(root_, pt);
  return root_;
};

template <class key_type>
typename RBTree<key_type>::Node *RBTree<key_type>::Search(Node *root_, Node *pt) const {
  if (root_ == nullptr)
    return pt;
  if (pt->data_ < root_->data_) {
    root_->left_ = Search(root_->left_, pt);
    root_->left_->parent_ = root_;
  } else if (pt->data_ > root_->data_) {
    root_->right_ = Search(root_->right_, pt);
    root_->right_->parent_ = root_;
  }
  return root_;
}
template <class key_type>
bool RBTree<key_type>::Node::contains(Node *node, const key_type key){
  if(root_ == nullptr) return false;
  bool cont = false;
  if (root_ -> data_ == key ) return true;
  else if(root_->data_ < key && root_->right_ != nullptr){
    cont |= root_->left_->contains(root_->left_,key);
  } else if (root_->data_ > key && root_->right_ != nullptr){
    cont |= root_->right_->contains(root_->left_key);
  } 
  return cont;
}

template <class key_type>
typename RBTree<key_type>::Node *RBTree<key_type>::Remove(){
  
};

template <class key_type>
void RBTree<key_type>::clear(){
  root_->Clear();
  if(root_ != end_) delete root_; 
  root_ = end_; 
}

template <class key_type>
void RBTree<key_type>::RotateLeft(Node *&root_, Node *&pt) {
  Node *pt_right_ = pt->right_;
  pt->right_ = pt_right_->left_;
  if (pt->right_ != nullptr)
    pt->right_->parent_ = pt;
  pt_right_->parent_ = pt->parent_;
  if (pt->parent_ == nullptr)
    root_ = pt_right_;
  else if (pt == pt->parent_->left_)
    pt->parent_->left_ = pt_right_;
  else
    pt->parent_->right_ = pt_right_;
  pt_right_->left_ = pt;
  pt->parent_ = pt_right_;
}

template <class key_type>
void RBTree<key_type>::RotateRight(Node *&root_, Node *&pt) {
  Node *pt_left_ = pt->left_;
  pt->left_ = pt_left_->right_;
  if (pt->left_ != nullptr)
    pt->left_->parent_ = pt;
  pt_left_->parent_ = pt->parent_;
  if (pt->parent_ == nullptr)
    root_ = pt_left_;
  else if (pt == pt->parent_->left_)
    pt->parent_->left_ = pt_left_;
  else
    pt->parent_->right_ = pt_left_;
  pt_left_->right_ = pt;
  pt->parent_ = pt_left_;
}

template <class key_type>
void RBTree<key_type>::Balance(Node *&root_, Node *&pt) {
  Node *parent_pt = nullptr;
  Node *grand_parent_pt = nullptr;
  while ((pt != root_) && (pt->color != BLACK) && (pt->parent_->color == RED)) {
    parent_pt = pt->parent_;
    grand_parent_pt = pt->parent_->parent_;
    if (parent_pt == grand_parent_pt->left_) {
      Node *uncle_pt = grand_parent_pt->right_;
      if (uncle_pt != nullptr && uncle_pt->color == RED) {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->right_) {
          RotateLeft(root_, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent_;
        }
        RotateRight(root_, grand_parent_pt);
        std::swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
    else {
      Node *uncle_pt = grand_parent_pt->left_;
      if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->left_) {
          RotateRight(root_, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent_;
        }
        RotateLeft(root_, grand_parent_pt);
        std::swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
  }
  root_->color = BLACK;
}

template <class key_type>
RBTree<key_type>::BTreeIterator::BTreeIterator(Node *node) : ptr(node) {}

template <class key_type>
RBTree<key_type>::BTreeIterator::BTreeIterator(Node *node, Node *end) : ptr(node), end_(end) {}


template <class key_type>
typename RBTree<key_type>::Node *RBTree<key_type>::BTreeIterator::FindMin(Node *ptr) {
  Node *node = ptr;
  while (node->left_ != nullptr)
    node = node->left_;
  return node;
}

template <class key_type>
typename RBTree<key_type>::Node *RBTree<key_type>::BTreeIterator::FindMax(Node *ptr) {
  Node *node = ptr;
  while (node->right_ != nullptr)
    node = node->right_;
  return node;
}

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::begin() {
  return iterator(FindMin(ptr), end_);
}

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::end() {
  return iterator(end_, end_);
}

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::next() {
  if (ptr->right_ != nullptr)
    ptr = FindMin(ptr->right_);
  else {
    while (ptr->parent_ != nullptr && ptr == ptr->parent_->right_)
      ptr = ptr->parent_;
    ptr = ptr->parent_;
  }
  return *this;
};

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::prev() {
  if (ptr->left_ != nullptr)
    ptr = FindMax(ptr->left_);
  else {
    while (ptr->parent_ != nullptr && ptr == ptr->parent_->left_)
      ptr = ptr->parent_;
    ptr = ptr->parent_;
  }
  return *this;
};

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator++() {
  return next();
};

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator--() {
  return prev();
};

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator++(int) {
  iterator tmp(ptr, end_);
  next();
  return tmp;
};

template <class key_type>
typename RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator--(int) {
  iterator tmp(ptr, end_);
  prev();
  return tmp;
};
template <class key_type>
bool RBTree<key_type>::BTreeIterator::operator==(const iterator rhs) const {
  return ptr == rhs.ptr;
};
template <class key_type>
bool RBTree<key_type>::BTreeIterator::operator<(const iterator rhs) const {
  return ptr->data_ < rhs.ptr->data_;
};

template <class key_type>
typename RBTree<key_type>::reference RBTree<key_type>::BTreeIterator::operator*() {
  return ptr->data_;
};
template <class key_type>
typename RBTree<key_type>::const_reference
RBTree<key_type>::BTreeIterator::operator*() const {
  return ptr->data_;
};
}; // namespace s21