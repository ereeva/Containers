namespace s21 {

template <class key_type> RBTree<key_type>::RBTree() : root(){};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Insert(key_type &x) {
  Node *pt = new Node(data);
  root = Search(root, pt);
  Balance(root, pt);
};

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Search(Node *root,
                                                 Node *pt) const {
  if (root == nullptr)
    return pt;
  if (pt->data < root->data) {
    root->left = BSTInsert(root->left, pt);
    root->left->parent = root;
  } else if (pt->data > root->data) {
    root->right = BSTInsert(root->right, pt);
    root->right->parent = root;
  }
  return root;
}

template <class key_type>
RBTree<key_type>::Node *RBTree<key_type>::Remove(reference x){};

template <class key_type>
void RBTree<key_type>::RotateLeft(Node *&root, Node *&pt) {
  Node *pt_right = pt->right;
  pt->right = pt_right->left;
  if (pt->right != nullptr)
    pt->right->parent = pt;
  pt_right->parent = pt->parent;
  if (pt->parent == nullptr)
    root = pt_right;
  else if (pt == pt->parent->left)
    pt->parent->left = pt_right;
  else
    pt->parent->right = pt_right;
  pt_right->left = pt;
  pt->parent = pt_right;
}

template <class key_type>
void RBTree<key_type>::RotateRight(Node *&root, Node *&pt) {
  Node *pt_left = pt->left;
  pt->left = pt_left->right;
  if (pt->left != nullptr)
    pt->left->parent = pt;
  pt_left->parent = pt->parent;
  if (pt->parent == nullptr)
    root = pt_left;
  else if (pt == pt->parent->left)
    pt->parent->left = pt_left;
  else
    pt->parent->right = pt_left;
  pt_left->right = pt;
  pt->parent = pt_left;
}

template <class key_type>
void RBTree<key_type>::Balance(Node *&root, Node *&pt) {
  Node *parent_pt = nullptr;
  Node *grand_parent_pt = nullptr;
  while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
    parent_pt = pt->parent;
    grand_parent_pt = pt->parent->parent;
    //  Case : A
    if (parent_pt == grand_parent_pt->left) {
      Node *uncle_pt = grand_parent_pt->right;
      // Case : 1
      if (uncle_pt != nullptr && uncle_pt->color == RED) {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      }
      else {
        // Case : 2
        if (pt == parent_pt->right) {
          RotateLeft(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        // Case : 3
        RotateRight(root, grand_parent_pt);
        std::swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
    // Case : B
    else {
      Node *uncle_pt = grand_parent_pt->left;
      // Case : 1
      if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        // Case : 2
        if (pt == parent_pt->left) {
          RotateRight(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        // Case : 3
        RotateLeft(root, grand_parent_pt);
        std::swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
  }
  root->color = BLACK;
}

template <class key_type>
RBTree<key_type>::BTreeIterator::BTreeIterator (Node* node) : ptr(node){}

template <class key_type>
RBTree<key_type>::Node* RBTree<key_type>::BTreeIterator::FindMin(Node* ptr){
  Node* node = ptr;
  while (node->left_ != nullptr)
    node = node->left_;
  return node;
}

template <class key_type>
RBTree<key_type>::Node* RBTree<key_type>::BTreeIterator::FindMax(Node* ptr){
  Node* node = ptr;
  while (node->right_ != nullptr)
    node = node->right_;
  return node;
}

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::begin(){
  return  iterator tmp(FindMin(root_));
}

template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::end(){
  return iterator tmp(nullptr);
}


template <class key_type>
RBTree<key_type>::iterator RBTree<key_type>::BTreeIterator::next(){
  Node* node = ptr_;
  if(node->right_ != nullptr)
    node = FindMin(node->right_);
  else {
    while (node->parent_ != nullptr && node == node->parent_->right)
      node = node->parent_;
    node = node->parent_;
  }
  return iterator tmp(node);
};
}; // namespace s21