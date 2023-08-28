#ifndef CPP2_S21_VECTOR_VECTOR_H_
#define CPP2_S21_VECTOR_VECTOR_H_

namespace s21 {
template <class T>
class vector {
 public:
  class VectorIterator;
  class ConstVectorIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = VectorIterator;
  using const_iterator = ConstVectorIterator;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();

  vector &operator=(const vector &v);
  vector &operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  iterator begin();
  iterator end();

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size();
  void reserve(size_type size);
  size_type capacity() { return capacity_; }
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

 private:
  size_type size_;
  size_type capacity_;
}

}  // namespace s21

#endif  // CPP2_S21_VECTOR_VECTOR_H_