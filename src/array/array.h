#ifndef CPP2_S21_ARRAY_ARRAY_H_
#define CPP2_S21_ARRAY_ARRAY_H_

#include <stdexcept>

namespace s21 {

template <class T, std::size_t N>
struct array {
  T arr[N];

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  reference at(size_type pos) {
    if (pos >= N) throw std::out_of_range("out of range");
    return arr[pos];
  }
  reference operator[](size_type pos) { return arr[pos]; }
  const_reference operator[](size_type pos) const { return arr[pos]; }

  reference front() { return arr[0]; }
  const_reference front() const { return arr[0]; }

  reference back() { return arr[N - 1]; }
  const_reference back() const { return arr[N - 1]; }

  iterator data() noexcept { return arr; }
  const_iterator data() const noexcept { return arr; }

  iterator begin() noexcept { return arr; }
  const_iterator begin() const noexcept { return arr; }

  iterator end() { return arr + N; }
  const_iterator end() const { return arr + N; }

  bool empty() const noexcept { return N == 0; }
  size_type size() const noexcept { return N; }
  size_type max_size() const noexcept { return N; }

  void swap(array &other) noexcept { std::swap(arr, other.arr); }
  void fill(const_reference value) { std::fill(arr, arr + N - 1, value); }
};

}  // namespace s21

#endif  // CPP2_S21_ARRAY_ARRAY_H_