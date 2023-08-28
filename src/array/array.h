#ifndef CPP2_S21_ARRAY_ARRAY_H_
#define CPP2_S21_ARRAY_ARRAY_H_

namespace s21{

	template<class T>
	struct array{
		using value_type = T;
		using reference = T &;
		using const_reference = const T &;
		using iterator = T *;
		using const_iterator = const T *;
		using size_type = size_t;
	}

} // namespace s21

#endif // CPP2_S21_ARRAY_ARRAY_H_