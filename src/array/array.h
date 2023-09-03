#ifndef CPP2_S21_ARRAY_ARRAY_H_
#define CPP2_S21_ARRAY_ARRAY_H_

namespace s21 {

template <class T, std::size_t N>
struct array {
  T data[N];

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  reference at(size_type pos) {
    if (pos >= N) throw std::out_of_range("out of range");
    return data[pos];
  }
  reference operator[](size_type pos) { return data[pos]; }
  const_reference operator[](size_type pos) const { return data[pos]; }

  reference front() { return data[0]; }
  const_reference front() const { return data[0]; }

  reference back() { return data[N - 1]; }
  const_reference back() const { return data[N - 1]; }

  iterator data() noexcept { return data; }
  const_iterator data() const noexcept { return data; }

  iterator begin() noexcept { return data; }
  const_iterator begin() const noexcept { return data; }

  iterator end() { return data + N; }
  const_iterator end() { return data + N; }

  bool empty() const noexcept { return N == 0; }
  size_type size() const noexcept { return N; }
  size_type max_size() const noexcept { ; }

  void swap(array &other) noexcept { std::swap(data, other.data); }
  void fill(const_reference value) { std::fill(data, data + N - 1, value); }
}

}  // namespace s21

#endif  // CPP2_S21_ARRAY_ARRAY_H_