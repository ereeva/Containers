enum Color { RED, BLACK };

template <class T> struct Node {
  T data_;
  Node *left_, *right_, *parent_;
  Node();
  Node(key_type data, Node *p = nullptr, Color c = RED, Node *r = nullptr,
       Node *l = nullptr)
      : data_(data), parent_(p), left_(l), right_(r){};
};

template <class T> class RBTree : public Node<T>{
public:

  using key_type = T;
  using value_type = key_type;
  using reference = T &;
  using const_reference = const T &;

  RBTree() : root_(nullptr){};

  Node<key_type> *Insert(T &x){return root_;};
  Node<key_type> *Search(T &x, Node<key_type> *first) const{return root_;};
  Node<key_type> *Remove(T &x) { return root_;};
protected:
  void Balance(Node<key_type> *&root, Node<key_type> *&pt){};
private:
  Node<key_type> *root_;
};

template<class key_type>
class BTreeIterator : private RBTree<key_type>{
    BTreeIterator() : ptr(root_){};
  iterator operator++(){return this;};
  iterator operator--(){return this;};
  bool operator==(){return true;};
  bool operator<(){return false;};
  Node &operator*(){return *ptr;};

private:
  Node *ptr;
};

int main(){
    RBTree<int> tree;
    return 0;
}
