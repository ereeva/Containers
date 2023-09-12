namespace s21 {

template <class key_type> RBTree<key_type>::RBTree() : root(){};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Insert(key_type &x) {
  Node *pt = new Node(data);
  root = Search(root, pt);
  Balance(root, pt);
};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Search(Node *root, Node *pt) const {
  if (root == nullptr)
    return pt;
  if (pt->data < root->data) {
    root->left_ = BSTInsert(root->left, pt);
    root->left_->parent_ = root;
  } else if (pt->data > root->data) {
    root->right_ = BSTInsert(root->right_, pt);
    root->right_->parent_ = root;
  }
  return root;
}

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Remove(reference x){};

template <class key_type>
void RBTree<key_type>::RotateLeft(Node *&root, Node *&pt) {
  Node *pt_right_ = pt->right_;
  pt->right_ = pt_right_->left_;
  if (pt->right_ != nullptr)
    pt->right_->parent_ = pt;
  pt_right_->parent_ = pt->parent_;
  if (pt->parent_ == nullptr)
    root = pt_right_;
  else if (pt == pt->parent_->left_)
    pt->parent_->left_ = pt_right_;
  else
    pt->parent_->right_ = pt_right_;
  pt_right_->left_ = pt;
  pt->parent_ = pt_right_;
}

template <class key_type>
void RBTree<key_type>::RotateRight(Node *&root, Node *&pt) {
  Node *pt_left_ = pt->left;
  pt->left_ = pt_left->right_;
  if (pt->left_ != nullptr)
    pt->left_->parent_ = pt;
  pt_left_->parent_ = pt->parent_;
  if (pt->parent_ == nullptr)
    root = pt_left_;
  else if (pt == pt->parent_->left_)
    pt->parent_->left_ = pt_left;
  else
    pt->parent_->right_ = pt_left_;
  pt_left_->right_ = pt;
  pt->parent_ = pt_left_;
}

template <class key_type>
void RBTree<key_type>::Balance(Node *&root, Node *&pt) {
  Node *parent_pt = nullptr;
  Node *grand_parent_pt = nullptr;
  while ((pt != root) && (pt->color != BLACK) && (pt->parent_->color == RED)) {
    parent_pt = pt->parent_;
    grand_parent_pt = pt->parent_->parent_;
    //  Case : A
    if (parent_pt == grand_parent_pt->left_) {
      Node *uncle_pt = grand_parent_pt->right_;
      // Case : 1
      if (uncle_pt != nullptr && uncle_pt->color == RED) {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        // Case : 2
        if (pt == parent_pt->right_) {
          Rotateleft_(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent_;
        }
        // Case : 3
        Rotateright_(root, grand_parent_pt);
        std::swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
    // Case : B
    else {
      Node *uncle_pt = grand_parent_pt->left_;
      // Case : 1
      if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        // Case : 2
        if (pt == parent_pt->left_) {
          Rotateright_(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent_;
        }
        // Case : 3
        Rotateleft_(root, grand_parent_pt);
        std::swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
  }
  root->color = BLACK;
}

template <class key_type>
RBTree<key_type>::BTreeIterator::BTreeIterator(Node *node) : ptr(node) {}

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::BTreeIterator::FindMin(Node *ptr) {
  Node *node = ptr;
  while (node->left_ != nullptr)
    node = node->left_;
  return node;
}

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::BTreeIterator::FindMax(Node *ptr) {
  Node *node = ptr;
  while (node->right_ != nullptr)
    node = node->right_;
  return node;
}

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::begin() {
  return iterator tmp(FindMin(root_));
}

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::end() {
  return iterator tmp(nullptr);
}

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::next() {
  Node *node = ptr_;
  if (node->right_ != nullptr)
    node = FindMin(node->right_);
  else {
    while (node->parent_ != nullptr && node == node->parent_->right_)
      node = node->parent_;
    node = node->parent_;
  }
  return iterator tmp(node);
};

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::next() {
  Node *node = ptr_;
  if (node->left_ != nullptr)
    node = FindMax(node->left_);
  else {
    while (node->parent_ != nullptr && node == node->parent_->left_)
      node = node->parent_;
    node = node->parent_;
  }
  return iterator tmp(node);
};

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator++() {
  return next();
};

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator--() {
  return prev();
};

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator++(int) {
  iterator tmp = iterator(ptr);
  next();
  return tmp;
};

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::operator--(int) {
  iterator tmp = iterator(ptr);
  prev();
  return tmp;
};
template <class key_type>
RBTree<key_type>::bool RBTree<key_type>::BTreeIterator:: operator==(const iterator rhs) const{
  return ptr == rhs.ptr; 
};
template <class key_type>
RBTree<key_type>::bool RBTree<key_type>::BTreeIterator::operator<(const iterator rhs)const{
  return ptr->data_ < rhs.ptr->data_; 
};

template <class key_type>
RBTree<key_type>::reference RBTree<key_type>::BTreeIterator::operator*(){
  return *ptr;
};
template <class key_type>
RBTree<key_type>::const_reference RBTree<key_type>::BTreeIterator::operator*() const{
  return *ptr;
};
}; // namespace s21