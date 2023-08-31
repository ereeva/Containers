#ifndef CPP2_S21_VECTOR_VECTOR_H_
#define CPP2_S21_VECTOR_VECTOR_H_

#include <cstddef>
#include <memory>
#include <new>
#include <utility>

namespace s21 {
template <class T>
class vector {
 public:
  vector() = default;

  vector(size_t) : data_(n) {
    std::uninitialized_value_construct_n(data_.buf_, n);
    size_ = n;
  }

  vector(const vector &other) : data_(other.size_) {
    std::uninitialized_copy_n(other.data_.buf_, other.size_, data_.buf_);
    size_ = other.size_;
  }

  vector(vector &&other) noexcept{
    swap(other);
  }

  ~vector() { std::destroy_n(data_.buf_, size_); }

  vector &operator=(vector &&other) noexcept{
    swap(other);
    return *this;
  }

  vector &operator=(const vector &other){
    if(other.size_ > data_.cp_){
      vector tmp(other);
      swap(tmp);
    }
    else{
      for(size_t i = 0; i < size_ && i < other.size_; ++i)
        data_[i] = other[i];
      if(size_ < other.size_){
        std::uninitialized_copy_n(other.data_.buf_ + size_, other.size_ - size_, data_.buf_ + size_);
      }
      else if(size_ > other.size_){
        std::destroy_n(data_.buf_ + other.size_, size_ - other.size_);
      }
      size_ = other.size_;
    }
    return *this;
  }

  void swap(vector &other) noexcept{
    data_.Swap(other.data_);
    std::swap(size_, other.size_);
  }

  void reserve(size_t n) {
    if (n > data_.cp_) {
      RawMemory<T> data2(n);
      std::uninitialized_move_n(data_.buf_, size_, data2.buf_);
      std::destroy_n(data_.buf_, size_);
      data.swap(data2);
    }
  }

  void resize(size_t n){
    reserve(n);
    if(size_ < n)
      std::uninitialized_value_construct_n(data_ + size_, n - size_);
    else if(size_ > n)
      std::destroy_n(data_ + n, size_ - n);
    size_ = n;
  }

  void push_back(const T &elem){
    if(size_ == data_.cp_)
      reserve(size_ == 0 ? 1 : size_ * 2);
    new (data_ + size_) T(elem);
    ++size_;
  }

  void push_back(T &&elem){
    if(size_ == data_.cp_)
      reserve(size_ == 0 ? 1 : size_ * 2);
    new (data_ + size_) T(std::move(elem));
    ++size_;
  }

  void pop_back(){
    std::destroy_at(data_ + size_ - 1);
    --size_;
  }

 private:
  RawMemory<T> data_;
  size_type size_ = 0;
};

template <class T>
struct RawMemory {
  T *buf_ = nullptr;
  size_t cp_ = 0;

  static T *Allocate(size_t n) {
    return static_cast<T *>(operator new(n * sizeof(T)));
  }

  static void Deallocate(T *buf) { operator delete(buf); }

  void Swap(RawMemory &other) noexcept {
    std::swap(buf_, other.buf_);
    std::swap(cp_, other.cp_);
  }

  RawMemory() = default;

  RawMemory(size_t n) {
    buf_ = Allocate(n);
    cp_ = n;
  }

  RawMemory(const RawMemory&) = delete;

  RawMemory(RawMemory &&other) noexcept{
    Swap(other);
  }

  ~RawMemory() { Deallocate(buf_); }

  RawMemory &operator=(const RawMemory&) = delete;

  RawMemory &operator=(RawMemory &&other) noexcept{
    Swap(other);
    return *this;
  }

  T *operator+(size_t i) { return buf_ + i; }

  const T *operator+(size_t i) const { return buf_ + i; }

  T &operator[](size_t i) { return buf_[i]; }

  const T &operator[](size_t i) const { return buf_[i]; }
};

}  // namespace s21

#endif  // CPP2_S21_VECTOR_VECTOR_H_