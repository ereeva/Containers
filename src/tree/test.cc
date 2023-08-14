#include <iostream>
#include <queue>

enum Color { RED, BLACK };

struct Node {
  int data;
  bool color;
  Node *left, *right, *parent;

  Node() : data(), left(nullptr), right(nullptr), parent(nullptr), color(RED){};
  Node(int data) : Node(){this->data = data;};
};

class RBTree {
private:
  Node *root;

protected:
  void RotateLeft(Node *&, Node *&);
  void RotateRight(Node *&, Node *&);
  void Balance(Node *&, Node *&);

public:
  RBTree() { root = nullptr; }
  void Insert(const int &n);
  void Inorder();
  void LevelOrder();
};

void PrintTree(Node *root) {
  if (root == nullptr)
    return;
  PrintTree(root->left);
  std::cout << root->data << "  ";
  PrintTree(root->right);
}

Node *BSTInsert(Node *root, Node *pt) {
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

void LevelOrderHelper(Node *root) {
  if (root == nullptr)
    return;
  std::queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *temp = q.front();
    std::cout << temp->data << "  ";
    q.pop();
    if (temp->left != nullptr)
      q.push(temp->left);
    if (temp->right != nullptr)
      q.push(temp->right);
  }
}

void RBTree::RotateLeft(Node *&root, Node *&pt) {
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

void RBTree::RotateRight(Node *&root, Node *&pt) {
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

void RBTree::Balance(Node *&root, Node *&pt) {
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

void RBTree::Insert(const int &data) {
  Node *pt = new Node(data);
  root = BSTInsert(root, pt);
  Balance(root, pt);
}

void RBTree::Inorder() { PrintTree(root); }
void RBTree::LevelOrder() { LevelOrderHelper(root); }

int main() {
  RBTree tree;

  tree.Insert(6);
  tree.Insert(5);
  tree.Insert(7);
  tree.Insert(4);
  tree.Insert(3);
  tree.Insert(2);
  tree.Insert(1);

  std::cout << "Inorder Traversal of Created Tree\n";
  tree.Inorder();
  std::cout << "\n\nLevel Order Traversal of Created Tree\n";
  tree.LevelOrder();
  return 0;
}