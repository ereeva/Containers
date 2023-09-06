#ifndef CPP2_S21_VECTOR_VECTOR_H_
#define CPP2_S21_VECTOR_VECTOR_H_

#include <cstddef>
#include <cstring>
#include <limits>
#include <memory>
#include <new>
#include <utility>

namespace s21 {
template <class T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector() = default;
  vector(size_type n) : data_(n) {
    std::uninitialized_value_construct_n(data_.buf_, n);
    size_ = n;
  }
  vector(std::initializer_list<value_type> const &items) : data_(items.size()) {
    for (auto item : items) {
      new (data_ + size_) T(item);
      ++size_;
    }
  }
  vector(const vector &other) : data_(other.size_) {
    std::uninitialized_copy_n(other.data_.buf_, other.size_, data_.buf_);
    size_ = other.size_;
  }
  vector(vector &&other) noexcept { swap(other); }
  ~vector() { std::destroy_n(data_.buf_, size_); }

  vector &operator=(vector &&other) noexcept {
    swap(other);
    return *this;
  }
  vector &operator=(const vector &other) {
    if (other.size_ > data_.cp_) {
      vector tmp(other);
      swap(tmp);
    } else {
      for (size_t i = 0; i < size_ && i < other.size_; ++i) data_[i] = other[i];
      if (size_ < other.size_) {
        std::uninitialized_copy_n(other.data_.buf_ + size_, other.size_ - size_,
                                  data_.buf_ + size_);
      } else if (size_ > other.size_) {
        std::destroy_n(data_.buf_ + other.size_, size_ - other.size_);
      }
      size_ = other.size_;
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_) throw std::out_of_range("out of range");
    return data_[pos];
  }
  const_reference at(size_type pos) const {
    if (pos >= size_) throw std::out_of_range("out of range");
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }
  const_reference operator[](size_type pos) const { return data_[pos]; }

  reference front() { return data_[0]; }
  const_reference front() const { return data_[0]; }

  reference back() { return data_[size_ - 1]; }
  const_reference back() const { return data_[size_ - 1]; }

  T *data() { return front(); }
  const T *data() const { return front(); }

  iterator begin() { return &data_[0]; }
  iterator end() { return &data_[size_]; }

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() {
    return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
  }
  void reserve(size_t n) {
    if (n > data_.cp_) {
      RawMemory<T> data2(n);
      std::uninitialized_move_n(data_.buf_, size_, data2.buf_);
      std::destroy_n(data_.buf_, size_);
      data_.Swap(data2);
    }
  }
  size_type capacity() { return data_.cp_; }
  void shrink_to_fit() {
    RawMemory<T> data2(size_);
    std::uninitialized_move_n(data_.buf_, size_, data2.buf_);
    std::destroy_n(data_.buf_, size_);
    data_.swap(data2);
  }

  void swap(vector &other) noexcept {
    data_.Swap(other.data_);
    std::swap(size_, other.size_);
  }

  void clear() {
    std::destroy_n(begin(), end());
    size_ = 0;
  }
  iterator insert(iterator pos, const_reference value) {
    if (size_ == data_.cp_) reserve(size_ == 0 ? 1 : size_ * 2);
    new (data_ + size_) T;
    ++size_;
    std::memmove(pos + 1, pos, end() - pos);
    *pos = T(value);
    return pos;
  }
  void erase(iterator pos) {
    std::destroy_at(pos);
    --size_;
  }
  void push_back(const T &elem) {
    if (size_ == data_.cp_) reserve(size_ == 0 ? 1 : size_ * 2);
    new (data_ + size_) T(elem);
    ++size_;
  }
  void pop_back() {
    std::destroy_at(data_ + size_ - 1);
    --size_;
  }

  void resize(size_t n) {
    reserve(n);
    if (size_ < n)
      std::uninitialized_value_construct_n(data_ + size_, n - size_);
    else if (size_ > n)
      std::destroy_n(data_ + n, size_ - n);
    size_ = n;
  }

 private:
  template <class value_type>
  struct RawMemory {
    T *buf_ = nullptr;
    size_t cp_ = 0;

    RawMemory() = default;
    RawMemory(size_t n) {
      buf_ = Allocate(n);
      cp_ = n;
    }
    RawMemory(const RawMemory &) = delete;
    RawMemory(RawMemory &&other) noexcept { Swap(other); }
    ~RawMemory() { Deallocate(buf_); }

    RawMemory &operator=(const RawMemory &) = delete;
    RawMemory &operator=(RawMemory &&other) noexcept {
      Swap(other);
      return *this;
    }

    value_type *operator+(size_t i) { return buf_ + i; }
    const value_type *operator+(size_t i) const { return buf_ + i; }

    value_type &operator[](size_t i) { return buf_[i]; }
    const value_type &operator[](size_t i) const { return buf_[i]; }

    static value_type *Allocate(size_t n) {
      return static_cast<value_type *>(operator new(n * sizeof(value_type)));
    }
    static void Deallocate(value_type *buf) { operator delete(buf); }

    void Swap(RawMemory &other) noexcept {
      std::swap(buf_, other.buf_);
      std::swap(cp_, other.cp_);
    }
  };

  RawMemory<T> data_;
  size_t size_ = 0;
};

}  // namespace s21

#endif  // CPP2_S21_VECTOR_VECTOR_H_